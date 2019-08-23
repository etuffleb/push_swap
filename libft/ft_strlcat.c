/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:35:40 by etuffleb          #+#    #+#             */
/*   Updated: 2018/12/04 14:07:38 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t res;

	res = 0;
	if (size > ft_strlen(dest))
	{
		res = ft_strlen(dest) + ft_strlen(src);
		ft_strncat(dest, src, (size - ft_strlen(dest) - 1));
		return (res);
	}
	return (ft_strlen(src) + size);
}
