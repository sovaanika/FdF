NAME = fdf
SRCSFOLDER = ./srcs/
SRCS = error.c winresize.c keyfunctions.c legend.c main.c celldraw.c bresenham.c projection.c resize.c rotate.c move.c draw.c validation.c putcords.c ft_atoi_base.c makestablemap.c
OBJNAME = $(SRCS:.c=.o)
OBJDIR = ./obj/
OBJ = $(addprefix $(OBJDIR),$(OBJNAME))
INCLUDES = fdf.h
GCCFLAG = -Wall -Wextra -Werror

LIBFTFOLDER = ./libft/
LIBFTINCLUDES = $(LIBFTFOLDER)
LIBFTINK = -I $(LIBFTINCLUDES) -L $(LIBFTFOLDER) -lft

MLXLINTMACOS = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFTFOLDER)
	gcc -g $(GCCFLAG) $(OBJ) $(MLXLINTMACOS) $(LIBFTINK) -o $(NAME)

clean:
	@$(MAKE) -C $(LIBFTFOLDER) clean
	rm -rf $(OBJDIR)
	rm -rf *.o

fclean: clean
	@$(MAKE) -C $(LIBFTFOLDER) fclean
	rm -rf $(OBJDIR)
	rm -rf $(NAME)

$(OBJDIR)%.o:$(SRCSFOLDER)%.c
	@mkdir -p $(OBJDIR)
	@gcc $(GCCFLAG) -I $(INCLUDES) -o $@ -c $<

re:	fclean $(NAME)

makeft:
	@$(MAKE) -C $(LIBFTFOLDER)