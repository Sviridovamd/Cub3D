/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:33:33 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:33:36 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int			count_sprites(t_vars *vars)
{
	int		x;
	int		y;
	int		count;

	y = 0;
	count = 0;
	while (y < vars->line_in_map)
	{
		x = 0;
		while (x < vars->len_max_string)
		{
			if (vars->map[y][x] == '2')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

t_sprite	*ft_get_sprites(t_vars *vars)
{
	int			x;
	int			y;
	int			i;
	t_sprite	*sprites;

	y = 0;
	i = 0;
	vars->count_sprites = count_sprites(vars);
	sprites = malloc(sizeof(t_sprite) * vars->count_sprites);
	while (y < vars->line_in_map - 1)
	{
		x = 0;
		while (x < vars->len_max_string)
		{
			if (vars->map[y][x] == '2')
			{
				sprites[i].y = y + 0.5;
				sprites[i++].x = x + 0.5;
			}
			x++;
		}
		y++;
	}
	return (sprites);
}
