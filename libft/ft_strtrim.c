/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:53:37 by etuffleb          #+#    #+#             */
/*   Updated: 2018/12/08 21:29:55 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_space(char const *s, int word)
{
	int i;

	i = 0;
	while (s[i] != '\0' && word)
	{
		i++;
		if (ft_isitspace(s[i]) && !ft_isitspace(s[i - 1]))
			word--;
	}
	return (i);
}

static char	*ft_split_space(char const *s)
{
	int i;

	i = 0;
	while (ft_isitspace(s[i]))
		i++;
	return (&((char *)s)[i]);
}

char		*ft_strtrim(char const *s)
{
	char	*r;
	int		i;
	int		j;
	int		word;

	if (s == NULL)
		return (NULL);
	word = ft_word_counter(s);
	i = 0;
	j = 0;
	s = ft_split_space(s);
	if ((r = malloc(sizeof(char) * ft_len_space(s, word) + 1)) == NULL)
		return (NULL);
	while (s[i] != '\0' && word)
	{
		r[j] = s[i];
		j++;
		i++;
		if (ft_isitspace(s[i]) && !ft_isitspace(s[i - 1]))
			word--;
	}
	r[j] = '\0';
	return (r);
}
