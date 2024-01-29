NAME		= fdf
LIBFT		= libft/libft.a
MINILIBX	= minilibx/libmlx.a
SRC 		= $(wildcard src/*.c)
OBJ 		= ${patsubst src/%.c, objs/%.o, $(SRC)}
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g
MLIBX_FLAGS	= -lX11 -lXext -lm
INCLUDE		= -I includes/
RM = rm -rf

all:	$(NAME) 

$(LIBFT):
		@$(MAKE) -s -C libft/

$(MINILIBX):
		@$(MAKE) -s -C minilibx/

objs:
		@mkdir -p objs > /dev/null 2>&1

$(OBJ): objs/%.o: src/%.c | objs
		$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ)
		$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(LIBFT) $(MINILIBX) -o $(NAME) \
			$(MLIBX_FLAGS)

clean: 
		@make clean -C libft
		${RM} ${OBJ}
		@rm -rf objs


fclean: clean
		@make fclean -C libft
		@make clean -C minilibx
		${RM} $(NAME)
		${RM} $(LIBFT)

re: fclean all

.PHONY:		all clean fclean re
