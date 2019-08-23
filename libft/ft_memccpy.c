/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:21:03 by etuffleb          #+#    #+#             */
/*   Updated: 2018/12/01 20:06:02 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((char *)src)[i] == (char)c)
		{
			((char *)dest)[i] = ((char *)src)[i];
			return (&(dest[i + 1]));
		}
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (NULL);
}
