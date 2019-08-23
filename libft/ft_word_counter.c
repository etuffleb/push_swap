/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:11:35 by etuffleb          #+#    #+#             */
/*   Updated: 2018/12/04 12:12:09 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_counter(char const *s)
{
	unsigned int	i;
	int				word;

	word = 0;
	i = 0;
	if (!ft_isitspace(s[i]) && s[i] != '\0')
		word = 1;
	while (s[i] != '\0')
	{
		if (ft_isitspace(s[i]) && (!ft_isitspace(s[i + 1]) && s[i + 1] != '\0'))
			word++;
		i++;
	}
	return (word);
}
