/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:17:38 by etuffleb          #+#    #+#             */
/*   Updated: 2019/09/05 22:47:21 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	draw_status(int *a, int *b)
{
	printf("\t%d\t%d\n", a[14], b[14]);
	printf("\t%d\t%d\n", a[13], b[13]);
	printf("\t%d\t%d\n", a[12], b[12]);
	printf("\t%d\t%d\n", a[11], b[11]);
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
	if (!(a = (int *)ft_memalloc(sizeof(int) * ac * 3)))
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

void	fill_instr(char *instruction, t_conv *instr_arr)
{
	if (ft_strcmp(instruction, "sa") == 0)
		instr_arr->f = *sa;
	else if (ft_strcmp(instruction, "sb") == 0)
		instr_arr->f = *sb;
	else if (ft_strcmp(instruction, "ss") == 0)
		instr_arr->f = *ss;
	else if (ft_strcmp(instruction, "pa") == 0)
		instr_arr->f = *pa;
	else if (ft_strcmp(instruction, "pb") == 0)
		instr_arr->f = *pb;
	else if (ft_strcmp(instruction, "ra") == 0)
		instr_arr->f = *ra;
	else if (ft_strcmp(instruction, "rb") == 0)
		instr_arr->f = *rb;
	else if (ft_strcmp(instruction, "rr") == 0)
		instr_arr->f = *rr;
	else if (ft_strcmp(instruction, "rra") == 0)
		instr_arr->f = *rra;
	else if (ft_strcmp(instruction, "rrb") == 0)
		instr_arr->f = *rrb;
	else if (ft_strcmp(instruction, "rrr") == 0)
		instr_arr->f = *rrr;
}
