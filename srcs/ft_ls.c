#include "../includes/ft_ls.h"

int	main(int ac, char **av) {
	t_rts	rts;

	ft_memset(&rts, 0, sizeof(rts));

	if (vector_ctor(&rts.target, sizeof(char *)) == NULL) {
		error(2, NULL, "failed to create vector");
	}

	parse_opt(&rts, ac, av);

	save_target_files(&rts, ac, av);
	
	if (rts.target.size == 0) {
		char	*s = ".";
		push_back(&rts.target, &s);
	}

	for (int i = 0; i < rts.target.size; i++) {
		loop(&rts, ((char **)rts.target.arr)[i]);
	}

	vector_dtor(&rts.target);
	return 0;
}
