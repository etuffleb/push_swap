/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:51:28 by etuffleb          #+#    #+#             */
/*   Updated: 2019/09/18 21:45:20 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*create_stack(int ac, char **av)
{
	int *a;
	int i;

	i = 0;
	if (!(a = (int *)ft_memalloc(sizeof(int) * ac * 3)))
		return (NULL);
	while (i < ac - 1)
	{
		a[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return (a);
}

int		*is_valid_str(char **av)
{
	int i;
	int j;
	int *a;

	i = 0;
	while (av[1][i] != '\0')
	{

		if ((av[1][i] < '0' || av[1][i] > '9') \
			&& av[1][i] != '-' && av[1][i] != '+' && av[1][i] != ' ')
			ft_error("Error");
		i++;
	}
	if (!(a = (int *)ft_memalloc(sizeof(int) * i)))
		ft_error("Cannot allocate memory :(");
	i = 0;
	j = 0;
	while (av[1][j] != '\0')
	{
		a[i] = ft_atoi(&(av[1][j]));
		printf("%d, %d\n", a[i], j );
		while(av[1][j] && (ft_isdigit(av[1][j]) || av[1][j] == '-' \
			|| av[1][j] == '+'))
			j++;
		if (av[1][j])
			j++;
		i++;
	}
	return (a);
}

int		*is_valid(int ac, char **av)
{
	int i;
	int j;

	if (ac < 2)
		ft_error("");
	if (ac == 2)
		return (is_valid_str(av));
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && \
				av[i][j] != '-' && av[i][j] != '+')
				ft_error("Error");
			j++;
		}
		i++;
	}
	return (create_stack(ac, av));
}
