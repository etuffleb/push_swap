/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:17:38 by etuffleb          #+#    #+#             */
/*   Updated: 2019/08/24 17:43:44 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	draw_status(int *a, int *b)
{

	printf("%d %d\n", a[6], b[6]);
	printf("%d %d\n", a[5], b[5]);
	printf("%d %d\n", a[4], b[4]);
	printf("%d %d\n", a[3], b[3]);
	printf("%d %d\n", a[2], b[2]);
	printf("%d %d\n", a[1], b[1]);
	printf("%d %d\n", a[0], b[0]);
	printf("_ _\na b\n\n");

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
