/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:17:38 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/12 00:34:27 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_max_a(int *a, int top)
{
	int max;

	max = a[top];
	while (top > -1)
	{
		if (max < a[top])
			max = a[top];
		top--;
	}
	return (max);
}

int		ft_min_a(int *a, int top)
{
	int min;

	min = a[top];
	while (top > -1)
	{
		if (min > a[top])
			min = a[top];
		top--;
	}
	return (min);
}

void	do_instruction(t_conv *instr_list, t_stacks *sts)
{
	(instr_list->f)(sts);
}

void	fill_instr(char *instruction, t_conv *instr_arr)
{
	while(*instruction == ' ')
	{
		instruction++;
	}
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
	else
		ft_error("Wrong command");
}
