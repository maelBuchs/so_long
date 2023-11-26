NAME =	so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -L./minilibx-linux -lmlx -lX11 -lXext -lm
RM = rm -rf
HEAD = so_long.h
SRCS = 	main.c\
		so_long_1.c\
		so_long_2.c\

OBJS = $(SRCS:.c=.o)

TOTAL_FILES = $(words $(SRCS))

all:			$(NAME)
				@clear
				@echo "Compilation terminee";

$(NAME):		$(OBJS)
				make --no-print-directory -C Libft/
				make --no-print-directory -C minilibx-linux/
				@$(CC) -o $(NAME)  $(HEAD) $(OBJS) $(CFLAGS) $(MLX) Libft/libft.a minilibx-linux/libmlx.a

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean:			
				make clean --no-print-directory -C  libft/
				make clean --no-print-directory -C minilibx-linux/
				@$(RM) $(OBJS)
				@clear
				@echo "Clean OK";


fclean: 		clean
				@$(RM) $(NAME) libft/libft.a libmlx_Linux.a
				@clear
				@echo "Full Clean OK ";

re: 			fclean all

.PHONY:			all clean fclean re
