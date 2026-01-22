NAME = ft_ls

CC = cc
CFLAGS= -g

SRC_DIR = srcs/
SRCS =	ft_ls.c	\
		loop.c	\
		vector.c	\
		allocator.c	\
		utils.c		\
		output.c	\
		sort.c	

OBJ_DIR = objs/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

LIBFT_DIR = libft
LIBFT_NAME = ft
LIBFT_A = $(LIBFT_DIR)/lib$(LIBFT_NAME).a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -l$(LIBFT_NAME) -o $@

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $^ -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

fclean_all: fclean
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean fclean_all re
