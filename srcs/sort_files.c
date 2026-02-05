#include "../includes/ft_ls.h"

int	compare_by_name(void *s1, void *s2);
int	compare_by_name_rev(void *a, void *b);
int	compare_by_time_rev(void *a, void *b);
int	compare_by_time(void *a, void *b);

void	sort_files(t_rts *rts, t_vector *v) {
	if (rts->opt_time) {
		if (rts->opt_reverse)
			sort(v, compare_by_time_rev, 0, v->size - 1);
		else
			sort(v, compare_by_time, 0, v->size - 1);
	}
	else {
		if (rts->opt_reverse)
			sort(v, compare_by_name_rev, 0, v->size - 1);
		else
			sort(v, compare_by_name, 0, v->size - 1);
	}
}

// if true: have to swap
int	compare_by_name(void *a, void *b) {
	char	*s1;
	char	*s2;

	s1 = ((t_stat *)a)->filename;
	s2 = ((t_stat *)b)->filename;
	return ft_strncmp((char *)s1, (char *)s2, ft_strlen(s1) + 1) > 0;
}

int	compare_by_name_rev(void *a, void *b) {
	char	*s1;
	char	*s2;

	s1 = ((t_stat *)a)->filename;
	s2 = ((t_stat *)b)->filename;
	return ft_strncmp((char *)s1, (char *)s2, ft_strlen(s1) + 1) < 0;
}

int	compare_by_time(void *a, void *b) {
	struct timespec	t1;
	struct timespec	t2;

	t1 = ((t_stat *)a)->time_epoch;
	t2 = ((t_stat *)b)->time_epoch;
	if (t1.tv_sec != t2.tv_sec)
		return t1.tv_sec < t2.tv_sec;
	if (t1.tv_nsec != t2.tv_nsec)
		return t1.tv_nsec < t2.tv_nsec;
	return compare_by_name(a, b);
}

int	compare_by_time_rev(void *a, void *b) {
	struct timespec	t1;
	struct timespec	t2;

	t1 = ((t_stat *)a)->time_epoch;
	t2 = ((t_stat *)b)->time_epoch;
	if (t1.tv_sec != t2.tv_sec)
		return t1.tv_sec > t2.tv_sec;
	if (t1.tv_nsec != t2.tv_nsec)
		return t1.tv_nsec > t2.tv_nsec;
	return compare_by_name_rev(a, b);
}
