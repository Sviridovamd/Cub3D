/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_liba.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:32:40 by wmadison          #+#    #+#             */
/*   Updated: 2021/03/22 19:32:42 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)s + i) = '\0';
		i++;
	}
}

int		ft_atoi(const char *str)
{
	int		i;
	int		n;
	int		num;

	i = 0;
	n = 1;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9' && str[i] != '\0')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * n);
}

char	*ft_strlcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	if (!dst)
		return (0);
	{
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}

int		ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}
