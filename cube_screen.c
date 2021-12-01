/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:28:50 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:28:53 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	bmpmake(t_vars *vars, unsigned char *header)
{
	ft_bzero(header, 54);
	header[0] = 'B';
	header[1] = 'M';
	header[2] = (vars->mapw * vars->maph * 4 + 54);
	header[3] = (vars->mapw * vars->maph * 4 + 54) >> 8;
	header[4] = (vars->mapw * vars->maph * 4 + 54) >> 16;
	header[5] = (vars->mapw * vars->maph * 4 + 54) >> 24;
	header[10] = 54;
	header[14] = 40;
	header[18] = vars->mapw;
	header[19] = vars->mapw >> 8;
	header[20] = vars->mapw >> 16;
	header[21] = vars->mapw >> 24;
	header[22] = (vars->maph);
	header[23] = vars->maph >> 8;
	header[24] = vars->maph >> 16;
	header[25] = vars->maph >> 24;
	header[26] = 1;
	header[28] = 32;
}

void	ft_screensave(t_vars *vars)
{
	int				fd;
	int				i;
	int				j;
	unsigned char	buf[54];

	render_next_frame(vars);
	bmpmake(vars, buf);
	fd = open("screenshot.bmp", O_CREAT | O_TRUNC | O_WRONLY, S_IRWXU);
	write(fd, buf, 54);
	i = vars->maph - 1;
	j = (vars->tex->c_bpp / 8) * vars->mapw;
	while (i >= 0)
	{
		write(fd, &vars->tex->c_addr[i * vars->tex->c_lnl], j);
		i--;
	}
	close(fd);
	exit(0);
}
