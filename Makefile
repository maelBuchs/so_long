NAME =	so_long

CC = gcc
CFLAGS = -g
# CFLAGS = -Wall -Wextra -Werror -g
MLX = -L./minilibx-linux -lmlx -lX11 -lXext -lm
RM = rm -rf
HEAD = so_long.h
SRCS = 	main.c\
		put_win.c\
		read_tab.c\
		use_map.c\
		check_map.c\

OBJS = $(SRCS:.c=.o)

TOTAL_FILES = $(words $(SRCS))

all:			$(NAME)
				@clear
				@echo "Compilation terminée";

$(NAME):		$(OBJS)
				make --no-print-directory -C Libft/
				make --no-print-directory -C minilibx-linux/
#				gcc a.out -lm -I . -I ./Libft -L ./Libft -lft -I ./minilibx-linux -L ./minilibx-linux -mlx_Linux -lXext -lX11
				@$(CC) -o $(NAME)  $(HEAD) $(OBJS) $(CFLAGS) $(MLX) Libft/libft.a minilibx-linux/libmlx.a

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean:			
				make clean --no-print-directory -C  Libft/
				make clean --no-print-directory -C minilibx-linux/
				@$(RM) $(OBJS)
				@clear
				@echo "Clean OK";


fclean: 		clean
				@$(RM) $(NAME) Libft/libft.a libmlx_Linux.a
				@clear
				@echo "Full Clean OK ";

re: 			fclean all

.PHONY:			all clean fclean re
