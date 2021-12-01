/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_pl_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:28:17 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:28:26 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_pl_pos(t_vars *vars, int *f)
{
	while (vars->plx < vars->len_max_string)
	{
		if (vars->map[(int)vars->ply][(int)vars->plx] == 'W')
		{
			pl_pos_fill_w(vars, f);
			break ;
		}
		else if (vars->map[(int)vars->ply][(int)vars->plx] == 'E')
		{
			pl_pos_fill_e(vars, f);
			break ;
		}
		else if (vars->map[(int)vars->ply][(int)vars->plx] == 'N')
		{
			pl_pos_fill_n(vars, f);
			break ;
		}
		else if (vars->map[(int)vars->ply][(int)vars->plx] == 'S')
		{
			pl_pos_fill_s(vars, f);
			break ;
		}
		vars->plx++;
	}
}

void	pl_pos_fill(t_vars *vars)
{
	int f;

	f = 0;
	while ((int)vars->ply < vars->line_in_map - 1)
	{
		vars->plx = 0;
		check_pl_pos(vars, &f);
		if (f)
			break ;
		vars->ply++;
	}
}

void	pl_pos(t_vars *vars)
{
	init_pl_pos(vars);
	pl_pos_fill(vars);
	vars->plx += 0.5;
	vars->ply += 0.5;
	vars->map[(int)vars->ply][(int)vars->plx] = '0';
}
