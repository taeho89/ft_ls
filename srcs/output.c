#include "../includes/ft_ls.h"

t_print_util	get_print_util_info(t_vector *v)
	ATTRIBUTE_NONNULL((1));

void	print_outputs(t_rts *rts, char *cur_path, int total_block, t_vector *v) {
	t_stat			st;
	t_print_util	pu;

	if (rts->opt_recursive) {
		ft_printf("%s:\n", cur_path);
	}

	if (rts->opt_list) {
		pu = get_print_util_info(v);

		ft_printf("total %d\n", total_block);
		for (int i = 0; i < v->size; i++) {
			st = ((t_stat *)v->arr)[i];
			ft_printf("%10s %*u %*s %*s %*d %s %s", \
					st.acl, \
					pu.link_len, st.nlink, \
					pu.uid_len, st.uid, \
					pu.gid_len, st.gid, \
					pu.file_size_len, st.file_size, \
					st.time_str, st.filename);
			if (st.acl[0] == 'l')
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

	ft_memset(&pu, 0, sizeof(pu));
	for (int i = 0; i < v->size; i++) {
		st = ((t_stat *)v->arr)[i];
		if (ft_numlen(st.nlink) + 1 > pu.link_len)
			pu.link_len = ft_numlen(st.nlink);
		if (ft_strlen(st.uid) > pu.uid_len)
			pu.uid_len = ft_strlen(st.uid);
		if (ft_strlen(st.gid) > pu.gid_len)
			pu.gid_len = ft_strlen(st.gid);
		if (ft_numlen(st.file_size) > pu.file_size_len)
			pu.file_size_len = ft_numlen(st.file_size);
	}
	return pu;
}
