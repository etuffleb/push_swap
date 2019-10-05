/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:03:36 by etuffleb          #+#    #+#             */
/*   Updated: 2019/09/21 13:06:35 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sizeof_list(t_conv *list)
{
	int i;

	i = 0;
	while (list != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int		right_position(int *stack, int *sample, int top)
{
	int i;

	i = 0;
	while (top--)
	{
		if (stack[i] == sample[i])
			i++;
		else
			break;
	}
	return (i);
}

void	insertion_sort_b(t_conv *list, t_stacks *sts, int top, int *sample)
{
	int i;

	i = 0;

	while (i < top - 1)
	{
		if (sts->b[sts->top_b] < sts->b[sts->top_b - 1])
			add_to_list(sts, list, "pa");
		else
		{
			add_to_list(sts, list, "sb");
			add_to_list(sts, list, "pa");
		}
		if (sts->top_a > 0 && sts->a[sts->top_a] < sts->a[sts->top_a - 1])
			add_to_list(sts, list, "sa");
		i++;
	}
	add_to_list(sts, list, "pa");
	top -= right_position(sts->a, sample, top);

	insertion_sort(list, sts, top, sample);
}

void	insertion_sort(t_conv *list, t_stacks *sts, int top, int *sample)
{
	int i;

	i = 0;
	top -= right_position(sts->a, sample, top);
	if (!top)
		return ;
	while (i < top - 1)
	{
		if (sts->a[sts->top_a] > sts->a[sts->top_a - 1])
			add_to_list(sts, list, "pb");
		else
		{
			add_to_list(sts, list, "sa");
			add_to_list(sts, list, "pb");
		}
		if (sts->top_b > 0 && sts->b[sts->top_b] > sts->b[sts->top_b - 1])
			add_to_list(sts, list, "sb");
		i++;
	}
	add_to_list(sts, list, "pb");
	insertion_sort_b(list, sts, top, sample);
}
