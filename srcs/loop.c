#include "../includes/ft_ls.h"
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

t_stat	get_stat(char *path, char *filename);

void	loop(t_rts *rts, char *path) {
	DIR	*dir;
	struct dirent	*cur;
	t_vector		v;
	int				total_block;
	char 			*next_path;
	t_stat			stat_buf;

	if (vector_ctor(&v, sizeof(t_stat)) == NULL) {
		error(2, NULL, "failed to create vector");
	}
	t_arena_cursor	cursor = get_arena_cursor();
	total_block = 0;
	dir = opendir(path);
	if (!dir) {
		if (rts->opt_recursive)
			error(0, path, "cannot open directory");
		else {
			// vector_dtor(&v);
			error(2, path, "cannot open directory");
		}
		return ;
	}
	errno = 0;
	cur = readdir(dir);
	while (cur) {
		// -a 옵션 없을 시 숨김파일 skip
		if (!rts->opt_all && !ft_strncmp(cur->d_name, ".", 1)) {
			cur = readdir(dir);
			continue ;
		}
		next_path = join_path(path, cur->d_name);
		if (!next_path) {
			error(2, NULL, "failed malloc");
		}
		stat_buf = get_stat(next_path, cur->d_name);
		push_back(&v, &stat_buf);
		total_block += stat_buf.blocks / 2;
		free(next_path);
		errno = 0;
		cur = readdir(dir);
	}
	if (errno != 0) {
		// vector_dtor(&v);
		error(2, path, "cannot read directory");
	}
	if (closedir(dir)) {
		// vector_dtor(&v);
		error(2, path, "cannot close directory");
	}

	sort_files(rts, &v);
	print_outputs(rts, path, total_block, &v);

	if (rts->opt_recursive) {
		for (int i = 0; i < v.size; i++) {
			t_stat	c;

			c = ((t_stat *)v.arr)[i];
			if (c.acl[0] != 'd' \
				|| !ft_strncmp(c.filename, ".", 2) \
				|| !ft_strncmp(c.filename, "..", 3))
				continue ;
			ft_printf("\n");
			next_path = join_path(path, c.filename);
			if (!next_path) {
				error(2, NULL, "failed malloc");
			}
			loop(rts, next_path);
			free(next_path);
		}
	}
	arena_rewind(cursor);
	// vector_dtor(&v);
}

t_stat	get_stat(char *path, char *filename) {
	t_stat			new_stat;
	struct passwd	*pw;
	struct group	*gr;
	struct stat		stat_buf;

	ft_memset(&stat_buf, 0, sizeof(stat_buf));
	ft_memset(&new_stat, 0, sizeof(new_stat));
	if (lstat(path, &stat_buf) < 0) {
		error(0, path, "failed lstat");
		ft_memset(new_stat.acl + 1, '?', sizeof(new_stat.acl) - 1);
		return new_stat;
	}

	for (int i = 0; i < 10; i++) {
		new_stat.acl[i] = '-';
	}

	switch (stat_buf.st_mode & S_IFMT) {
		case S_IFDIR: new_stat.acl[0] = 'd'; break ;
		case S_IFLNK: new_stat.acl[0] = 'l'; break ;
		case S_IFSOCK: new_stat.acl[0] = 's'; break ;
		case S_IFBLK: new_stat.acl[0] = 'b'; break ;
		case S_IFCHR: new_stat.acl[0] = 'c'; break ;
		case S_IFIFO: new_stat.acl[0] = 'p'; break ;
	}

	if (stat_buf.st_mode & S_IRUSR)
		new_stat.acl[1] = 'r';
	if (stat_buf.st_mode & S_IWUSR)
		new_stat.acl[2] = 'w';
	if (stat_buf.st_mode & S_IXUSR)
		new_stat.acl[3] = 'x';
	if (stat_buf.st_mode & S_IRGRP)
		new_stat.acl[4] = 'r';
	if (stat_buf.st_mode & S_IWGRP)
		new_stat.acl[5] = 'w';
	if (stat_buf.st_mode & S_IXGRP)
		new_stat.acl[6] = 'x';
	if (stat_buf.st_mode & S_IROTH)
		new_stat.acl[7] = 'r';
	if (stat_buf.st_mode & S_IWOTH)
		new_stat.acl[8] = 'w';
	if (stat_buf.st_mode & S_IXOTH)
		new_stat.acl[9] = 'x';

	new_stat.nlink = stat_buf.st_nlink;

	pw = getpwuid(stat_buf.st_uid);
	if (pw)
		new_stat.uid = pw->pw_name;
	else
		new_stat.uid = ft_itoa(stat_buf.st_uid);

	gr = getgrgid(stat_buf.st_gid);
	if (gr)
		new_stat.gid = gr->gr_name;
	else
		new_stat.gid = ft_itoa(stat_buf.st_gid);

	new_stat.file_size = stat_buf.st_size;
	new_stat.time_epoch = stat_buf.st_mtim;
	ft_memcpy(new_stat.time_str, ctime(&stat_buf.st_mtim.tv_sec) + 4, 12);
	ft_memcpy(new_stat.filename, filename, ft_strlen(filename) + 1);

	if (new_stat.acl[0] == 'l') {
		int	c;

		c = readlink(path, new_stat.linked_filename, sizeof(new_stat.linked_filename));
		if (c < 0) {
			error(0, path, "failed readlink");
		}
	}

	new_stat.blocks = stat_buf.st_blocks;
	return new_stat;
}
