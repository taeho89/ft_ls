#include "../includes/vector.h"
#include "../includes/allocator.h"

void	vector_init(t_vector *v, int element_size) {
	v->element_size = element_size;
	v->capacity = 4;
	v->size = 0;
	v->arr = ft_malloc(v->capacity * v->element_size);
}

void	push_back(t_vector *v, void *value) {
	if (v->size == v->capacity) {
		v->capacity *= 2;
		v->arr = ft_realloc(v, v->capacity * v->element_size);
	}

	// v->arr[v->size++] = value;
	int pos = v->size * v->element_size;
	for (int i = 0; i < v->element_size; i++) {
		((char *)(v->arr + pos))[i] = ((char *)value)[i];
	}
	v->size++;
}
