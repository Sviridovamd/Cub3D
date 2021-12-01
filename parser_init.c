/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:32:18 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:32:25 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_vars_map(t_vars *vars)
{
	vars->mapw = 0;
	vars->maph = 0;
	vars->n_tex_path = NULL;
	vars->s_tex_path = NULL;
	vars->e_tex_path = NULL;
	vars->w_tex_path = NULL;
	vars->sp_path = NULL;
	vars->ceiling_color = 0;
	vars->floor_color = 0;
	vars->map_t = NULL;
	vars->map = NULL;
	vars->have_resolution = 0;
	vars->have_texture_no = 0;
	vars->have_texture_so = 0;
	vars->have_texture_ea = 0;
	vars->have_texture_we = 0;
	vars->have_hero = 0;
	vars->have_sprite = 0;
	vars->have_floor = 0;
	vars->have_ceiling = 0;
	vars->first_line_map = 0;
	vars->line_in_map = 0;
	vars->map_end = 0;
	vars->map_done = 0;
}

void	do_map_endfile(t_vars *vars, int i, int j, int c)
{
	if (!null_end_line(vars, i, j))
		free_close("Ooops!Map does not surround by walls!\n", vars);
	while (i < vars->count_line_map_t)
	{
		if (!check_two_maps(vars->map_t[i]))
			free_close("Ooops!You have two maps!\n", vars);
		i++;
	}
	vars->line_in_map = c;
	vars->map_end = 2;
}

void	ft_freee(t_vars *vars)
{
	(void)vars;
}
