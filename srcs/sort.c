#include "../includes/ft_ls.h"

int	compare_by_name(void *s1, void *s2);

void	sort_files(t_rts *rts, t_vector *v) {
	t_stat	st1;
	t_stat	st2;

	if (rts->opt_time) {
		if (rts->opt_reverse) {
			//
		}
		else {

		}
	}
	else {
		if (rts->opt_reverse) {
			//
		}
		else {
			sort(v, compare_by_name);
		}
	}
}

// int	compare_by_time() {
//
// }

// if true: have to swap
int	compare_by_name(void *a, void *b) {
	char	*s1;
	char	*s2;
	int		s1_len;
	int		s2_len;
	int		max_len;

	s1 = ((t_stat *)a)->filename;
	s2 = ((t_stat *)b)->filename;
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	max_len = s1_len > s2_len ? s1_len : s2_len;
	if (ft_strncmp((char *)s1, (char *)s2, max_len) == 0) {
		return ft_strncmp((char *)s1, (char *)s2, max_len) < 0;
	}
	return ft_strncmp((char *)s1, (char *)s2, max_len) > 0;
}
