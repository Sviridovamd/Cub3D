/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:31:22 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:31:31 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_count_color(t_vars *vars, int count, char *s)
{
	if (count == 1)
	{
		if (s[0] == 'C')
			vars->ceiling_color_r = vars->tmp_color;
		else
			vars->floor_color_r = vars->tmp_color;
		vars->tmp_color = 0;
	}
	if (count == 2)
	{
		if (s[0] == 'C')
			vars->ceiling_color_g = vars->tmp_color;
		else
			vars->floor_color_g = vars->tmp_color;
		vars->tmp_color = 0;
	}
	if (count == 3)
	{
		if (s[0] == 'C')
			vars->ceiling_color_b = vars->tmp_color;
		else
			vars->floor_color_b = vars->tmp_color;
	}
}

void	color_fill_2(char *s, int *i, t_vars *vars)
{
	while (s[*i] == ' ' || s[*i] == '\t')
		(*i)++;
	if (!ft_isdigit(s[*i]) || ft_atoi(s + *i) > 255)
		free_close("Invalid color input!\n", vars);
	while (ft_isdigit(s[*i]))
	{
		vars->tmp_color = (vars->tmp_color * 10) + (s[*i] - '0');
		(*i)++;
	}
}

void	color_fill(char *s, int *i, t_vars *vars)
{
	int		count;

	count = 0;
	vars->tmp_color = 0;
	vars->count_colors = 0;
	while (count < 3)
	{
		color_fill_2(s, i, vars);
		count++;
		check_count_color(vars, count, s);
		while (s[*i] == ' ' || s[*i] == '\t')
			(*i)++;
		if (s[*i] == ',')
		{
			vars->count_colors++;
			(*i)++;
		}
	}
}

void	color_pars_2(char *s, t_vars *vars)
{
	if (s[0] == 'C')
	{
		if (vars->have_ceiling)
			free_close("Ceiling color already defined!\n", vars);
		vars->have_ceiling = 1;
	}
	else
	{
		if (vars->have_floor)
			free_close("Floor color already defined!\n", vars);
		vars->have_floor = 1;
	}
}

void	color_pars(char *s, t_vars *vars)
{
	int		i;

	vars->tmp_color = 0;
	vars->count_colors = 0;
	i = 1;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	color_fill(s, &i, vars);
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (vars->count_colors != 2 || s[i])
		free_close("Invalid color input!\n", vars);
	color_pars_2(s, vars);
}
