#include "../includes/ft_ls.h"
#include <string.h>

void	error(int status, const char *argument, const char *errmsg) {
	write(2, PROGNAME, ft_strlen(PROGNAME));
	write(2, ": ", 2);
	write(2, errmsg, ft_strlen(errmsg));
	write(2, " \'", 2);
	if (argument)
		write(2, argument, ft_strlen(argument));
	write(2, "\': ", 3);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	
	if (status)
		exit(status);
}
