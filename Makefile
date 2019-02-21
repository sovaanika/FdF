NAME = fdf
SRC = error.c 1.c celldraw.c bresenham.c validation.c
INC = fdf.h
LIB = ./libft/

all: $(NAME)

$(NAME):
	@$(MAKE) -C $(LIB)
	gcc -g -Wall -Wextra -Werror -o $(NAME) $(SRC) -I$(INC) ./libft/libft.a -I$(LIB) -lmlx -framework OpenGL -framework AppKit

clean:
	@$(MAKE) -C $(LIB) clean

fclean: clean
	@$(MAKE) -C $(LIB) fclean
	/bin/rm -f $(NAME)

re: fclean all