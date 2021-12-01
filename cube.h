/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:26:19 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 20:26:48 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "minilibx_mms_20200219/mlx.h"
# include "minilibx_opengl_20191021/mlx.h"
# include "minilibx_opengl_20191021/mlx_png.h"
# include "get_next_line.h"
# include <math.h>
# include <stdint.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

# ifndef TEX_H
#  define TEXWIDTH 64
#  define TEXHEIGHT 64
# endif

typedef struct		s_sprite
{
	double			x;
	double			y;
}					t_sprite;

typedef struct		s_win
{
	void			*mlx;
	void			*win_mlx;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_win;

typedef struct		s_tex
{
	void			*content;
	void			*tex;
	int				img_w;
	int				img_h;
	char			*c_addr;
	char			*t_addr;
	int				c_bpp;
	int				t_bpp;
	int				c_lnl;
	int				t_lnl;
	int				c_endian;
	int				t_endian;
}					t_tex;

typedef struct		s_vars
{
	long int		mapw;
	long int		maph;
	int				have_resolution;
	int				have_texture_no;
	int				have_texture_so;
	int				have_texture_ea;
	int				have_texture_we;
	int				have_sprite;
	int				have_floor;
	int				have_hero;
	int				have_ceiling;
	char			**map_t;
	int				count_line_map_t;
	int				first_line_map;
	int				len_max_string;
	char			**map;
	double			*zbuffer;
	char			*n_tex_path;
	char			*s_tex_path;
	char			*e_tex_path;
	char			*w_tex_path;
	int				line_in_map;
	int				save;
	int				move;
	int				map_end;
	int				map_done;
	int				x;
	double			wallx;
	int				texx;
	int				texy;
	double			step;
	double			texpos;
	int				y;
	void			*n_tex;
	int				n_width;
	int				n_height;
	void			*s_tex;
	int				s_width;
	int				s_height;
	void			*w_tex;
	int				w_width;
	int				w_height;
	void			*e_tex;
	int				e_width;
	int				e_height;
	void			*sp_tex;
	int				sp_width;
	int				sp_height;
	int				count_sprites;
	char			walldir;
	char			*sp_path;
	int				ceiling_color_r;
	int				ceiling_color_g;
	int				ceiling_color_b;
	int				ceiling_color;
	int				floor_color;
	int				floor_color_r;
	int				floor_color_g;
	int				floor_color_b;
	int				tmp_color;
	int				count_colors;
	t_win			*win;
	t_tex			*tex;
	t_sprite		*sprites;
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				drawstarty;
	int				drawendy;
	int				spritewidth;
	int				drawstartx;
	int				drawendx;
	int				texx_s;
	int				texy_s;
	int				stripe;
	int				tmp;
	int				dist_tmp;
	double			plx;
	double			ply;
	int				mapx;
	int				mapy;
	double			camerax;
	double			raydirx;
	double			raydiry;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				color;
	double			movespeed;
	double			rotspeed;
	double			olddirx;
	double			oldplanex;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	int				wall_size;
}					t_vars;

void				create_map_t(t_vars *vars, int fd);
int					count_line_map(char *file);
int					parser_map_t(t_vars *vars, char *line_map);
int					check_line(t_vars *vars, int i);
int					check_walls(t_vars *vars, int i);
int					check_null(t_vars *vars, int i, int j);
int					check_two_maps(const char *str);
int					null_end_line(t_vars *vars, int i, int j);
void				check_path_continuation(t_vars *vars,
					char *line_map, int *i);
void				check_path(char *line_map, t_vars *vars);
void				check_all_have_map_2(t_vars *vars);
void				check_all_have_map(t_vars *vars);
void				init_vars_map(t_vars *vars);
void				do_map(t_vars *vars, int i);
void				check_count_color(t_vars *vars, int count, char *s);
void				color_fill(char *s, int *i, t_vars *vars);
void				color_pars(char *s, t_vars *vars);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *str);
char				*ft_strlcpy(char *dst, const char *src);
int					ft_isdigit(char c);
void				parser(t_vars *vars, char *file);
int					checker_save(char *s);
int					checker_name(char *s);
int					check_xpm(char *s);
int					check_exist_path(char *path);
void				check_open_file(t_vars *vars);
void				so_no_path(char *s, t_vars *vars, int i, int j);
void				ea_we_path(char *s, t_vars *vars, int i, int j);
void				sp_tex_path(char *s, t_vars *vars);
void				tex_path(char *s, t_vars *vars);
void				check_all_path(t_vars *vars);
int					count_sprites(t_vars *vars);
t_sprite			*ft_get_sprites(t_vars *vars);
int					render_next_frame(t_vars *vars);
int					main(int argc, char **argv);
void				texures_path(t_vars *vars, char *path);
int					create_trgb(int t, int r, int g, int b);
void				game_init(t_vars *vars);
void				game_init_2(t_vars *vars);
void				init_plr_move(t_vars *vars);
void				plr_move_0(t_vars *vars);
void				plr_move_2(t_vars *vars);
int					plr_move(int keycode, t_vars *vars);
void				plr_move_13(t_vars *vars);
void				plr_move_1(t_vars *vars);
void				plr_move_123(t_vars *vars);
void				plr_move_124(t_vars *vars);
void				start_sprite(t_vars *vars, double *spd, int *spo);
void				sort_sprite(t_vars *vars, double *spd, int *spo);
void				draw_sprite_position(t_vars *vars, int *spo, int i);
void				draw_sprite_hig(t_vars *vars);
void				draw_sprite_loop(t_vars *vars);
void				draw_sprite_start(t_vars *vars, int *spo);
void				draw_sprite(t_vars *vars);
void				pl_pos_fill(t_vars *vars);
void				pl_pos(t_vars *vars);
void				init_pl_pos(t_vars *vars);
void				pl_pos_fill_w(t_vars *vars, int *f);
void				pl_pos_fill_e(t_vars *vars, int *f);
void				pl_pos_fill_n(t_vars *vars, int *f);
void				pl_pos_fill_s(t_vars *vars, int *f);
void				bmpmake(t_vars *vars, unsigned char *header);
void				ft_screensave(t_vars *vars);
int					win_close(int keycode, t_vars *vars);
void				calculate_distance(t_vars *vars);
void				calculate_value_of_wallx_1(t_vars *vars);
void				calculate_value_of_wallx_ns(t_vars *vars);
void				calculate_value_of_wallx_we(t_vars *vars);
void				calculate_value_of_wallx(t_vars *vars);
void				draw_map3d(t_vars *vars);
void				ft_freee(t_vars *vars);
void				draw_cail_floor(t_vars *vars);
void				draw_map3d_1(t_vars *vars, int *hit);
void				draw_map3d_dda(t_vars *vars, int *hit);
void				pixel_put(t_vars *vars, int x, int y, unsigned int color);
void				my_mlx_p_t_put(t_vars *vars, int x,
					int y, unsigned int color);
unsigned int		my_mlx_pixel_get(t_vars *vars, int x, int y);
void				go_texture(t_vars *vars);
void				step_calculate(t_vars *vars);
void				check_pl_pos(t_vars *vars, int *f);
void				color_fill_2(char *s, int *i, t_vars *vars);
int					free_close(char *s, t_vars *vars);
void				start_parser(t_vars *vars, char **argv, int argc);
void				do_map_endfile(t_vars *vars, int i, int j, int c);
void				ft_free(t_vars *vars);

#endif
