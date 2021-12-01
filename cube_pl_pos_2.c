/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_pl_pos_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:28:36 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:28:39 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_mms_20200219/mlx.h"
#include "minilibx_opengl_20191021/mlx.h"
#include "cube.h"

void	init_pl_pos(t_vars *vars)
{
	vars->dirx = -1.0;
	vars->diry = 0.0;
	vars->planex = 0.0;
	vars->planey = 0.66;
	vars->ply = 0;
}

void	pl_pos_fill_w(t_vars *vars, int *f)
{
	*f = 1;
	vars->dirx = -1.0;
	vars->diry = 0.0;
	vars->planex = 0.0;
	vars->planey = -0.66;
}

void	pl_pos_fill_e(t_vars *vars, int *f)
{
	*f = 1;
	vars->dirx = 1.0;
	vars->diry = 0.0;
	vars->planex = 0.0;
	vars->planey = 0.66;
}

void	pl_pos_fill_n(t_vars *vars, int *f)
{
	*f = 1;
	vars->dirx = 0;
	vars->diry = -1;
	vars->planex = 0.66;
	vars->planey = 0.0;
}

void	pl_pos_fill_s(t_vars *vars, int *f)
{
	*f = 1;
	vars->dirx = 0;
	vars->diry = -1;
	vars->planex = 0.66;
	vars->planey = 0.0;
}
