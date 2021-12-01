/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:27:23 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:27:26 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_mms_20200219/mlx.h"
#include "minilibx_opengl_20191021/mlx.h"
#include "cube.h"

void			pixel_put(t_vars *vars, int x, int y, unsigned int color)
{
	char *dst;

	dst = vars->win->addr +
			(y * vars->win->line_length + x * (vars->win->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void			my_mlx_p_t_put(t_vars *vars, int x, int y, unsigned int color)
{
	char *dst;

	dst = vars->tex->c_addr +
			(y * vars->tex->c_lnl + x * (vars->tex->c_bpp / 8));
	*(unsigned int*)dst = color;
}

unsigned int	my_mlx_pixel_get(t_vars *vars, int x, int y)
{
	char *dst;

	dst = vars->tex->t_addr + (y * vars->tex->t_lnl + x *
			(vars->tex->t_bpp / 8));
	return (*(unsigned int*)dst);
}
