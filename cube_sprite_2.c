/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_sprite_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:29:14 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:29:16 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_sprite(t_vars *vars)
{
	int		*spriteorder;
	double	*spritedistance;

	spriteorder = (int *)malloc((vars->count_sprites + 1) * sizeof(int));
	spritedistance = (double *)malloc((vars->count_sprites + 1)
			* sizeof(double));
	texures_path(vars, vars->sp_path);
	start_sprite(vars, spritedistance, spriteorder);
	sort_sprite(vars, spritedistance, spriteorder);
	draw_sprite_start(vars, spriteorder);
	free(spriteorder);
	free(spritedistance);
}

void	draw_sprite_start(t_vars *vars, int *spo)
{
	int		i;

	i = 0;
	while (i < vars->count_sprites)
	{
		draw_sprite_position(vars, spo, i);
		draw_sprite_hig(vars);
		vars->stripe = vars->drawstartx;
		while (vars->stripe < vars->drawendx)
			draw_sprite_loop(vars);
		i++;
	}
}
