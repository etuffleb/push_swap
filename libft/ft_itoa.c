/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:54:43 by etuffleb          #+#    #+#             */
/*   Updated: 2018/12/02 19:55:34 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_help(int len, char *str, int n)
{
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len] = ('0' + (n % 10));
		n /= 10;
		len--;
	}
}

char		*ft_itoa(int n)
{
	int		num;
	int		len;
	char	*str;
	int		neg;

	num = n;
	len = 1;
	neg = 0;
	while (num /= 10)
		len++;
	if (n < 0)
		len++;
	if ((str = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	ft_itoa_help(len, str, n);
	if (neg)
		str[0] = '-';
	return (str);
}
