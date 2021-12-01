/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:32:53 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:32:56 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	create_map_t(t_vars *vars, int fd)
{
	char	*line;
	int		i;
	int		read;

	read = 1;
	i = 0;
	while (read)
	{
		read = get_next_line(fd, &line);
		vars->map_t[i] = malloc((ft_strlen(line) + 1) * sizeof(char));
		vars->map_t[i] = ft_strlcpy(vars->map_t[i], line);
		free(line);
		line = 0;
		i++;
	}
	free(line);
	line = 0;
	vars->map_t[i] = 0;
}

int		count_line_map(char *file)
{
	char	*line;
	int		fd;
	int		read;
	int		count;

	count = 0;
	fd = open(file, O_RDONLY);
	while ((read = get_next_line(fd, &line)))
	{
		count++;
		free(line);
	}
	close(fd);
	free(line);
	return (count + 1);
}

int		parser_map_t_2(t_vars *vars, char *s, int i)
{
	if (s[i] == 'R' && (s[i + 1]) == ' ')
		check_path(s + i, vars);
	else if (s[i] == 'N' && s[i + 1] == 'O' && s[i + 2] == ' ')
		tex_path(s + i, vars);
	else if (s[i] == 'S' && s[i + 1] == 'O' && s[i + 2] == ' ')
		tex_path(s + i, vars);
	else if (s[i] == 'W' && s[i + 1] == 'E' && s[i + 2] == ' ')
		tex_path(s + i, vars);
	else if (s[i] == 'E' && s[i + 1] == 'A' && s[i + 2] == ' ')
		tex_path(s + i, vars);
	else if (s[i] == 'S' && s[i + 1] == ' ')
		sp_tex_path(s + i, vars);
	else if (s[i] == 'F' && s[i + 1] == ' ')
		color_pars(s + i, vars);
	else if (s[i] == 'C' && s[i + 1] == ' ')
		color_pars(s + i, vars);
	else if (s[i] == '1' || s[i] == ' ' || s[i] == '2')
		return (1);
	else
		free_close("Ooops!Something went wrong!(invalid identifier)", vars);
	return (0);
}

int		parser_map_t(t_vars *vars, char *line_map)
{
	int		i;

	i = 0;
	while (line_map[i] == ' ' || line_map[i] == '\t')
		i++;
	if (line_map[i] == '\0')
		return (0);
	if (parser_map_t_2(vars, line_map, i))
		return (1);
	return (0);
}
