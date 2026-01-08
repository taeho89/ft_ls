#include "../includes/ft_ls.h"

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
