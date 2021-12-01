/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_pl_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:27:39 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:40:33 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_plr_move(t_vars *vars)
{
	vars->movespeed = 0.5;
	vars->rotspeed = 0.1;
	vars->olddirx = vars->dirx;
	vars->oldplanex = vars->planex;
}

void	plr_move_0(t_vars *vars)
{
	if (vars->map[(int)(vars->ply)][(int)(vars->plx -
	vars->planex * vars->movespeed)] == '0')
		vars->plx = vars->plx - vars->planex * vars->movespeed;
	if (vars->map[(int)(vars->ply - vars->planey * vars->movespeed)]
	[(int)(vars->plx)] == '0')
		vars->ply = vars->ply - vars->planey * vars->movespeed;
	vars->move = 1;
}

void	plr_move_2(t_vars *vars)
{
	if (vars->map[(int)(vars->ply)][(int)(vars->plx +
	vars->planex * vars->movespeed)] == '0')
		vars->plx = vars->plx + vars->planex * vars->movespeed;
	if (vars->map[(int)(vars->ply + vars->planey * vars->movespeed)]
	[(int)(vars->plx)] == '0')
		vars->ply = vars->ply + vars->planey * vars->movespeed;
	vars->move = 1;
}

int		plr_move(int keycode, t_vars *vars)
{
	init_plr_move(vars);
	if (keycode == 13)
		plr_move_13(vars);
	if (keycode == 1)
		plr_move_1(vars);
	if (keycode == 123)
		plr_move_123(vars);
	if (keycode == 124)
		plr_move_124(vars);
	if (keycode == 0)
		plr_move_0(vars);
	if (keycode == 2)
		plr_move_2(vars);
	if (keycode == 53)
	{
		ft_freee(vars);
		mlx_destroy_window(vars->win->mlx, vars->win->win_mlx);
		exit(0);
	}
	return (0);
}
