/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cheak_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:30:28 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:30:31 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_line(t_vars *vars, int i)
{
	int		j;

	j = 0;
	while (vars->map_t[i][j])
	{
		if (vars->map_t[i][j] != ' ' && vars->map_t[i][j] != '1'
			&& i == vars->count_line_map_t - 1)
			return (0);
		else if (vars->map_t[i][j] != ' ' && vars->map_t[i][j] != '1'
			&& i == vars->first_line_map - 1)
			return (0);
		else if (vars->map_t[i][j] == ' ' && i == vars->first_line_map - 1)
		{
			if (vars->map_t[i + 1][j] != '1' && vars->map_t[i + 1][j] != ' ')
				return (0);
		}
		else if (vars->map_t[i][j] == ' ' && i == vars->count_line_map_t - 1)
		{
			if (vars->map_t[i - 1][j] != '1' && vars->map_t[i - 1][j] != ' ')
				return (0);
		}
		j++;
	}
	return (1);
}

int	check_walls(t_vars *vars, int i)
{
	int		j;

	j = 0;
	if (i == vars->first_line_map - 1 || i == vars->count_line_map_t - 1)
	{
		if (!check_line(vars, i))
			return (0);
	}
	while (vars->map_t[i][j] == ' ' || vars->map_t[i][j] == '\t')
		j++;
	if (vars->map_t[i][j] != '1')
		return (0);
	if (vars->map_t[i][(ft_strlen(vars->map_t[i]) - 1)] != '1'
		&& vars->map_t[i][(ft_strlen(vars->map_t[i]) - 1)] != ' ')
		return (0);
	return (1);
}

int	check_null(t_vars *vars, int i, int j)
{
	if (i == vars->count_line_map_t - 1 || i == vars->first_line_map - 1
		|| j == 0 || j == vars->len_max_string - 1)
		return (1);
	else if (vars->map_t[i + 1][j] == '0')
		return (0);
	else if (vars->map_t[i - 1][j] == '0')
		return (0);
	else if (vars->map_t[i][j - 1] == '0')
		return (0);
	else if (vars->map_t[i][j + 1] == '0')
		return (0);
	return (1);
}

int	check_two_maps(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else
			return (0);
	}
	return (1);
}

int	null_end_line(t_vars *vars, int i, int j)
{
	i--;
	while (vars->map_t[i][j])
	{
		if (vars->map_t[i][j] != '1' && vars->map_t[i][j] != ' ')
			return (0);
		j++;
	}
	return (1);
}
