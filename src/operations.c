/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:29:39 by etuffleb          #+#    #+#             */
/*   Updated: 2019/09/05 19:03:53 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *sts)
{
	if (sts->top_b == -1)
		return ;
	sts->a[sts->top_a + 1] = sts->b[sts->top_b];
	sts->b[sts->top_b] = 0;
	sts->top_a++;
	sts->top_b--;
}

void	pb(t_stacks *sts)
{
	if (sts->top_a == -1)
		return ;
	sts->b[sts->top_b + 1] = sts->a[sts->top_a];
	sts->a[sts->top_a] = 0;
	sts->top_b++;
	sts->top_a--;
}

void	sb(t_stacks *sts)
{
	int tmp;

	tmp = sts->b[sts->top_b];
	sts->b[sts->top_b] = sts->b[sts->top_b - 1];
	sts->b[sts->top_b - 1] = tmp;
}

void	sa(t_stacks *sts)
{
	int tmp;

	tmp = sts->a[sts->top_a];
	sts->a[sts->top_a] = sts->a[sts->top_a - 1];
	sts->a[sts->top_a - 1] = tmp;
}

void	ss(t_stacks *sts)
{
	sa(sts);
	sb(sts);
}
