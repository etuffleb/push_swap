/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:04:57 by etuffleb          #+#    #+#             */
/*   Updated: 2018/12/05 21:21:14 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_int_map(int *tab, int length, int (*f)(int))
{
	int		*array;
	int		i;

	i = 0;
	if (!f || !tab)
		return (NULL);
	array = (int *)malloc(sizeof(int) * length);
	while (length > i)
	{
		array[i] = f(tab[i]);
		i++;
	}
	return (array);
}
