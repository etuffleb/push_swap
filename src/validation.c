/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:51:28 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/24 18:32:51 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	long_atoi(const char *str)
{
	int				n;
	long long int	res;

	n = 1;
	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		n = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return ((res * n));
}

int				ft_is_int(char *str)
{
	long long		nbr;

	nbr = long_atoi(str);
	if (nbr != ft_atoi(str))
		ft_error("Error");
	return ((int)nbr);
}

void			check_repeat(int *a, int size)
{
	int				i;
	int				j;
	int				sample;

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

int				*create_stack(int ac, char **av, int *top)
{
	int				*a;
	int				i;
	int				j;
	int				t;

	i = 0;
	t = 0;
	if (!(a = (int *)ft_memalloc(sizeof(int) * (*top + 1))))
		return (NULL);
	while (i < ac - 1)
	{
		j = 0;
		while (av[i + 1][j] != '\0')
		{
			a[(*top) - ++t] = ft_is_int(&av[i + 1][j++]);
			while ((ft_isdigit(av[i + 1][j]) || av[i + 1][j] == '-' || \
			av[i + 1][j] == '+') && av[i + 1][j] != '\0')
				j++;
		}
		i++;
	}
	check_repeat(a, *top);
	return (a);
}

int				*is_valid(int ac, char **av, int *top)
{
	int				i;
	int				j;

	if (ac < 2)
		ft_error("Number of parameters should be more then 0");
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
