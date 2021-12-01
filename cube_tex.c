/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:29:26 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:29:29 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	texures_path(t_vars *vars, char *path)
{
	vars->tex->tex = mlx_xpm_file_to_image(vars->win->mlx,
			path, &vars->tex->img_w, &vars->tex->img_h);
	vars->tex->t_addr = mlx_get_data_addr(vars->tex->tex,
			&vars->tex->t_bpp, &vars->tex->t_lnl, &vars->tex->t_endian);
	vars->tex->c_addr = mlx_get_data_addr(vars->tex->content,
			&vars->tex->c_bpp, &vars->tex->c_lnl, &vars->tex->c_endian);
}

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	go_texture(t_vars *vars)
{
	vars->n_tex = mlx_xpm_file_to_image(vars->win->mlx, vars->n_tex_path,
			&vars->n_width, &vars->n_height);
	vars->s_tex = mlx_xpm_file_to_image(vars->win->mlx, vars->s_tex_path,
			&vars->s_width, &vars->s_height);
	vars->w_tex = mlx_xpm_file_to_image(vars->win->mlx, vars->w_tex_path,
			&vars->w_width, &vars->w_height);
	vars->e_tex = mlx_xpm_file_to_image(vars->win->mlx, vars->e_tex_path,
			&vars->e_width, &vars->e_height);
	vars->sp_tex = mlx_xpm_file_to_image(vars->win->mlx, vars->sp_path,
			&vars->sp_width, &vars->sp_height);
}

void	game_init(t_vars *vars)
{
	vars->wall_size = 10;
	vars->win = malloc(sizeof(t_win));
	vars->tex = malloc(sizeof(t_tex));
	vars->save = 0;
	vars->map = NULL;
	vars->map_t = NULL;
}

void	game_init_2(t_vars *vars)
{
	vars->move = 1;
	vars->zbuffer = malloc((sizeof(double) * vars->mapw) + 1);
	vars->ceiling_color = create_trgb(0, vars->ceiling_color_r,
			vars->ceiling_color_g, vars->ceiling_color_b);
	vars->floor_color = create_trgb(0, vars->floor_color_r,
			vars->floor_color_g, vars->floor_color_b);
	pl_pos(vars);
}
