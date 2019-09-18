/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:22:33 by etuffleb          #+#    #+#             */
/*   Updated: 2019/09/18 20:22:36 by etuffleb         ###   ########.fr       */
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

int		sort_pushed_in_a(t_conv *list, t_stacks *sts, int pushed_a)
{
	int pivot;
	int i;
	int rest;
	int size_b;

	if (pushed_a < 2)
		return (0);
	if (pushed_a == 2)
	{
		if (sts->a[sts->top_a] < sts->a[sts->top_a - 1])
			add_to_list(sts, list, "sa");
		return (0);
	}
	pivot = (int)ft_pivot(sts->a, sts->top_a, pushed_a);
	i = 0;
	rest = 0;
	size_b = 0;
	while (i++ < pushed_a)
		if (sts->a[sts->top_a] >= pivot)
		{
			add_to_list(sts, list, "pb");
			size_b++;
		}
		else if (sts->a[sts->top_a] < pivot)
		{
			add_to_list(sts, list, "ra");
			rest++;
		}
	i = rest;
	while (i--)
		add_to_list(sts, list, "rra");
	return (size_b + sort_pushed_in_a(list, sts, rest));
}

void	sort_stack_b(t_conv *list, t_stacks *sts, int max_i)
{
	int i;
	int piv;
	int rest;
	int pushed_a;

	if (sts->top_b == 0)
	{
		add_to_list(sts, list, "pa");
		return ;
	}
	i = 0;
	rest = 0;
	pushed_a = 0;
	piv = ft_pivot(sts->b, sts->top_b, max_i - 1);
	while (i++ < max_i)
		if (sts->b[sts->top_b] <= piv && (++pushed_a))
			add_to_list(sts, list, "pa");
		else
		{
			add_to_list(sts, list, "rb");
			rest++;
		}
	i = rest;
	while (i--)
		add_to_list(sts, list, "rrb");
	rest += sort_pushed_in_a(list, sts, pushed_a);
	if (rest)
		sort_stack_b(list, sts, rest);
}

void	quick_sort_a(t_conv *list, t_stacks *sts, int max_i, int is_first)
{
	int pivot;
	int i;
	int rest;
	int size_b;

	if (max_i < 2 || sts->top_a < 1)
		return ;
	pivot = (int)ft_pivot(sts->a, sts->top_a, max_i - 1);
	i = 0;
	rest = 0;
	size_b = 0;
	while (i++ < max_i)
		if (sts->a[sts->top_a] >= pivot && (++size_b))
			add_to_list(sts, list, "pb");
		else
		{
			add_to_list(sts, list, "ra");
			rest++;
		}
	i = rest;
	if (!is_first)
		while (i--)
			add_to_list(sts, list, "rra");
	if (rest > 1)
		quick_sort_a(list, sts, rest, is_first);
	sort_stack_b(list, sts, size_b);
}
