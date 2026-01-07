#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector	t_vector;

struct s_vector {
	void	*arr;
	int		element_size;
	int		capacity;
	int 	size;
};

#endif
