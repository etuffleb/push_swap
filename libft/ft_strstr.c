/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 22:06:43 by etuffleb          #+#    #+#             */
/*   Updated: 2018/12/04 16:18:12 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	const char	*res;
	size_t		i;
	size_t		j;

	if (*to_find == '\0')
		return ((char *)str);
	j = -1;
	while (str[++j] != '\0')
		if (str[j] == *to_find)
		{
			res = &str[j];
			i = -1;
			while (++i < ft_strlen(to_find) && to_find[i] != '\0')
				if (str[j + i] != to_find[i])
				{
					res = 0;
					break ;
				}
			if (res)
				return ((char *)res);
		}
	return (NULL);
}
