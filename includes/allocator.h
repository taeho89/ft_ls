#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include "../libft/libft.h"

typedef struct s_block {
	char			*data;
	size_t			capacity;
	size_t			used;
	struct s_block	*next;
}	t_block;

typedef struct s_header {
	size_t	size;
}	t_header;

typedef struct s_arena_cursor {
	t_block	*block;
	size_t	used;
}	t_arena_cursor;

void	*ft_xmalloc(size_t size);
void	*ft_realloc(void *ptr, size_t new_size);
// void	ft_free(void *ptr);

void			arena_init();
void			arena_free();
t_arena_cursor	get_arena_cursor();
void			arena_rewind(t_arena_cursor cursor);

#endif
