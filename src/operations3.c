/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 00:41:05 by etuffleb          #+#    #+#             */
/*   Updated: 2019/09/05 20:49:48 by etuffleb         ###   ########.fr       */
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

double	ft_middle(int *stack, int top, int size)
{
	double	mid;
	int		i;

	i = 0;
	mid = 0;
	while (i < size)
	{
		mid += stack[top - i];
		i++;
	}
	return (mid / i);
}

double	ft_pivot(int *stack, int top, int size)
{
	double	middle;
	double	pivot;
	double	dif;
	double	modul;
	int		i;

	middle = ft_middle(stack, top, size);
	pivot = stack[top];
	modul = stack[top] - middle;
	modul = (modul < 0) ? modul * -1 : modul;
	i = 0;
	while (i < size)
	{
		dif = stack[top - i] - middle;
		dif = (dif < 0) ? dif * -1 : dif;
		if (dif < modul)
		{
			modul = dif;
			pivot = stack[top - i];
		}
		i++;
	}
	return (pivot);
}
