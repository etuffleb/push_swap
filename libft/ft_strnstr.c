/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:00:31 by etuffleb          #+#    #+#             */
/*   Updated: 2018/12/08 21:18:42 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_f, size_t len)
{
	size_t	length;

	if (*to_f == '\0')
		return ((char *)str);
	if (len >= ft_strlen(str))
		return (ft_strstr(str, to_f));
	length = ft_strlen(to_f);
	while (*str != '\0' && len >= length)
	{
		if (*str == *to_f && ft_memcmp(str, to_f, length) == 0)
			return ((char *)str);
		str++;
		len--;
	}
	return (NULL);
}
