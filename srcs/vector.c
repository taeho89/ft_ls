#include "../includes/vector.h"
#include "../includes/allocator.h"
#include <stdlib.h>
#include "../libft/libft.h"

void	quick_sort(t_vector *v, int comp(void *a, void *b), int left, int right);

void	vector_init(t_vector *v, int element_size) {
	v->element_size = element_size;
	v->capacity = 4;
	v->size = 0;
	v->arr = ft_malloc(v->capacity * v->element_size);
}

void	push_back(t_vector *v, void *value) {
	if (v->size == v->capacity) {
		v->capacity *= 2;
		v->arr = ft_realloc(v->arr, v->capacity * v->element_size);
	}

	// v->arr[v->size++] = value;
	int pos = v->size * v->element_size;
	for (int i = 0; i < v->element_size; i++) {
		((char *)(v->arr + pos))[i] = ((char *)value)[i];
	}
	v->size++;
}

void	swap(t_vector *v, int idx1, int idx2) {
	void	*tmp;

	tmp = malloc(v->element_size);
	if (!tmp) {
		// TODO: 에러 처리 고민 (still reachable)
		exit(1);
	}
	ft_memcpy(tmp, v->arr + idx1 * v->element_size, v->element_size);
	ft_memcpy(v->arr + idx1 * v->element_size, v->arr + idx2 * v->element_size, v->element_size);
	ft_memcpy(v->arr + idx2 * v->element_size, tmp, v->element_size);
}

void	sort(t_vector *v, int comp(void *a, void *b)) {
	quick_sort(v, comp, 0, v->size - 1);
}

void	quick_sort(t_vector *v, int comp(void *a, void *b), int left, int right) {
	int	pivot;
	int	low;
	int	high;	

	if (left >= right)
		return ;

	pivot = left;
	low = left + 1;
	high = right;
	while (low < high) {
		// compare(v->arr[left], v->arr[right])
		if (comp(v->arr + v->element_size * low, v->arr + v->element_size * high)) {
			swap(v, low, high);
		}
		low++;
		high--;
	}

	if (comp(v->arr + v->element_size * pivot, v->arr + v->element_size * high)) {
		swap(v, pivot, high);
	}

#ifdef DEBUG
# include "../includes/ft_ls.h"
	t_stat	st;

	ft_printf("====== DEBUG SORTING =======");
	ft_printf("left: %d, right: %d\n", left, right);
	for (int i = 0; i < v->size; i++) {
		st = ((t_stat *)v->arr)[i];
		ft_printf("%s\n", st.filename);
	}
	ft_printf("\n");
#endif

	quick_sort(v, comp, left, high - 1);
	quick_sort(v, comp, high + 1, right);
}
