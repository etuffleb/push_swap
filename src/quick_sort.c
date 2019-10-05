/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:22:33 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/05 18:27:39 by etuffleb         ###   ########.fr       */
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

void	push_b_min(t_conv *list, t_stacks *sts, int top)//to check / checked?
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
		while (((top+1) - c_ra))
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
		else if ((++rest))
			add_to_list(sts, list, "rb");
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
	// sort_stack_b(list, sts, size_b);
}
