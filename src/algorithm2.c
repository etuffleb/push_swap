/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 03:45:22 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/12 03:45:34 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_in_needed_order(t_conv *list, t_stacks *sts, int top)
{
	int *a;

	a = sts->a;
	if ((a[top] < a[top - 1]) && a[top - 1] < a[top - 2])
		add_to_list(sts, list, "rra");
	else if (a[top - 2] < a[top - 1] && a[top - 2] > a[top])
		add_to_list(sts, list, "sa");
	else if (a[top] < a[top - 1] && a[top] > a[top - 2])
		add_to_list(sts, list, "ra");
	else if (a[top - 1] > a[top - 2] && a[top - 1] < a[top])
	{
		add_to_list(sts, list, "rra");
		add_to_list(sts, list, "sa");
	}
	else if (a[top] > a[top - 1] && a[top] < a[top - 2])
	{
		add_to_list(sts, list, "ra");
		add_to_list(sts, list, "sa");
	}
}

int		op_counter(int i, t_stacks *sts)
{
	int rot_b;
	int rot_a;
	int op;
	int j;

	rot_b = ((sts->top_b - i) < (i + 1)) ? (sts->top_b - i) : (i + 1);
	j = 0;
	if (!(sts->b[i] < sts->a[sts->top_a] && sts->b[i] > sts->a[0]))
		while (j < sts->top_a)
		{
			if (sts->b[i] < sts->a[j] && (j != sts->top_a && \
				sts->b[i] > sts->a[j + 1]))
				break ;
			j++;
		}
	else
		j = -1;
	rot_a = ((sts->top_a - j) < (j + 1)) ? (sts->top_a - j) : (j + 1);
	op = rot_b + rot_a + 1;
	return (op);
}

void	add_func_to_list(t_conv *list, t_stacks *sts, int nbr, char *func)
{
	int i;

	i = 0;
	while (i < nbr)
	{
		add_to_list(sts, list, func);
		i++;
	}
}

void	add_list_of_instr(t_conv *list, t_stacks *sts, int i)
{
	int j;

	j = 0;
	if ((sts->top_b - i) < (i + 1))
		add_func_to_list(list, sts, sts->top_b - i, "rb");
	else
		add_func_to_list(list, sts, i + 1, "rrb");
	j = 0;
	if (!(sts->b[sts->top_b] < sts->a[sts->top_a] && \
		sts->b[sts->top_b] > sts->a[0]))
	{
		while (j < sts->top_a)
		{
			if (sts->b[sts->top_b] < sts->a[j] && (j != sts->top_a && \
				sts->b[sts->top_b] > sts->a[j + 1]))
				break ;
			j++;
		}
		if ((sts->top_a - j) < (j + 1))
			add_func_to_list(list, sts, sts->top_a - j, "ra");
		else
			add_func_to_list(list, sts, j + 1, "rra");
	}
	add_to_list(sts, list, "pa");
}

int		find_min_i(t_stacks *sts)
{
	int i;
	int min_i;
	int tmp;
	int res;

	res = 0;
	i = 0;
	min_i = op_counter(i, sts);
	while (++i <= sts->top_b)
	{
		tmp = op_counter(i, sts);
		if (min_i > tmp)
		{
			min_i = tmp;
			res = i;
		}
	}
	return (res);
}
