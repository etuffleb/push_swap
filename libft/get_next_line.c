/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:37:43 by etuffleb          #+#    #+#             */
/*   Updated: 2019/08/22 13:42:36 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFF_SIZE 4

static char	*ft_full_string(char **s, char *slash_n)
{
	char	*rest;
	char	*result;
	size_t	len;

	len = slash_n - *s;
	rest = ft_strdup(slash_n);
	result = ft_strsub(*s, 0, len);
	result[len - 1] = '\0';
	free(*s);
	*s = rest;
	if (*s[0] == '\0')
		ft_strdel(s);
	return (result);
}

static int	ft_get_line(char **s, char **line, int fd, int read_status)
{
	char *slash_n;

	if ((slash_n = ft_strchr(s[fd], '\n')))
		*line = ft_full_string(&(s[fd]), slash_n + 1);
	else
	{
		if (read_status == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*s[10240];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			read_status;

	if (fd < 0 || line == NULL || fd > 10240)
		return (-1);
	while ((read_status = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (read_status == -1)
			return (-1);
		buf[read_status] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(0);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (read_status == 0 && (!s[fd] || s[fd][0] == '\0'))
		return (0);
	return (ft_get_line(s, line, fd, read_status));
}
