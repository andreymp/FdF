NAME =	fdf

CC =	gcc
CFLAGS =	-Wall -Wextra -Werror -MMD -o3

RM =	rm -rf

SRC =	utils.c \
		init.c \
		main.c \
		fdf.c \
		paint.c \
		get_next_line.c \
		get_next_line_utils.c \
		iso_and_paint.c \

INC =	-I fdf.h \
		-I get_next_line.h \
		-I libft/libft.h \
		-I minilibx/mlx.h \

OBJS =	$(SRC:.c=.o)
DEP =	$(SRC:.c=.d)

#MLXFLAGS =	-lft -lm -lmx -lXext -lX11
LD_FLAGS =	-L libft -L minilibx

.PHONY :	all clean re fclean

.c.o :		
		${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}


$(NAME):	$(OBJS)
			make -C ./minilibx/
			make -C ./libft/
			${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -lft -lmx -framework OpenGL -framework AppKit libmlx.a ./libft/libft.a -o ${NAME}

all: 		$(NAME)

clean:
			$(RM) $(OBJS) $(DEP) get_next_line.o get_next_line.d get_next_line_utils.o get_next_line_utils.d
			make clean -C minilibx/
			make clean -C libft/

fclean: 	clean
			$(RM) $(NAME)
			make clean -C minilibx/
			make fclean -C libft/

re: 		fclean all

-include $(DEP)