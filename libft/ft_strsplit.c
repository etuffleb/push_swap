/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:54:07 by etuffleb          #+#    #+#             */
/*   Updated: 2018/12/08 21:21:43 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word(char const *s, char c)
{
	unsigned int	i;
	int				word;

	word = 0;
	i = 0;
	if (s[i] != c && s[i] != '\0')
		word = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && (s[i + 1] != c) && s[i + 1] != '\0')
			word++;
		i++;
	}
	return (word);
}

static void	ft_free_arr(char **arr, char *str)
{
	int j;

	j = 0;
	while (arr[j] <= str)
	{
		free(arr[j]);
		++j;
	}
}

static char	**ft_split(char const *s, char c, int i, int j)
{
	char	**arr;
	int		lett;
	int		n;

	if ((arr = (char **)malloc(sizeof(char *) * ft_word(s, c) + 1)) == NULL)
		return (NULL);
	while (s[i] != '\0')
		if (s[i] == c)
			i++;
		else
		{
			lett = ft_letter_counter(&s[i], c);
			n = i--;
			if ((arr[++j] = ft_strnew(lett)) == NULL)
			{
				ft_free_arr(arr, arr[j]);
				return (NULL);
			}
			while (++i < n + lett)
				arr[j][i - n] = s[i];
		}
	arr[j + 1] = NULL;
	return (arr);
}

char		**ft_strsplit(char const *s, char c)
{
	if (s == NULL)
		return (NULL);
	return (ft_split(s, c, 0, -1));
}
