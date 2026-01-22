#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include "../includes/allocator.h"
# include "../includes/vector.h"
# include <stdint.h>
# include <inttypes.h>

typedef struct s_rts 	t_rts;
typedef struct s_stat	t_stat;

/* Runtime State */
struct s_rts {
	t_vector	v;

	/* Option bit field */
	unsigned char
		opt_list:1,
		opt_recursive:1,
		opt_reverse:1,
		opt_all:1,
		opt_time:1;
};

struct s_stat {
	char			acl[10];
	uintmax_t		nlink;
	char			*uid;
	char			*gid;
	int				file_size;
	struct timespec	time;
	char			filename[256];
};

void	loop(t_rts *rts, char *path);

/* utils.c */
char	*join_path(char *front, char *back);
int		ft_numlen(size_t num);

/* output.c */
void	print_outputs(t_rts *rts, char *cur_path, int total_block, t_vector *v);

void	sort(t_rts *rts, t_vector *v);
#endif
