/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:30:52 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:42:04 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		checker_save(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] == 'e' && s[i - 2] == 'v' && s[i - 3] == 'a'
		&& s[i - 4] == 's' && s[i - 5] == '-' && s[i - 6] == '-')
		return (1);
	return (0);
}

int		checker_name(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] == 'b' && s[i - 2] == 'u' && s[i - 3] == 'c'
		&& s[i - 4] == '.')
		return (1);
	return (0);
}

int		check_xpm(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] != 'm' || s[i - 2] != 'p'
		|| s[i - 3] != 'x' || s[i - 4] != '.')
		return (1);
	return (0);
}

int		check_exist_path(char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	close(fd);
	return (fd);
}

void	check_open_file(t_vars *vars)
{
	if (check_exist_path(vars->n_tex_path) == -1)
		free_close("Ooops!I don't see file with North texture!", vars);
	if (check_exist_path(vars->s_tex_path) == -1)
		free_close("Ooops!I don't see file with South texture!", vars);
	if (check_exist_path(vars->w_tex_path) == -1
		|| check_exist_path(vars->e_tex_path) == -1)
		free_close("Ooops!I don't see file with East or West texture!", vars);
	if (check_exist_path(vars->sp_path) == -1)
		free_close("Ooops!I don't see file with Sprite texture!", vars);
}
