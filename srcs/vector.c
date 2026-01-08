#include "../includes/vector.h"
#include "../includes/allocator.h"
#include <stdlib.h>
#include "../libft/libft.h"

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
