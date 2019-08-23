/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:27:25 by etuffleb          #+#    #+#             */
/*   Updated: 2018/12/08 21:10:25 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	if (!n)
		return (dest);
	n++;
	while (--n)
		((char *)dest)[n - 1] = ((char *)src)[n - 1];
	((char *)dest)[n] = ((char *)src)[n];
	return (dest);
}
