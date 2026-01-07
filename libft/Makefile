# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/04 21:53:58 by takwak            #+#    #+#              #
#    Updated: 2024/10/31 06:17:06 by takwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Werror -Wextra

NAME = libft.a

all : $(NAME) 

$(NAME) :
	make -C ./ft_printf
	cp -r ./ft_printf/libftprintf.a ./$(NAME)
	make -C ./get_next_line
	ar rcs $@ get_next_line/get_next_line_bonus.o get_next_line/get_next_line_utils_bonus.o

%.o : %.c
	$(CC) $(FLAGS) -c $^ -o $@

clean :
	make -C ft_printf clean
	make -C get_next_line clean

fclean : clean
	rm -rf $(NAME) get_next_line/gnl.a
	make -C ft_printf fclean
	make -C get_next_line fclean

re : fclean all
