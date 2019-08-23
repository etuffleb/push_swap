/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:02:01 by etuffleb          #+#    #+#             */
/*   Updated: 2018/12/08 20:48:03 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t i;

	i = 0;
	while (n > i)
	{
		if (*((unsigned char *)(arr + i)) == (unsigned char)c)
			return ((void *)(arr + i));
		i++;
	}
	return (NULL);
}
