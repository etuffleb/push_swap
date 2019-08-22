/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:17:38 by etuffleb          #+#    #+#             */
/*   Updated: 2019/08/22 16:33:39 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	draw_status(t_stacks *sts)
{
	printf("%d %d\n%d %d\n%d %d\n%d %d\n_ _\n", sts->a[3], 0, \
	sts->a[2], 0, sts->a[1], 0, sts->a[0], 0);
}

void	do_instruction(t_conv *instr_list, t_stacks *sts)
{
	(instr_list->f)(sts);
}

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

int		*create_stack(int ac, char **av, int *mid)
{
	int *a;
	int i;
	int min;
	int max;


	i = 0;
	if (!(a = (int *)malloc(sizeof(int) * ac)))
		return (NULL);
	min = ft_atoi(av[1]);
	max = ft_atoi(av[1]);
	while (i < ac - 1)
	{
		a[i] = ft_atoi(av[i + 1]);
		if (min > a[i])
			min = a[i];
		if (max < a[i])
			max = a[i];
		i++;
	}
	if (*mid)
		*mid = (min + max) / 2;
	return (a);
}

void	is_valid(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != '-')
				ft_error("Error");
			j++;
		}
		i++;
	}
}
