#include "../includes/vector.h"
#include "../includes/allocator.h"

void	quick_sort(t_vector *v, int comp(void *a, void *b), int left, int right);

t_vector *vector_ctor(t_vector *v, int element_size) {
	v->element_size = element_size;
	v->capacity = 4;
	v->size = 0;
	v->arr = ft_xmalloc(v->capacity * v->element_size);
	if (!v->arr) {
		return NULL;
	}
	return v;
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
	char	*ptr1;
	char	*ptr2;
	char	tmp;
	
	ptr1 = (char *)v->arr + idx1 * v->element_size;
	ptr2 = (char *)v->arr + idx2 * v->element_size;
	for (int i = 0; i < v->element_size; i++) {
		tmp = ptr1[i];
		ptr1[i] = ptr2[i];
		ptr2[i] = tmp;
	}
}

void	sort(t_vector *v, int comp(void *a, void *b), int left, int right) {
	int	pivot;
	int	low;
	int	high;	

	if (left >= right)
		return ;

	pivot = left;
	low = left + 1;
	high = right;
	while (low <= high) {
		// compare(v->arr[low], v->arr[pivot]) => low < pivot => low++
		while (low <= right	\
			&& !comp(v->arr + v->element_size * low, v->arr + v->element_size * pivot)) {
			low++;
		}
		// compare(v->arr[high], v->arr[pivot]) => high > pivot => high--
		while (high >= left + 1	\
			&& comp(v->arr + v->element_size * high, v->arr + v->element_size * pivot)) {
			high--;
		}

		if (low < high) {
			swap(v, low, high);
		}
	}

	swap(v, pivot, high);

	sort(v, comp, left, high - 1);
	sort(v, comp, high + 1, right);
}
