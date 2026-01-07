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
MAKEFLAGS += --no-print-directory

CC = cc
FLAGS = -Wall -Werror -Wextra -std=c99

NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c 			\
	   ft_isblank.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c 		\
	   ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c 		\
	   ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strdup.c 	\
	   ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c 			\
	   ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS = $(SRCS:.c=.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJS = $(BONUS:.c=.o)

# ifdef WITH_BONUS
#     OBJ = $(OBJS) $(BONUS_OBJS)
# else
#     OBJ = $(OBJS)
# endif

OBJ = $(OBJS) $(BONUS_OBJS)

all : $(NAME)

$(NAME) : $(OBJ) $(GNL_OBJS)
	ar rcs $@ $^

%.o : %.c
	$(CC) $(FLAGS) -c $^ -o $@

$(GNL_OBJS) : $(GNL_SRCS)
	$(CC) $(FLAGS) -c $^ -o $@

clean :
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus :
	make WITH_BONUS=1 all

# bonus : $(OBJS) $(BONUS_OBJS)
# 	ar rcs $(NAME) $^
# 	touch $@

# %.o : %.c
# 	$(CC) $(FLAGS) -c $^ -o $@
