CC=clang
NAME=cub3D
CFLAGS=-Wall -Wextra -Werror #-fsanitize=address -g3

SRC =  main.c keyhook.c draw_pixel.c rayplayer.c rays_func.c


OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all	

.PHONY: clean fclean all