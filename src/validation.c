/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:51:28 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/12 00:33:47 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

void	check_repeat(int *a, int size)
{
	int i;
	int j;
	int sample;

	i = 0;
	while (i < size)
	{
		sample = a[i];
		j = i + 1;
		while (j < size)
			if (a[j++] == sample)
				ft_error("Error");
		i++;
	}
}

int		*create_stack(int ac, char **av, int *top)
{
	int *a;
	int i;
	int j;
	int t;

	i = 0;
	t = 0;
	if (!(a = (int *)ft_memalloc(sizeof(int) * *top * 3)))
		return (NULL);
	while (i < ac - 1)
	{
		j = 0;
		while (av[i + 1][j] != '\0')
		{
			a[(*top) - ++t] = ft_atoi(&av[i + 1][j++]);
			while ((ft_isdigit(av[i + 1][j]) || av[i + 1][j] == '-' || \
			av[i + 1][j] == '+') && av[i + 1][j] != '\0')
				j++;
		}
		i++;
	}
	check_repeat(a, *top);
	return (a);
}

int		*is_valid(int ac, char **av, int *top)
{
	int i;
	int j;

	if (ac < 2)
		ft_error("");
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (ft_isdigit(av[i][j]) && \
			(av[i][j + 1] == ' ' || av[i][j + 1] == '\0'))
				(*top)++;
			if (ft_isdigit(av[i][j]) || av[i][j] == ' ' || \
			((av[i][j] == '-' || av[i][j] == '+') && ft_isdigit(av[i][j + 1])))
				j++;
			else
				ft_error("Error");
		}
		i++;
	}
	return (create_stack(ac, av, top));
}
