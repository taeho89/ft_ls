#include "../includes/ft_ls.h"
#include <pwd.h>
#include <grp.h>

static char	first = 1;

t_print_util	get_print_util_info(t_vector *v)
	ATTRIBUTE_NONNULL((1));

void	print_outputs(t_rts *rts, char *cur_path, int total_block, t_vector *v) {
	t_stat			st;
	t_print_util	pu;
	struct passwd	*pw;
	struct group	*gr;

	if (rts->opt_recursive) {
		if (first) {
			ft_printf("%s:\n", cur_path);
			first = 0;
		}
		else
			ft_printf("\n%s:\n", cur_path);
	}

	if (rts->opt_list) {
		pu = get_print_util_info(v);

		ft_printf("total %d\n", total_block);
		for (int i = 0; i < v->size; i++) {
			st = ((t_stat *)v->arr)[i];
			if (st.acl[1] == '?') {
				ft_printf("%10s %*c %*c %*c %*c %13c %s\n", \
					st.acl, \
					pu.link_len, '?', \
					pu.uid_len, '?', \
					pu.gid_len, '?', \
					pu.file_size_len, '?', \
					'?', st.filename);
				continue ;
			}
			ft_printf("%10s %*u ", \
					st.acl, pu.link_len, st.nlink);

			pw = getpwuid(st.uid);
			if (pw)
				ft_printf("%*s ", pu.uid_len, pw->pw_name);
			else
				ft_printf("%*u ", pu.uid_len, st.uid);

			gr = getgrgid(st.gid);
			if (gr)
				ft_printf("%*s ", pu.gid_len, gr->gr_name);
			else
				ft_printf("%*u ", pu.gid_len, st.gid);

			ft_printf("%*d %s %s",
					pu.file_size_len, st.file_size, \
					st.time_str, st.filename);
			if (st.acl[0] == 'l' && st.linked_filename[0] != '\0')
				ft_printf(" -> %s", st.linked_filename);
			ft_printf("\n");
		}
	}
	else {
		for (int i = 0; i < v->size; i++) {
			st = ((t_stat *)v->arr)[i];
			ft_printf("%s\n", st.filename);
		}
	}
}

t_print_util	get_print_util_info(t_vector *v) {
	t_stat			st;
	t_print_util	pu;
	struct passwd	*pw;
	struct group	*gr;

	ft_memset(&pu, 0, sizeof(pu));
	for (int i = 0; i < v->size; i++) {
		st = ((t_stat *)v->arr)[i];
		if (st.acl[1] == '?')
			continue ;
		if (ft_numlen(st.nlink) + 1 > pu.link_len)
			pu.link_len = ft_numlen(st.nlink);

		pw = getpwuid(st.uid);
		if (pw)
			pu.uid_len = ft_strlen(pw->pw_name) > pu.uid_len ? \
					ft_strlen(pw->pw_name) : pu.uid_len;
		else
			pu.uid_len = ft_numlen(st.uid) > pu.uid_len ? \
					ft_numlen(st.uid) : pu.uid_len;

		gr = getgrgid(st.gid);
		if (gr)
			pu.gid_len = ft_strlen(gr->gr_name) > pu.gid_len ? \
					ft_strlen(gr->gr_name) : pu.gid_len;
		else
			pu.gid_len = ft_numlen(st.gid) > pu.gid_len ? \
					ft_numlen(st.gid) : pu.gid_len;

		if (ft_numlen(st.file_size) > pu.file_size_len)
			pu.file_size_len = ft_numlen(st.file_size);
	}
	if (pu.link_len == 0) {
		// 모든 파일이 ?인 경우
		pu.link_len = 1;
		pu.uid_len = 1;
		pu.gid_len = 1;
		pu.file_size_len = 1;
	}
	return pu;
}
