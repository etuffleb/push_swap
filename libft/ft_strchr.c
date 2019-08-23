/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:46:54 by etuffleb          #+#    #+#             */
/*   Updated: 2018/11/29 14:41:52 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	ch = (char)ch;
	while (*str != ch && *str != '\0')
		str++;
	if (*str == ch)
		return ((char *)str);
	else
		return (NULL);
}
