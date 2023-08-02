CC=cc
NAME=cub3D
CFLAGS=-Wall -Wextra -Werror #-fsanitize=address -g #-Imlx 
SRC =  main.c keyhook.c draw_pixel.c rayplayer.c


OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all	

.PHONY: clean fclean all