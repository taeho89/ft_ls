#include "../includes/ft_ls.h"

int	main(int ac, char **av) {
	t_rts	rts;
	char	*path;

	ft_memset(&rts, 0, sizeof(rts));
	vector_init(&rts.target, sizeof(char *));
	// TODO: preprocess input (parse options)
	parse_opt(&rts, ac, av);

	for (int i = 0; i < rts.target.size; i++) {
		loop(&rts, ((char **)rts.target.arr)[i]);
	}
	return 0;
}
