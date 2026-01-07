# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 20:14:58 by takwak            #+#    #+#              #
#    Updated: 2024/10/23 23:46:41 by takwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Werror -Wextra -Wall

NAME = libftprintf.a
SRCS = ft_adrlen.c					\
	   ft_check_flag.c				\
	   ft_check_type.c				\
	   ft_check_width.c				\
	   ft_check_prec.c				\
	   ft_default_print.c			\
	   ft_error.c					\
	   ft_init_struct.c				\
	   ft_intlen_base.c				\
	   ft_is_flag_minus.c			\
	   ft_is_flag_plus.c			\
	   ft_is_flag_sharp.c			\
	   ft_is_flag_space.c			\
	   ft_is_flag_zero.c			\
	   ft_is_valid_type.c			\
	   ft_prec_set_zero.c			\
	   ft_print_arg.c				\
	   ft_print_type.c				\
	   ft_print_type_def_cs.c		\
	   ft_print_type_def_iduxlxp.c	\
	   ft_printf.c					\
	   ft_printlen_arg.c			\
	   ft_sizet_toa_base.c			\
	   ft_sizetlen_base.c			\
	   ft_typedef_cps.c				\
	   ft_typedef_iduxlx.c			\
	   ft_write.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C ./libft
	cp ./libft/libft.a $(NAME)
	ar rcs $@ $^

%.o : %.c
	$(CC) $(FLAGS) -c $^ -o $@

clean :
	rm -f *.o
	@make clean -C ./libft

fclean : clean
	rm -rf $(NAME)
	@make fclean -C ./libft 

re : fclean all

bonus : $(NAME)
