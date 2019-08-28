/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:17:38 by etuffleb          #+#    #+#             */
/*   Updated: 2019/08/28 15:28:56 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	draw_status(int *a, int *b)
{
	printf("\t%d\t%d\n", a[10], b[10]);
	printf("\t%d\t%d\n", a[9], b[9]);
	printf("\t%d\t%d\n", a[8], b[8]);
	printf("\t%d\t%d\n", a[7], b[7]);

	printf("\t%d\t%d\n", a[6], b[6]);
	printf("\t%d\t%d\n", a[5], b[5]);
	printf("\t%d\t%d\n", a[4], b[4]);
	printf("\t%d\t%d\n", a[3], b[3]);
	printf("\t%d\t%d\n", a[2], b[2]);
	printf("\t%d\t%d\n", a[1], b[1]);
	printf("\t%d\t%d\n", a[0], b[0]);
	printf("\t__\t__\n\ta\tb\n\n");


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

int		*create_stack(int ac, char **av)
{
	int *a;
	int i;

	i = 0;
	if (!(a = (int *)ft_memalloc(sizeof(int) * ac * 2)))
		return (NULL);
	while (i < ac - 1)
	{
		a[i] = ft_atoi(av[i + 1]);
		i++;
	}
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
