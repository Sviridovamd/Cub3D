/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_distans.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:26:56 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:27:02 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	calculate_distance(t_vars *vars)
{
	if (vars->side == 0)
		vars->perpwalldist = (vars->mapx - vars->plx +
				(1 - (double)vars->stepx) / 2) / vars->raydirx;
	else
		vars->perpwalldist = (vars->mapy - vars->ply +
				(1 - (double)vars->stepy) / 2) / vars->raydiry;
	vars->perpwalldist = vars->perpwalldist == 0 ? 0.1 : vars->perpwalldist;
	vars->lineheight = (int)(vars->maph / vars->perpwalldist);
	vars->drawstart = -vars->lineheight / 2 + vars->maph / 2;
	if (vars->drawstart < 0)
		vars->drawstart = 0;
	vars->drawend = vars->lineheight / 2 + vars->maph / 2;
	if (vars->drawend >= vars->maph)
		vars->drawend = vars->maph;
}

void	calculate_value_of_wallx_1(t_vars *vars)
{
	if (vars->side == 0)
	{
		if (vars->raydirx > 0)
			vars->walldir = 'N';
		else
			vars->walldir = 'S';
		vars->wallx = vars->ply + vars->perpwalldist * vars->raydiry;
		vars->texx = TEXWIDTH - vars->texx - 1;
	}
	else
	{
		if (vars->raydiry > 0)
			vars->walldir = 'W';
		else
			vars->walldir = 'E';
		vars->wallx = vars->plx + vars->perpwalldist * vars->raydirx;
		vars->texx = TEXHEIGHT - vars->texx - 1;
	}
}

void	calculate_value_of_wallx_ns(t_vars *vars)
{
	if (vars->walldir == 'N')
	{
		vars->tex->t_addr = mlx_get_data_addr(vars->n_tex,
										&vars->tex->t_bpp, &vars->tex->t_lnl,
										&vars->tex->t_endian);
		vars->tex->c_addr = mlx_get_data_addr(vars->tex->content,
										&vars->tex->c_bpp, &vars->tex->c_lnl,
										&vars->tex->c_endian);
	}
	else if (vars->walldir == 'S')
	{
		vars->tex->t_addr = mlx_get_data_addr(vars->s_tex,
										&vars->tex->t_bpp, &vars->tex->t_lnl,
										&vars->tex->t_endian);
		vars->tex->c_addr = mlx_get_data_addr(vars->tex->content,
										&vars->tex->c_bpp, &vars->tex->c_lnl,
										&vars->tex->c_endian);
	}
}

void	calculate_value_of_wallx_we(t_vars *vars)
{
	if (vars->walldir == 'W')
	{
		vars->tex->t_addr = mlx_get_data_addr(vars->w_tex,
										&vars->tex->t_bpp, &vars->tex->t_lnl,
										&vars->tex->t_endian);
		vars->tex->c_addr = mlx_get_data_addr(vars->tex->content,
										&vars->tex->c_bpp, &vars->tex->c_lnl,
										&vars->tex->c_endian);
	}
	else if (vars->walldir == 'E')
	{
		vars->tex->t_addr = mlx_get_data_addr(vars->e_tex,
										&vars->tex->t_bpp, &vars->tex->t_lnl,
										&vars->tex->t_endian);
		vars->tex->c_addr = mlx_get_data_addr(vars->tex->content,
										&vars->tex->c_bpp, &vars->tex->c_lnl,
										&vars->tex->c_endian);
	}
}

void	calculate_value_of_wallx(t_vars *vars)
{
	vars->texx = (int)(vars->wallx * (double)TEXWIDTH);
	calculate_value_of_wallx_1(vars);
	if (vars->walldir == 'E' || vars->walldir == 'N')
		vars->wallx -= floor(vars->wallx);
	if (vars->walldir == 'S' || vars->walldir == 'W')
		vars->wallx = 1 - (vars->wallx - floor(vars->wallx));
	calculate_value_of_wallx_ns(vars);
	calculate_value_of_wallx_we(vars);
	vars->step = 1.0 * TEXHEIGHT / vars->lineheight;
	vars->texpos = (vars->drawstart - vars->maph / 2 + vars->lineheight / 2)
			* vars->step;
	vars->y = vars->drawstart;
}
