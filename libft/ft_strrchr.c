/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:34:21 by etuffleb          #+#    #+#             */
/*   Updated: 2018/12/02 18:38:02 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		i;
	char	*res;

	res = NULL;
	i = 0;
	if (ch == '\0' || ch == 128)
	{
		while (str[i] != '\0')
		{
			if (ch == 128 && str[i] == '\200')
				res = &((char *)str)[i];
			i++;
		}
		if (ch == 128)
			return (res);
		return (&((char *)str)[i]);
	}
	else
		while (str[i] != '\0')
		{
			if (str[i] == ch)
				res = &((char *)str)[i];
			i++;
		}
	return (res);
}
