/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:26:39 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:26:44 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_free(t_vars *vars)
{
	int i;

	i = 0;
	if (vars->map_done)
	{
		if (vars->map)
		{
			while (vars->map[i])
				free(vars->map[i++]);
			free(vars->map);
		}
	}
	if (vars->map_t)
	{
		while (vars->map_t[i])
			free(vars->map_t[i++]);
		free(vars->map_t);
	}
	if (vars->zbuffer)
		free(vars->zbuffer);
	free(vars->win);
	free(vars->tex);
}

int		free_close(char *s, t_vars *vars)
{
	write(2, "Error\n", 6);
	perror(s);
	ft_free(vars);
	exit(2);
}

int		win_close(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	ft_freee(vars);
	exit(0);
}
