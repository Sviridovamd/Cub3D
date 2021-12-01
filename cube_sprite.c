/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:29:02 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:29:05 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	start_sprite(t_vars *vars, double *spd, int *spo)
{
	int		i;

	i = 0;
	while (i < vars->count_sprites)
	{
		spo[i] = i;
		spd[i] = ((vars->plx - vars->sprites[i].x)
				* (vars->plx - vars->sprites[i].x)
				+ (vars->ply - vars->sprites[i].y)
				* (vars->ply - vars->sprites[i].y));
		i++;
	}
}

void	sort_sprite(t_vars *vars, double *spd, int *spo)
{
	int		i;
	int		j;

	i = 0;
	while (i < vars->count_sprites - 1)
	{
		j = 0;
		while (j < vars->count_sprites - i - 1)
		{
			if (spd[j] < spd[j + 1])
			{
				vars->dist_tmp = spd[j];
				spd[j] = spd[j + 1];
				spd[j + 1] = vars->dist_tmp;
				vars->tmp = spo[j];
				spo[j] = spo[j + 1];
				spo[j + 1] = vars->tmp;
			}
			j++;
		}
		i++;
	}
}

void	draw_sprite_position(t_vars *vars, int *spo, int i)
{
	vars->spritex = vars->sprites[spo[i]].x - vars->plx;
	vars->spritey = vars->sprites[spo[i]].y - vars->ply;
	vars->invdet = 1.0 / (vars->planex * vars->diry - vars->dirx *
			vars->planey);
	vars->transformx = vars->invdet * (vars->diry * vars->spritex -
			vars->dirx * vars->spritey);
	vars->transformy = vars->invdet * (-vars->planey * vars->spritex +
			vars->planex * vars->spritey);
	vars->spritescreenx = (int)((vars->mapw / 2) * (1 + vars->transformx /
			vars->transformy));
}

void	draw_sprite_hig(t_vars *vars)
{
	vars->spriteheight = abs((int)(vars->maph / (vars->transformy)));
	vars->drawstarty = -(vars->spriteheight) / 2 + vars->maph / 2;
	if (vars->drawstarty < 0)
		vars->drawstarty = 0;
	vars->drawendy = vars->spriteheight / 2 + vars->maph / 2;
	if (vars->drawendy >= vars->maph)
		vars->drawendy = vars->maph - 1;
	vars->spritewidth = abs((int)(vars->mapw / (vars->transformy)));
	vars->drawstartx = -(vars->spritewidth) / 2 + vars->spritescreenx;
	if (vars->drawstartx < 0)
		vars->drawstartx = 0;
	vars->drawendx = vars->spritewidth / 2 + vars->spritescreenx;
	if (vars->drawendx >= vars->mapw)
		vars->drawendx = vars->mapw - 1;
}

void	draw_sprite_loop(t_vars *vars)
{
	int		y;
	int		d;

	vars->texx_s = (int)(256 * (vars->stripe - (-(vars->spritewidth)
					/ 2 + vars->spritescreenx))
			* TEXWIDTH / vars->spritewidth) / 256;
	y = vars->drawstarty;
	if (vars->transformy > 0 && vars->stripe > 0
		&& (vars->stripe < vars->mapw && vars->transformy)
		&& (vars->transformy < vars->zbuffer[vars->stripe]))
	{
		while (y < vars->drawendy)
		{
			d = y * 256 - vars->maph * 128 + vars->spriteheight * 128;
			vars->texy_s = ((d * TEXHEIGHT) / vars->spriteheight) / 256;
			vars->color = my_mlx_pixel_get(vars, vars->texx_s, vars->texy_s);
			if (vars->color != 0)
				my_mlx_p_t_put(vars, vars->stripe, y, vars->color);
			y++;
		}
	}
	vars->stripe++;
}
