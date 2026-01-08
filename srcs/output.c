#include "../includes/ft_ls.h"

void	print_outputs(t_rts *rts, char *cur_path, int total_block, t_vector *v) {
	t_stat	st;

	if (rts->opt_recursive) {
		ft_printf("%s:\n", cur_path);
	}

	ft_printf("total %d\n", total_block);
	if (rts->opt_list) {
		for (int i = 0; i < v->size; i++) {
			st = ((t_stat *)v->arr)[i];
			// TODO: 간격 조정
			ft_printf("%10s %10u %15s %15s %10d %s\n", \
					st.acl, st.nlink, st.uid, st.gid, st.file_size, st.filename);
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
