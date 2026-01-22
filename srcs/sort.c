#include "../includes/ft_ls.h"

int	compare_by_name(char *s1, char *s2);

void	sort(t_rts *rts, t_vector *v) {
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
			int	flag = 1;

			while (flag) {
				flag = 0;
				for (int i = 0; i < v->size; i++) {
					st1 = ((t_stat *)v->arr)[i];
					for (int j = i + 1; j < v->size; j++) {
						st2 = ((t_stat *)v->arr)[j];
						if (compare_by_name(st1.filename, st2.filename)) {
							swap(v, i, j);
							st1 = ((t_stat *)v->arr)[i];
							st2 = ((t_stat *)v->arr)[j];
							flag = 1;
						}
					}
				}
				usleep(1000);
			}
		}
	}
}

// int	compare_by_time() {
//
// }

// if true: have to swap
int	compare_by_name(char *s1, char *s2) {
	int	s1_len;
	int	s2_len;
	int	max_len;
	char	*s1_cpy;
	char	*s2_cpy;

	s1_cpy = ft_strdup(s1);
	s2_cpy = ft_strdup(s2);

	for (int i = 0; s1[i]; i++) {
		s1_cpy[i] = ft_toupper(s1_cpy[i]);
	}
	for (int i = 0; s2[i]; i++) {
		s2_cpy[i] = ft_toupper(s2_cpy[i]);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	max_len = s1_len > s2_len ? s1_len : s2_len;
	if (ft_strncmp(s1_cpy, s2_cpy, max_len) == 0) {
		return ft_strncmp(s1, s2, max_len) < 0;
	}
	return ft_strncmp(s1_cpy, s2_cpy, max_len) > 0;
}
