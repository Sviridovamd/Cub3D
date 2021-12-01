/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:48:52 by wmadison          #+#    #+#             */
/*   Updated: 2020/12/17 18:52:35 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	sizes1;
	size_t	size;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	sizes1 = ft_strlen(s1);
	size = sizes1 + ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * size + 1);
	if (!new)
		return (NULL);
	while (i < sizes1)
	{
		new[i] = *s1++;
		i++;
	}
	while (i < size)
	{
		new[i] = *s2++;
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*p;

	len = 0;
	while (src[len] != '\0')
		len++;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	len = 0;
	while (src[len] != '\0')
	{
		p[len] = src[len];
		len++;
	}
	p[len] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	substring = (char *)malloc(sizeof(char) * (len - start + 1));
	if (!substring)
		return (NULL);
	if ((size_t)ft_strlen((char *)s) > start)
		while ((start + i) < len)
		{
			substring[i] = s[start + i];
			i++;
		}
	substring[i] = '\0';
	return (substring);
}
