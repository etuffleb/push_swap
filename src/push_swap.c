/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 20:34:58 by etuffleb          #+#    #+#             */
/*   Updated: 2019/09/05 21:03:42 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

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
		if (sts->b[sts->top_b] <= piv)
		{
			add_to_list(sts, list, "pa");
			pushed_a++;
		}
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

void	sort_stack_a(t_conv *list, t_stacks *sts, int max_i, int is_first)
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
		if (sts->a[sts->top_a] >= pivot)
		{
			add_to_list(sts, list, "pb");
			size_b++;
		}
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
		sort_stack_a(list, sts, rest, is_first);
	sort_stack_b(list, sts, size_b);
}

void	run_sorting(t_stacks *sts, int top, t_stacks *sts_copy)
{
	t_conv		*instr_list;
	t_conv		*tmp_list;

	instr_list = ft_memalloc(sizeof(t_conv));
	instr_list->next = NULL;
	sort_stack_a(instr_list, sts, top, 1);
	optimise_instructions(instr_list);
	tmp_list = instr_list->next;
	//draw_status(sts_copy->a, sts_copy->b);
	while(tmp_list)
	{
		ft_putendl(tmp_list->instr);
		do_instruction(tmp_list, sts_copy);
		// draw_status(sts_copy->a, sts_copy->b);
		// ft_putendl("");
		tmp_list = tmp_list->next;
	}
	draw_status(sts_copy->a, sts_copy->b);
	free(sts);
	free(instr_list);
}

/* to do
* ac == 1
* "-45 23 42 -11 0 3"
*
*/

int		main(int ac, char **av)
{
	int			*a;
	int			*a_copy;
	int			*b;
	int			*b_copy;
	t_stacks	*sts;
	t_stacks	*sts_copy;

	if (ac < 2)
		ft_error("");

	is_valid(ac, av);
	if (!(a = create_stack(ac, av)))
		ft_error("cannot allocate memory\n");
	if (!(b = ft_memalloc(sizeof(int) * ac * 3)))
		ft_error("cannot allocate memory\n");

	a_copy = create_stack(ac, av);
	b_copy = ft_memalloc(sizeof(int) * ac * 3);

	sts = (t_stacks *)ft_memalloc(sizeof(t_stacks));

	sts->a = a;
	sts->b = b;
	sts->top_a = ac - 2;
	sts->top_b = -1;

	sts_copy = (t_stacks *)ft_memalloc(sizeof(t_stacks));
	sts_copy->a = a_copy;
	sts_copy->b = b_copy;
	sts_copy->top_a = ac - 2;
	sts_copy->top_b = -1;

	run_sorting(sts, ac - 1, sts_copy);


	// free(a);
	// free(b);
	exit(0);
}
