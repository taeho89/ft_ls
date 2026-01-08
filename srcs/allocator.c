#include "../includes/allocator.h"
#include <stdlib.h>
#include <stdio.h>

void	*ft_malloc(int size) {
	t_header	*header;

	header = (t_header *)malloc(sizeof(t_header) + size);
	if (!header) {
		return NULL;
	}
	header->size = size;
	return (void *)(header + 1);
}

void	*ft_realloc(void *ptr, int new_size) {
	void		*new_ptr;
	int			old_size;
	int			copy_size;
	t_header	*header;

	if (!ptr) {
		return ft_malloc(new_size);
	}

	if (new_size == 0) {
		free(ptr);
		return NULL;
	}

	header = ((t_header *)ptr) - 1;
	old_size = header->size;

	new_ptr = ft_malloc(new_size);

	copy_size = (old_size < new_size) ? old_size : new_size;
	for (int i = 0; i < copy_size; i++) {
		((char *)new_ptr)[i] = ((char *)ptr)[i];
	}
	free(header);

	return new_ptr;
}
