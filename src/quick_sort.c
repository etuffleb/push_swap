/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:22:33 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/06 21:01:29 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_three(t_conv *list, t_stacks *sts, int top)
{
	int *a;

	a = sts->a;
	if ((a[top] > a[top - 1] && a[top - 1] > a[top - 2]) || \
		(a[top - 2] < a[top - 1] && a[top - 2] > a[top]))
	{
		add_to_list(sts, list, "sa");
		sort_three(list, sts, top);
		return ;
	}
	if (a[top] < a[top - 1] && a[top] > a[top - 2])
		add_to_list(sts, list, "rra");
	else if (a[top - 2] < a[top] && a[top - 2] > a[top - 1])
		add_to_list(sts, list, "ra");
	else if (a[top] > a[top - 1] && a[top] < a[top - 2])
		add_to_list(sts, list, "sa");
}

void	push_b_min(t_conv *list, t_stacks *sts, int top)
{
	int c_ra;
	int i;
	int min;

	min = ft_min_a(sts->a, sts->top_a);
	c_ra = 0;
	i = 0;
	while (sts->a[top - i++] != min)
	{
		c_ra++;
	}
	if (c_ra < (top - c_ra))
		while (c_ra)
		{
			add_to_list(sts, list, "ra");
			c_ra--;
		}
	else
		while (((top + 1) - c_ra))
		{
			add_to_list(sts, list, "rra");
			c_ra++;
		}
	add_to_list(sts, list, "pb");
}

void	smart_sort(t_conv *list, t_stacks *sts, int top)
{
	int i;

	if (top == 1)
	{
		add_to_list(sts, list, "sa");
		return ;
	}
	i = 2;
	while (i++ < top)
	{
		push_b_min(list, sts, top);
	}
	sort_three(list, sts, 2);
	while (top-- > 2)
		add_to_list(sts, list, "pa");
}
