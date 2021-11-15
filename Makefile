CC		= gcc
NAME	= so_long
MINILIB	= -L mlx -l mlx -framework OpenGL -framework AppKit
HEADER	= so_long.h
OBJS	= $(SRCS:.c=.o)
SRCS	= so_long.c so_longutils.c ./utils/gnl/get_next_line_utils.c ./utils/gnl/get_next_line.c \
			./utils/map/maputils.c ./utils/map/ft_takemap.c ./utils/map/ft_checkmap.c ./utils/mlxcontrol.c \
			./utils/ft_free.c ./utils/keys/keys_hook.c ./utils/map/ft_draw.c ./utils/movement/movement.c \
			./utils/movement/objetos.c

all:	$(NAME)


$(NAME):	$(OBJS)
	@make -C ./mlx
	gcc -g $(OBJS) $(MINILIB) -o $(NAME)
			
.c.o:
			$(CC) -g -I $(HEADER) -c $< -o $(<:.c=.o)
			
clean:		
	rm -rf $(OBJS)
	
fclean:		clean
			rm -rf $(NAME) a.out
			@make clean -C ./mlx

re:			fclean all

