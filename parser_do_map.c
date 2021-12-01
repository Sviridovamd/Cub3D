/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_do_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:31:47 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:31:51 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	do_map_checker_2(t_vars *vars, int *i, int *j, int *c)
{
	if (!check_null(vars, *i, *j) || vars->map_t[*i][*j] == '\n')
		free_close("Ooops!I see a hole in your map!\n", vars);
	vars->map[*c][*j] = '1';
}

void	do_map_checker_3(t_vars *vars, int *i, int *j, int *c)
{
	if (vars->have_hero == 1)
		free_close("Ooops!You already have a hero!\n", vars);
	vars->map[*c][*j] = vars->map_t[*i][*j];
	vars->have_hero = 1;
}

void	do_map_checker(t_vars *vars, int *i, int *j, int *c)
{
	while (vars->map_t[*i][*j] != '\0')
	{
		if (check_walls(vars, *i) == 0)
			free_close("Ooops!Map does not surround by walls!", vars);
		if (vars->map_t[*i][*j] == ' ' || vars->map_t[*i][*j] == '\t')
			do_map_checker_2(vars, i, j, c);
		else if (vars->map_t[*i][*j] == '1'
			|| vars->map_t[*i][*j] == '0' || vars->map_t[*i][*j] == '2')
			vars->map[*c][*j] = vars->map_t[*i][*j];
		else if (vars->map_t[*i][*j] == 'W'
			|| vars->map_t[*i][*j] == 'N' || vars->map_t[*i][*j] == 'E'
			|| vars->map_t[*i][*j] == 'S')
			do_map_checker_3(vars, i, j, c);
		else
			free_close("Ooops!invalid symbol is in map!\n", vars);
		(*j)++;
	}
}

void	do_map_2(t_vars *vars, int i)
{
	int		c;
	int		j;

	c = 0;
	while (vars->map_t[i])
	{
		j = 0;
		vars->map[c] = (char *)malloc(sizeof(char)
				* vars->len_max_string + 1);
		if (ft_strlen(vars->map_t[i]) == 0)
			do_map_endfile(vars, i, j, c);
		if (vars->map_end == 0)
		{
			do_map_checker(vars, &i, &j, &c);
			while (j < vars->len_max_string - 1)
				vars->map[c][j++] = '1';
			vars->map[c][j] = '\0';
		}
		i++;
		c++;
	}
	vars->map[c] = "\0";
	vars->map_done = 1;
}

void	do_map(t_vars *vars, int i)
{
	int		a;

	a = i;
	vars->len_max_string = ft_strlen(vars->map_t[i]);
	vars->line_in_map = vars->count_line_map_t - i;
	if (vars->line_in_map == 1 || vars->line_in_map == 0
		|| vars->line_in_map == 2)
		free_close("Ooops!it's not good map for the Game!\n", vars);
	while (vars->map_t[a + 1])
	{
		if (vars->len_max_string < ft_strlen(vars->map_t[a + 1]))
			vars->len_max_string = ft_strlen(vars->map_t[a + 1]);
		a++;
	}
	vars->map = malloc(sizeof(char *) * (vars->line_in_map + 2));
	do_map_2(vars, i);
}
