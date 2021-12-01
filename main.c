/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:29:40 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:29:43 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	start_parser(t_vars *vars, char **argv, int argc)
{
	if (argc == 2 && checker_name(argv[1]))
		parser(vars, argv[1]);
	else if (argc == 3 && checker_name(argv[1]) && checker_save(argv[2]))
	{
		parser(vars, argv[1]);
		vars->save = 1;
	}
	else
		free_close("Ooops!Invalid arguments!", vars);
}

int		render_next_frame(t_vars *vars)
{
	if (vars->move == 1)
	{
		vars->tex->content = mlx_new_image(vars->win->mlx,
				vars->mapw, vars->maph);
		vars->tex->c_addr = mlx_get_data_addr(vars->tex->content,
				&vars->tex->c_bpp, &vars->tex->c_lnl, &vars->tex->c_endian);
		draw_cail_floor(vars);
		draw_map3d(vars);
		vars->move = 0;
		draw_sprite(vars);
		if (vars->save == 0)
			mlx_put_image_to_window(vars->win->mlx, vars->win->win_mlx,
				vars->tex->content, 0, 0);
		mlx_destroy_image(vars->win->mlx, vars->tex->content);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_vars	vars;

	game_init(&vars);
	start_parser(&vars, argv, argc);
	game_init_2(&vars);
	vars.win->mlx = mlx_init();
	go_texture(&vars);
	if (vars.save == 0)
	{
		vars.win->win_mlx = mlx_new_window(vars.win->mlx,
				vars.mapw, vars.maph, "Cube3D");
		mlx_hook(vars.win->win_mlx, 2, 1L << 0, plr_move, &vars);
		mlx_hook(vars.win->win_mlx, 17, 1L << 0, win_close, &vars);
		mlx_loop_hook(vars.win->mlx, render_next_frame, &vars);
		mlx_loop(vars.win->mlx);
	}
	if (vars.save == 1)
		ft_screensave(&vars);
	return (0);
}
