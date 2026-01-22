#include "../includes/ft_ls.h"

void	print_outputs(t_rts *rts, char *cur_path, int total_block, t_vector *v) {
	t_stat	st;

	if (rts->opt_recursive) {
		ft_printf("%s:\n", cur_path);
	}

	ft_printf("total %d\n", total_block);
	int		link_len;
	int		uid_len;
	int		gid_len;
	int		file_size_len;
	if (rts->opt_list) {
		for (int i = 0; i < v->size; i++) {
			st = ((t_stat *)v->arr)[i];
			// TODO: 간격 조정
			ft_printf("%10s %*u %*s %*s %*d %s\n", \
					st.acl, \
					ft_numlen(st.nlink) + 1, st.nlink, \
					ft_strlen(st.uid), st.uid, \
					ft_strlen(st.gid), st.gid, \
					ft_numlen(st.file_size) + 2, st.file_size, \
					st.filename);
		}
	}
	else {
		for (int i = 0; i < v->size; i++) {
			st = ((t_stat *)v->arr)[i];
			ft_printf("%s ", st.filename);
		}
	}
	ft_printf("\n");
}
