#include "../includes/ft_ls.h"

int	main(int ac, char **av) {
	t_rts	rts;
	char	*path;
	// TODO: preprocess input (parse options)
	if (ac == 1) {
		path = ".";
	} else {
		ft_strlcpy(path, av[1], ft_strlen(av[1]));
	}
	
	// TODO: main_logic
	ft_memset(&rts, 0, sizeof(rts));
	rts.opt_list = 1;
	rts.opt_recursive = 0;
	loop(&rts, path);
	return 0;
}
