#include "../includes/ft_ls.h"
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

t_stat	get_stat(char *filename, struct stat *statbuf);

void	loop(t_rts *rts, char *path) {
	DIR	*dir;
	struct dirent	*cur;
	t_vector		v;
	int				total_block;
	char 			*next_path;

	vector_init(&v, sizeof(t_stat));
	total_block = 0;
	dir = opendir(path);
	cur = readdir(dir);
	while (cur) {
		struct stat	statbuf;
	
		if (!ft_strncmp(cur->d_name, ".", 1)) {
			cur = readdir(dir);
			continue ;
		}
		next_path = join_path(path, cur->d_name);
		if (stat(next_path, &statbuf) < 0) {
			perror(next_path);
		}

		t_stat	stat = get_stat(cur->d_name, &statbuf);
		// t_stat 구조체 생성
		push_back(&v, &stat);
		total_block += statbuf.st_blocks / 2;
		free(next_path);
		cur = readdir(dir);
	}

	// TODO: sorting && printing
	sort(rts, &v);
	print_outputs(rts, path, total_block, &v);

	if (rts->opt_recursive) {
		for (int i = 0; i < v.size; i++) {
			t_stat	c;

			c = ((t_stat *)v.arr)[i];
			if (c.acl[0] != 'd') continue ;
			next_path = join_path(path, c.filename);
			loop(rts, next_path);
			free(next_path);
			ft_printf("\n");
		}
	}
}

t_stat	get_stat(char *filename, struct stat *statbuf) {
	t_stat	new_stat;
	struct passwd	pw;

	ft_memset(&new_stat, 0, sizeof(new_stat));
	for (int i = 0; i < 10; i++) {
		new_stat.acl[i] = '-';
	}

	switch (statbuf->st_mode & S_IFMT) {
		case S_IFDIR: new_stat.acl[0] = 'd'; break ;
		case S_IFLNK: new_stat.acl[0] = 'l'; break ;
		case S_IFSOCK: new_stat.acl[0] = 's'; break ;
		case S_IFBLK: new_stat.acl[0] = 'b'; break ;
		case S_IFCHR: new_stat.acl[0] = 'c'; break ;
		case S_IFIFO: new_stat.acl[0] = 'p'; break ;
	}

	if (statbuf->st_mode & S_IRUSR)
		new_stat.acl[1] = 'r';
	if (statbuf->st_mode & S_IWUSR)
		new_stat.acl[2] = 'w';
	if (statbuf->st_mode & S_IXUSR)
		new_stat.acl[3] = 'x';
	if (statbuf->st_mode & S_IRGRP)
		new_stat.acl[4] = 'r';
	if (statbuf->st_mode & S_IWGRP)
		new_stat.acl[5] = 'w';
	if (statbuf->st_mode & S_IXGRP)
		new_stat.acl[6] = 'x';
	if (statbuf->st_mode & S_IROTH)
		new_stat.acl[7] = 'r';
	if (statbuf->st_mode & S_IWOTH)
		new_stat.acl[8] = 'w';
	if (statbuf->st_mode & S_IXOTH)
		new_stat.acl[9] = 'x';
	new_stat.nlink = statbuf->st_nlink;
	new_stat.uid = getpwuid(statbuf->st_uid)->pw_name;
	new_stat.gid = getgrgid(statbuf->st_gid)->gr_name;
	new_stat.file_size = statbuf->st_size;
	new_stat.time = statbuf->st_mtim;
	ft_memcpy(new_stat.filename, filename, ft_strlen(filename) + 1);

	return new_stat;
}
