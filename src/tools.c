/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:17:38 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/24 17:10:09 by etuffleb         ###   ########.fr       */
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
	if (instr_list->f)
		(instr_list->f)(sts);
}

void	fill_instr(char *instruction, t_conv *instr_arr)
{
	if (!instruction)
		return ;
	if (ft_strequ(instruction, "sa") || ft_strequ(instruction, "sb"))
		instr_arr->f = (ft_strequ(instruction, "sa")) ? *sa : *sb;
	else if (ft_strequ(instruction, "ss"))
		instr_arr->f = *ss;
	else if (ft_strequ(instruction, "pa"))
		instr_arr->f = *pa;
	else if (ft_strequ(instruction, "pb"))
		instr_arr->f = *pb;
	else if (ft_strequ(instruction, "ra"))
		instr_arr->f = *ra;
	else if (ft_strequ(instruction, "rb"))
		instr_arr->f = *rb;
	else if (ft_strequ(instruction, "rr"))
		instr_arr->f = *rr;
	else if (ft_strequ(instruction, "rra"))
		instr_arr->f = *rra;
	else if (ft_strequ(instruction, "rrb"))
		instr_arr->f = *rrb;
	else if (ft_strequ(instruction, "rrr"))
		instr_arr->f = *rrr;
	else
		ft_error("Error");
}
