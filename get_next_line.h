/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 19:33:07 by wmadison          #+#    #+#             */
/*   Updated: 2020/12/17 19:38:41 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*ft_strrchr(const char *str, int ch);
int		get_next_line(int fd, char **line);
int		ft_strlen(const char *s);
char	*ft_strdup(char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_createnewline(char *buf, char *rem);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_get_line(char *rem, char **line, int howmuchread);
#endif
