NAME = cub3D

SRC = cube_pl_move.c cube_sprite.c parser_cheak_have.c parser_init.c cube_close.c cube_pl_move_2.c cube_sprite_2.c main.c parser_cheak_map.c parser_liba.c cube_distans.c cube_pl_pos.c cube_tex.c get_next_line_utils.c parser_checker.c parser_map.c cube_draw_map.c cube_pl_pos_2.c parser.c parser_color.c parser_path.c cube_pixel.c cube_screen.c get_next_line.c parser_do_map.c parser_sprite.c

LIBNAME = ft_cub3d.a

FLAGS = -Wall -Wextra -Werror

MLX = minilibx_opengl_20191021

MLXFLAGS = -L minilibx_opengl_20191021 -lmlx  -framework OpenGL -framework AppKit

OBJECT = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJECT)
	ar rcs $(LIBNAME) $(OBJECT)
	gcc -I $(MLX) $(MLXFLAGS) $(LIBNAME) -o $(NAME)

%.o:%.c
	gcc $(FLAGS) -c $< -o $@

norme:
		norminette cube_pl_move.c cube_sprite.c parser_cheak_have.c parser_init.c cube_close.c cube_pl_move_2.c cube_sprite_2.c main.c parser_cheak_map.c parser_liba.c cube_distans.c cube_pl_pos.c cube_tex.c get_next_line_utils.c parser_checker.c parser_map.c cube_draw_map.c cube_pl_pos_2.c parser.c parser_color.c parser_path.c cube_pixel.c cube_screen.c get_next_line.c parser_do_map.c parser_sprite.c cube.h get_next_line.c

clean:
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(LIBNAME)
	/bin/rm -f screenshot.bmp

re: fclean all