/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cheak_have.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:30:16 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:30:18 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_path_continuation(t_vars *vars, char *line_map, int *i)
{
	while (ft_isdigit(line_map[*i]))
	{
		vars->mapw = (vars->mapw * 10) + (line_map[*i] - '0');
		(*i)++;
	}
	while (line_map[*i] == ' ' || line_map[*i] == '\t')
		(*i)++;
	if (!ft_isdigit(line_map[*i]))
		free_close("Ooops!It's not good resolution for Game!\n", vars);
	while (ft_isdigit(line_map[*i]))
	{
		vars->maph = (vars->maph * 10) + (line_map[*i] - '0');
		(*i)++;
	}
	while (line_map[*i] == ' ' || line_map[*i] == '\t')
		(*i)++;
}

void	check_path(char *line_map, t_vars *vars)
{
	int		i;

	i = 1;
	while (line_map[i] == ' ' || line_map[i] == '\t')
		i++;
	if (vars->have_resolution)
		free_close("Ooops!You already had resolution!\n", vars);
	if (!ft_isdigit(line_map[i]))
		free_close("Ooops!It's not good resolution for Game!\n", vars);
	check_path_continuation(vars, line_map, &i);
	if (line_map[i])
		free_close("Ooops!It's not good resolution for Game!\n", vars);
	vars->have_resolution = 1;
}

void	check_all_have_map_2(t_vars *vars)
{
	if (!vars->have_texture_we || !vars->have_texture_ea)
		free_close("Ooops!Sorry!You don't have enough texture for Game!\n",
			vars);
	else if (!vars->have_floor || !vars->have_ceiling)
		free_close("Ooops!Sorry!You don't have enough colors for Game!\n",
			vars);
	else if (!vars->have_sprite)
		free_close("Ooops!Sorry!You don't have sprite's texture for Game!\n",
			vars);
}

void	check_all_have_map(t_vars *vars)
{
	if (!vars->have_resolution)
		free_close("Ooops!Sorry!You don't have enough texture for Game!\n",
			vars);
	else if (!vars->have_texture_no)
		free_close("Ooops!Sorry!You don't have enough texture for Game!\n",
			vars);
	else if (!vars->have_texture_so)
		free_close("Ooops!Sorry!You don't have enough texture for Game!\n",
			vars);
	check_all_have_map_2(vars);
}
