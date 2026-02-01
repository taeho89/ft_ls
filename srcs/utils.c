#include "../includes/ft_ls.h"

char	get_opt(char *av);

void	parse_opt(t_rts *rts, int ac, char **av) {
	for (int i = 1; i < ac; i++) {
		switch (get_opt(av[i])) {
			case 'l':
				rts->opt_list = 1;
				break;
			case 'r':
				rts->opt_reverse = 1;
				break;
			case 'R':
				rts->opt_recursive = 1;
				break;
			case 'a':
				rts->opt_all = 1;
				break;
			case 't':
				rts->opt_time = 1;
				break;
			default:
				push_back(&rts->target, &av[i]);
		}
	}

}

char	get_opt(char *av) {
	if (av[0] != '-')
		return 0;

	if (ft_strncmp(av, "--list", 7))
		return 'l';
	if (ft_strncmp(av, "-l", 3))
		return 'l';
	if (ft_strncmp(av, "--recursive", 12))
		return 'R';
	if (ft_strncmp(av, "-R", 3))
		return 'R';
	if (ft_strncmp(av, "--reverse", 10))
		return 'r';
	if (ft_strncmp(av, "-r", 3))
		return 'r';
	if (ft_strncmp(av, "--all", 6))
		return 'a';
	if (ft_strncmp(av, "-a", 3))
		return 'a';
	if (ft_strncmp(av, "-t", 3))
		return 't';

	return 0;
}

char	*join_path(char *front, char *back) {
	char	*new_path;
	char	*tmp;

	tmp = ft_strjoin(front, "/");
	if (!tmp) {
		return NULL;
	}
	new_path = ft_strjoin(tmp, back);
	if (!new_path) {
		return NULL;
	}
	return new_path;
}

int	ft_numlen(size_t num) {
	int	len;

	len = 0;
	while (num) {
		num = num / 10;
		len++;
	}
	return len;
}
