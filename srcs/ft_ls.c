#include "../includes/ft_ls.h"

int	main(int ac, char **av) {
	t_rts	rts;
	char	*path;

	ft_memset(&rts, 0, sizeof(rts));
	vector_init(&rts.target, sizeof(char *));
	parse_opt(&rts, ac, av);

	save_target_file(&rts, ac, av);
	
	if (rts.target.size == 0) {
		char	*s = ".";
		push_back(&rts.target, &s);
	}

	for (int i = 0; i < rts.target.size; i++) {
		loop(&rts, ((char **)rts.target.arr)[i]);
	}

	return 0;
}
