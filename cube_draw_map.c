/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_draw_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:27:10 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:27:13 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_mms_20200219/mlx.h"
#include "minilibx_opengl_20191021/mlx.h"
#include "cube.h"

void	draw_map3d(t_vars *vars)
{
	int hit;

	hit = 0;
	vars->x = 0;
	while (vars->x < vars->mapw)
	{
		draw_map3d_1(vars, &hit);
		while (hit == 0)
			draw_map3d_dda(vars, &hit);
		calculate_distance(vars);
		calculate_value_of_wallx(vars);
		while (vars->y < vars->drawend)
		{
			vars->texy = (int)vars->texpos & (TEXHEIGHT - 1);
			vars->texpos += vars->step;
			vars->color = my_mlx_pixel_get(vars, vars->texx, vars->texy);
			my_mlx_p_t_put(vars, vars->x, vars->y, vars->color);
			vars->y++;
		}
		vars->zbuffer[vars->x] = vars->perpwalldist;
		vars->x++;
	}
}

void	draw_cail_floor(t_vars *vars)
{
	int x;
	int y;

	y = 0;
	while (y < vars->maph / 2)
	{
		x = 0;
		while (x < vars->mapw)
			my_mlx_p_t_put(vars, x++, y, vars->ceiling_color);
		y++;
	}
	y = vars->maph / 2;
	while (y < vars->maph)
	{
		x = 0;
		while (x < vars->mapw)
			my_mlx_p_t_put(vars, x++, y, vars->floor_color);
		y++;
	}
}

void	step_calculate(t_vars *vars)
{
	if (vars->raydirx < 0)
	{
		vars->stepx = -1;
		vars->sidedistx = (vars->plx - vars->mapx) * vars->deltadistx;
	}
	else
	{
		vars->stepx = 1;
		vars->sidedistx = (vars->mapx + 1.0 - vars->plx) * vars->deltadistx;
	}
	if (vars->raydiry < 0)
	{
		vars->stepy = -1;
		vars->sidedisty = (vars->ply - vars->mapy) * vars->deltadisty;
	}
	else
	{
		vars->stepy = 1;
		vars->sidedisty = (vars->mapy + 1.0 - vars->ply) * vars->deltadisty;
	}
}

void	draw_map3d_1(t_vars *vars, int *hit)
{
	vars->camerax = 2 * vars->x / (double)vars->mapw - 1;
	vars->raydirx = vars->dirx + vars->planex * vars->camerax;
	vars->raydiry = vars->diry + vars->planey * vars->camerax;
	vars->mapx = (int)vars->plx;
	vars->mapy = (int)vars->ply;
	if (vars->raydiry == 0)
		vars->deltadistx = 0;
	else
	{
		if (vars->raydirx == 0)
			vars->deltadistx = 1;
		else
			vars->deltadistx = fabs(1 / vars->raydirx);
	}
	if (vars->raydirx == 0)
		vars->deltadisty = 0;
	else
	{
		if (vars->raydiry == 0)
			vars->deltadisty = 1;
		else
			vars->deltadisty = fabs(1 / vars->raydiry);
	}
	*hit = 0;
	step_calculate(vars);
}

void	draw_map3d_dda(t_vars *vars, int *hit)
{
	if (vars->sidedistx < vars->sidedisty)
	{
		vars->sidedistx += vars->deltadistx;
		vars->mapx += vars->stepx;
		vars->side = 0;
	}
	else
	{
		vars->sidedisty += vars->deltadisty;
		vars->mapy += vars->stepy;
		vars->side = 1;
	}
	if (vars->map[vars->mapy][vars->mapx] == '1')
		*hit = 1;
}
