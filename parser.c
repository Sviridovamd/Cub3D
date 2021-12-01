/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:30:00 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:30:03 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_for_parser(t_vars *vars, int i)
{
	check_all_have_map(vars);
	check_all_path(vars);
	vars->first_line_map = i;
	do_map(vars, --i);
	vars->sprites = ft_get_sprites(vars);
}

void	parser(t_vars *vars, char *file)
{
	int		fd;
	int		i;
	int		rt;

	init_vars_map(vars);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		free_close("Ooops!Map file does not exist!", vars);
	i = 0;
	rt = 0;
	vars->count_line_map_t = count_line_map(file);
	vars->map_t = malloc(sizeof(char *) * (vars->count_line_map_t + 1));
	create_map_t(vars, fd);
	while (!rt && i <= vars->count_line_map_t - 1)
	{
		rt = parser_map_t(vars, vars->map_t[i]);
		i++;
	}
	if (!rt)
		free_close("Ooops!You forgot the map!", vars);
	check_for_parser(vars, i);
	if (vars->have_hero == 0)
		free_close("Ooops!You don't have a hero!", vars);
}
