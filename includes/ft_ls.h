#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include "../includes/allocator.h"
# include "../includes/vector.h"
# include <stdint.h>
# include <inttypes.h>
# include <errno.h>
# include <time.h>

# define PROGNAME "ft_ls"
# define MONTHS_6 (60 * 60 * 24 * 30 * 6)

#if defined(__GNUC__) || defined(__clang__)
	#define ATTRIBUTE_NONNULL(args) __attribute__((nonnull args))
#else
	#define ATTRIBUTE_NONULL(args)
#endif

typedef struct s_rts 		t_rts;
typedef struct s_stat		t_stat;
typedef struct s_print_util t_print_util;

/* Runtime State */
struct s_rts {
	t_vector	target;

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
	char			time_str[13];
	struct timespec	time_epoch;
	char			filename[256];
	char			linked_filename[256];
	int				blocks;
};

struct s_print_util {
	int	link_len;
	int	uid_len;
	int	gid_len;
	int	file_size_len;
};

void	loop(t_rts *rts, char *path);

/* utils.c */
void	parse_opt(t_rts *rts, int ac, char **av);
char	*join_path(char *front, char *back);
int		ft_numlen(size_t num);
void	save_target_files(t_rts *rts, int ac, char **av);

/* output.c */
void	print_outputs(t_rts *rts, char *cur_path, int total_block, t_vector *v);

void	sort_files(t_rts *rts, t_vector *v);

void	error(int status, const char *argument, const char *errmsg);
#endif
