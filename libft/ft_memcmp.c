/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:11:52 by etuffleb          #+#    #+#             */
/*   Updated: 2018/12/05 21:35:49 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcomp(unsigned char *s1, unsigned char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && (n - 1) > i)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int			ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	return (ft_strcomp((unsigned char *)arr1, (unsigned char *)arr2, n));
}
