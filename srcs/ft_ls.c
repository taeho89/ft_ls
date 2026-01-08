#include "../includes/ft_ls.h"

int	main(int ac, char **av) {
	t_rts	rts;
	// TODO: preprocess input (parse options)
	
	// TODO: main_logic
	ft_memset(&rts, 0, sizeof(rts));
	rts.opt_list = 1;
	rts.opt_recursive = 1;
	loop(&rts, av[1]);
	return 0;
}
