/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 03:45:17 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/12 05:23:03 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	just_push_b(t_conv *list, t_stacks *sts, int max_i)
{
	int		pivot;
	int		i;
	int		rest;

	if (sts->top_a < 3)
		return ;
	pivot = (int)ft_pivot(sts->a, sts->top_a, max_i - 1);
	i = 0;
	rest = 0;
	while (i++ < max_i)
	{
		if (sts->a[sts->top_a] != sts->mid && \
		sts->a[sts->top_a] != sts->min && sts->a[sts->top_a] != sts->max && \
		sts->a[sts->top_a] < pivot)
			add_to_list(sts, list, "pb");
		else
		{
			add_to_list(sts, list, "ra");
			rest++;
		}
	}
	sts->mid = (int)ft_pivot(sts->a, sts->top_a, rest - 1);
	just_push_b(list, sts, rest);
}

void	rotate_until(t_conv *list, t_stacks *sts)
{
	int		i;

	i = 0;
	while (sts->a[i] != sts->min)
	{
		i++;
	}
	if ((sts->top_a - i) < (i + 1))
	{
		i = sts->top_a - i;
		while (i--)
		{
			add_to_list(sts, list, "ra");
		}
	}
	else
	{
		i++;
		while (i--)
		{
			add_to_list(sts, list, "rra");
		}
	}
}

int		check_stacks(t_stacks *sts)
{
	int		top;

	top = sts->top_a;
	if (sts->top_b != -1)
		return (0);
	if (sts->a[top] > sts->a[top - 1])
	{
		while (top > 0)
		{
			if (sts->a[top] < sts->a[top - 1])
				return (0);
			top--;
		}
	}
	else
	{
		top = sts->top_a;
		while (top > 0)
		{
			if (sts->a[top] > sts->a[top - 1])
				return (0);
			top--;
		}
	}
	return (1);
}

void	add_to_list(t_stacks *sts, t_conv *list, char *str)
{
	t_conv	*new;

	while (list->next != NULL)
	{
		list = list->next;
	}
	new = ft_memalloc(sizeof(t_conv));
	new->instr = str;
	fill_instr(str, new);
	new->next = NULL;
	list->next = new;
	do_instruction(new, sts);
}

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}
