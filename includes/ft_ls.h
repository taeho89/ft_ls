#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include "../includes/allocator.h"
# include "../includes/vector.h"

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
	int 			ino;
	int 			uid;
	int 			gid;
	int 			file_size;
	struct timespec	time;
	char			filename[256];
};

void	loop(t_rts *rts);

#endif
