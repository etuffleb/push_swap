/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:04:28 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/05 18:13:19 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stacks *sts)
{
	int tmp;
	int top;

	tmp = sts->b[sts->top_b];
	top = sts->top_b;
	while (top)
	{
		sts->b[top] = sts->b[top - 1];
		top--;
	}
	sts->b[0] = tmp;
}

void	ra(t_stacks *sts)
{
	int tmp;
	int top;

	tmp = sts->a[sts->top_a];
	top = sts->top_a;
	while (top)
	{
		sts->a[top] = sts->a[top - 1];
		top--;
	}
	sts->a[0] = tmp;
}

void	rr(t_stacks *sts)
{
	ra(sts);
	rb(sts);
}

void	rrr(t_stacks *sts)
{
	rra(sts);
	rrb(sts);
}
