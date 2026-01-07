#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>

typedef struct s_header {
	size_t	size;
}	t_header;

void	*ft_malloc(int size);
void	*ft_realloc(void *ptr, int new_size);

#endif
