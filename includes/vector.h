#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector	t_vector;

struct s_vector {
	void	*arr;
	int		element_size;
	int		capacity;
	int 	size;
};

void	push_back(t_vector *v, void *value);
void	vector_ctor(t_vector *v, int element_size);
void	vector_dtor(t_vector *v);
void	swap(t_vector *v, int idx1, int idx2);
void	sort(t_vector *v, int comp(void *a, void *b));

#endif
