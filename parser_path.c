/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:33:19 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:33:21 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	so_no_path(char *s, t_vars *vars, int i, int j)
{
	if (s[0] == 'N')
	{
		if (vars->have_texture_no)
			free_close("Ooops!You already have North texture!\n", vars);
		vars->n_tex_path = ft_substr(s, i, j);
		if (check_xpm(vars->n_tex_path))
			free_close("Ooops!It's not .xpm!\n", vars);
		vars->have_texture_no = 1;
	}
	else if (s[0] == 'S')
	{
		if (vars->have_texture_so)
			free_close("Ooops!You already have South texture!\n", vars);
		vars->s_tex_path = ft_substr(s, i, j);
		if (check_xpm(vars->s_tex_path))
			free_close("Ooops!It's not .xpm!\n", vars);
		vars->have_texture_so = 1;
	}
}

void	ea_we_path(char *s, t_vars *vars, int i, int j)
{
	if (s[0] == 'W')
	{
		if (vars->have_texture_we)
			free_close("Ooops!You already have West texture!\n", vars);
		vars->w_tex_path = ft_substr(s, i, j);
		check_xpm(vars->w_tex_path);
		vars->have_texture_we = 1;
	}
	else if (s[0] == 'E')
	{
		if (vars->have_texture_ea)
			free_close("Ooops!You already have East texture!\n", vars);
		vars->e_tex_path = ft_substr(s, i, j);
		check_xpm(vars->e_tex_path);
		vars->have_texture_ea = 1;
	}
}

void	sp_tex_path(char *s, t_vars *vars)
{
	int		i;
	int		j;

	i = 1;
	if (vars->have_sprite)
		free_close("Ooops!You already have Sprite!\n", vars);
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	j = i;
	while (s[j] != ' ' && s[j] != '\0')
		j++;
	vars->sp_path = ft_substr(s, i, j);
	check_xpm(vars->sp_path);
	vars->have_sprite = 1;
	while (s[j] == ' ' || s[j] == '\t')
		j++;
	if (s[j])
		free_close("Ooops!It's illegal in sprite path!\n", vars);
}

void	tex_path(char *s, t_vars *vars)
{
	int		i;
	int		j;

	i = 2;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	j = i;
	while (s[j] != ' ' && s[j] != '\0')
		j++;
	so_no_path(s, vars, i, j);
	ea_we_path(s, vars, i, j);
	while (s[j] == ' ' || s[j] == '\t')
		j++;
	if (s[j])
		free_close("Ooops!It's illegal in a path\n", vars);
}

void	check_all_path(t_vars *vars)
{
	check_open_file(vars);
	if (vars->maph > 1440)
		vars->maph = 1440;
	if (vars->mapw > 2560)
		vars->mapw = 2560;
	if (vars->maph < 1 || vars->mapw < 1)
		free_close("Ooops!it's not good resolution for the Game!\n", vars);
}
