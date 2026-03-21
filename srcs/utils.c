#include "../includes/ft_ls.h"

char	get_opt(int ac, char **av, char *opt_list);

void	parse_opt(t_rts *rts, int ac, char **av) {
	char	c;

	while (1) {
		c = get_opt(ac, av, "altrR");
		if (c == -1)
			break ;
		switch (c) {
			case 'a':
				rts->opt_all = 1;
				break;
			case 'l':
				rts->opt_list = 1;
				break;
			case 't':
				rts->opt_time = 1;
				break;
			case 'r':
				rts->opt_reverse = 1;
				break;
			case 'R':
				rts->opt_recursive = 1;
				break;
		}
	}
}

/* POSIX 표준 및 과제 요구사항에 따라 short 옵션만 처리 */
char	get_opt(int ac, char **av, char *opt_list) {
	static int	i = 1;
	static int	j = 1;
	char 		*s;

	while (i < ac) {
		s = av[i];

		if (s[0] != '-') {
			i++;
			continue ;
		}

		while (j < ft_strlen(s)) {
			s = ft_strchr(opt_list, s[j++]);
			if (s) {
				return *s;
			}
		}
		i++;
	}
	return -1;
}

/* 명령행 인자로 들어온 파일들 저장 */
void	save_target_files(t_rts *rts, int ac, char **av) {
	int		i;
	char	*s;
	
	i = 1;
	while (i < ac) {
		s = av[i++];

		if (s[0] == '-')
			continue;

		push_back(&rts->target, &s);
	}
}

char	*join_path(char *front, char *back) {
	char	*new_path;
	char	*tmp;

	if (front[ft_strlen(front) - 1] != '/')
		tmp = ft_strjoin(front, "/");
	else
		tmp = ft_strdup(front);
	if (!tmp) {
		return NULL;
	}
	new_path = ft_strjoin(tmp, back);
	free(tmp);
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
