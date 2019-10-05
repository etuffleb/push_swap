/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 00:41:05 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/05 18:14:07 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *sts)
{
	int		tmp;
	int		i;
	int		top;

	top = sts->top_a;
	i = 0;
	tmp = sts->a[0];
	while (i < top)
	{
		sts->a[i] = sts->a[i + 1];
		i++;
	}
	sts->a[top] = tmp;
}

void	rrb(t_stacks *sts)
{
	int		tmp;
	int		i;
	int		top;

	top = sts->top_b;
	i = 0;
	tmp = sts->b[0];
	while (i < top)
	{
		sts->b[i] = sts->b[i + 1];
		i++;
	}
	sts->b[top] = tmp;
}
