/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:34:20 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:34:23 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*ft_createnewline(char *buf, char *rem)
{
	char *tmp;

	if (rem)
	{
		tmp = ft_strjoin(rem, buf);
		free(rem);
		rem = NULL;
		rem = ft_strdup(tmp);
		free(tmp);
	}
	else
		rem = ft_strdup(buf);
	return (rem);
}

char	*ft_strrchr(const char *str, int ch)
{
	char *copy;

	if (str == NULL)
		return (0);
	copy = (char*)str;
	while (*copy != '\0')
	{
		if (*copy == ch)
			return (copy);
		copy++;
	}
	if (*copy == ch && ch == '\0')
		return (copy);
	return (NULL);
}

char	*ft_get_line(char *rem, char **line, int howmuchread)
{
	int		n;
	char	*tmp;

	(void)howmuchread;
	n = 0;
	while (rem[n] != '\n' && rem[n] != '\0')
		n++;
	if (n < ft_strlen(rem))
	{
		*line = ft_substr(rem, 0, n);
		tmp = ft_substr(rem, n + 1, ft_strlen(rem));
		free(rem);
		rem = NULL;
		rem = ft_strdup(tmp);
		free(tmp);
	}
	else
	{
		*line = ft_strdup(rem);
		free(rem);
		rem = NULL;
	}
	return (rem);
}

int		get_next_line(int fd, char **line)
{
	int			howmuchread;
	char		*buf;
	static char *rem;

	if (!line || fd < 0 || BUFFER_SIZE < 1
	|| !(buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	howmuchread = 1;
	while (howmuchread && !(ft_strrchr(rem, '\n')))
	{
		howmuchread = read(fd, buf, BUFFER_SIZE);
		if (howmuchread == -1)
			return (-1);
		buf[howmuchread] = '\0';
		rem = ft_createnewline(buf, rem);
	}
	free(buf);
	rem = ft_get_line(rem, line, howmuchread);
	if (howmuchread == 0 && !rem)
		return (0);
	return (1);
}
