/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 20:34:58 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/05 19:43:37 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	just_push_b(t_conv *list, t_stacks *sts, int max_i)
{
	int pivot;
	int i;
	int rest;

	if (sts->top_a < 3)//check
		return ;
	pivot = (int)ft_pivot(sts->a, sts->top_a, max_i - 1);//sts->mid
	i = 0;
	rest = 0;
	while (i++ < max_i)
	{
		if (sts->a[sts->top_a] != sts->mid && sts->a[sts->top_a] != sts->min && sts->a[sts->top_a] != sts->max && sts->a[sts->top_a] < pivot)// <= mid
			add_to_list(sts, list, "pb");
		else
		{
			add_to_list(sts, list, "ra");
			rest++;
		}
	}
	sts->mid = (int)ft_pivot(sts->a, sts->top_a, rest - 1);
	just_push_b(list, sts, rest);
	// sts->mid = (int)ft_pivot(sts->b, sts->top_b, max_i - 1);
}

void	rotate_until(t_conv *list, t_stacks *sts)
{
	int i;

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

void	run_sorting(t_stacks *sts, int top, t_stacks *sts_copy, int v)
{
	t_conv		*instr_list;
	t_conv		*tmp_list;
	int			min_i;
	// int flag = 0;

	tmp_list = ft_memalloc(sizeof(t_conv));
	tmp_list->next = NULL;


	if (check_stacks(sts))//checks if stack a[] sorted
	{
		// printf ("sorted\n");
		return ;
	}
	if (top < 5)
	{
		smart_sort(tmp_list, sts, top);
	}
	else
	{
		just_push_b(tmp_list, sts, top);
		sort_a_in_needed_order(tmp_list, sts, 2);
		while (sts->top_b != -1)
		{
			min_i = find_min_i(sts);
			add_list_of_instr(tmp_list, sts, min_i);
			// printf ("min i = %d, top b = %d\n", min_i, sts->top_b);
		}
		rotate_until(tmp_list, sts);
	}

	optimise_instructions(tmp_list);
	instr_list = tmp_list->next;

	// draw_test(sts_copy->a, sts_copy->b);
	if (v)
		start_vizualisation(sts_copy, instr_list);
	else
	{
		while (instr_list)
		{
			// if (ft_strcmp(instr_list->instr, "pa") == 0 && sts_copy->b[sts_copy->top_b] == 6)
			// {
			// 	flag = 1;
			// }
			// if (flag++ && flag >= 60 && flag < 68)
			// 	draw_status(sts_copy, sts->top_a + sts->top_b);
			ft_putendl(instr_list->instr);
			do_instruction(instr_list, sts_copy);
			// draw_test(sts_copy->a, sts_copy->b);
			// ft_putendl("");
			instr_list = instr_list->next;
		}
		// draw_test(sts_copy->a, sts_copy->b);
	}
	free(sts);
	free(instr_list);
	free(tmp_list);
}

t_stacks	*init_stacks(int *a, int *b, int top)
{
	t_stacks	*sts;

	sts = (t_stacks *)ft_memalloc(sizeof(t_stacks));
	sts->a = a;
	sts->b = b;
	sts->top_a = top;
	sts->top_b = -1;
	sts->min = ft_min_a(a, top);
	sts->max = ft_max_a(a, top);
	sts->mid = ft_pivot(a, top, top - 1);
	return (sts);
}

int			main(int ac, char **av)
{
	int			*a;
	int			*a_copy;
	int			*b;
	int			*b_copy;
	t_stacks	*sts;
	t_stacks	*sts_copy;
	int			top;
	int			v;

	top = 0;
	v = 0;
	if (ft_strequ(av[1], "-v"))
	{
		av++;
		ac--;
		v = 1;
	}

	if (!(a = is_valid(ac, av, &top)))
		ft_error("cannot allocate memory\n");
	if (!(b = ft_memalloc(sizeof(int) * top * 3)))
		ft_error("cannot allocate memory\n");

	top = 0;
	a_copy = is_valid(ac, av, &top);
	b_copy = ft_memalloc(sizeof(int) * top * 3);

	sts = init_stacks(a, b, top - 1);

	sts_copy = init_stacks(a_copy, b_copy, top - 1);

	run_sorting(sts, top - 1, sts_copy, v);

	

	// draw_status(a, b);

	free(a);
	free(b);
	free(a_copy);
	free(b_copy);


	exit(0);
}
