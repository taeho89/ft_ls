#include "../includes/ft_ls.h"
#include <dirent.h>
#include <sys/stat.h>

void	loop(t_rts *rts) {
	DIR	*dir;
	struct dirent	*cur;
	t_vector		v;

	dir = opendir(".");
	cur = readdir(dir);
	while (cur) {
		struct stat	statbuf;
	
		ft_printf("%s  ", cur->d_name);
		if (!ft_strncmp(cur->d_name, ".", 1)) {
			cur = readdir(dir);
			continue ;
		}
		if (stat(ft_strjoin("./", cur->d_name), &statbuf) < 0) {
			perror(ft_strjoin("\n./", cur->d_name));
		}
		// t_stat 구조체 생성
		// TODO: push_back(v, new t_stat);
		cur = readdir(dir);
	}
	// TODO: sorting && printing
	ft_printf("\n");
}
