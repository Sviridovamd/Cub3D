/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_pl_move_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:28:03 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:28:08 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_mms_20200219/mlx.h"
#include "minilibx_opengl_20191021/mlx.h"
#include "cube.h"

void	plr_move_13(t_vars *vars)
{
	if (vars->map[(int)(vars->ply)][(int)(vars->plx + vars->dirx *
	vars->movespeed)] == '0')
		vars->plx = vars->plx + vars->dirx * vars->movespeed;
	if (vars->map[(int)(vars->ply + vars->diry * vars->movespeed)]
	[(int)(vars->plx)] == '0')
		vars->ply = vars->ply + vars->diry * vars->movespeed;
	vars->move = 1;
}

void	plr_move_1(t_vars *vars)
{
	if (vars->map[(int)(vars->ply)][(int)(vars->plx - vars->dirx *
	vars->movespeed)] == '0')
		vars->plx = vars->plx - vars->dirx * vars->movespeed;
	if (vars->map[(int)(vars->ply - vars->diry * vars->movespeed)]
	[(int)(vars->plx)] == '0')
		vars->ply = vars->ply - vars->diry * vars->movespeed;
	vars->move = 1;
}

void	plr_move_123(t_vars *vars)
{
	vars->dirx = vars->dirx * cos(-(vars->rotspeed)) -
			vars->diry * sin(-(vars->rotspeed));
	vars->diry = vars->olddirx * sin(-(vars->rotspeed)) +
			vars->diry * cos(-(vars->rotspeed));
	vars->planex = vars->planex * cos(-(vars->rotspeed)) -
			vars->planey * sin(-(vars->rotspeed));
	vars->planey = vars->oldplanex * sin(-(vars->rotspeed)) +
			vars->planey * cos(-(vars->rotspeed));
	vars->move = 1;
}

void	plr_move_124(t_vars *vars)
{
	vars->dirx = vars->dirx * cos(vars->rotspeed) -
			vars->diry * sin(vars->rotspeed);
	vars->diry = vars->olddirx * sin(vars->rotspeed) +
			vars->diry * cos(vars->rotspeed);
	vars->planex = vars->planex * cos(vars->rotspeed) -
			vars->planey * sin(vars->rotspeed);
	vars->planey = vars->oldplanex * sin(vars->rotspeed) +
			vars->planey * cos(vars->rotspeed);
	vars->move = 1;
}
