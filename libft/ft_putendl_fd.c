/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:00:38 by etuffleb          #+#    #+#             */
/*   Updated: 2018/11/29 16:38:47 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	unsigned int i;

	i = 0;
	if (fd > -1 && s != NULL)
	{
		while (s[i] != '\0')
			ft_putchar_fd(s[i++], fd);
		ft_putchar_fd('\n', fd);
	}
}
