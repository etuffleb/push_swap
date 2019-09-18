/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 20:34:58 by etuffleb          #+#    #+#             */
/*   Updated: 2019/09/18 21:49:00 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	insertion_sort(t_conv *list, t_stacks *sts, int top, int *sample);

int		sizeof_list(t_conv *list)
{
	int i;

	i = 0;
	while (list != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int		right_position(int *stack, int *sample, int top)
{
	int i;

	i = 0;
	while (top--)
	{
		if (stack[i] == sample[i])
			i++;
		else
			break;
	}
	return (i);
}

void	insertion_sort_b(t_conv *list, t_stacks *sts, int top, int *sample)
{
	int i;

	i = 0;

	while (i < top - 1)
	{
		if (sts->b[sts->top_b] < sts->b[sts->top_b - 1])
			add_to_list(sts, list, "pa");
		else
		{
			add_to_list(sts, list, "sb");
			add_to_list(sts, list, "pa");
		}
		if (sts->top_a > 0 && sts->a[sts->top_a] < sts->a[sts->top_a - 1])
			add_to_list(sts, list, "sa");
		i++;
	}
	add_to_list(sts, list, "pa");
	top -= right_position(sts->a, sample, top);

	insertion_sort(list, sts, top, sample);
}

void	insertion_sort(t_conv *list, t_stacks *sts, int top, int *sample)
{
	int i;

	i = 0;
	top -= right_position(sts->a, sample, top);
	if (!top)
		return ;
	while (i < top - 1)
	{
		if (sts->a[sts->top_a] > sts->a[sts->top_a - 1])
			add_to_list(sts, list, "pb");
		else
		{
			add_to_list(sts, list, "sa");
			add_to_list(sts, list, "pb");
		}
		if (sts->top_b > 0 && sts->b[sts->top_b] > sts->b[sts->top_b - 1])
			add_to_list(sts, list, "sb");
		i++;
	}
	add_to_list(sts, list, "pb");
	insertion_sort_b(list, sts, top, sample);
}

void	run_sorting(t_stacks *sts, int top, t_stacks *sts_copy, t_stacks *sts_copy_copy)
{
	t_conv		*instr_list;
	t_conv		*tmp_list;
	t_conv		*tmp_list_two;

	tmp_list = ft_memalloc(sizeof(t_conv));
	tmp_list->next = NULL;
	tmp_list_two = ft_memalloc(sizeof(t_conv));
	tmp_list_two->next = NULL;

	quick_sort_a(tmp_list, sts, top, 1);
	optimise_instructions(tmp_list);

	insertion_sort(tmp_list_two, sts_copy, top, sts->a);
	optimise_instructions(tmp_list_two);

	if (sizeof_list(tmp_list) < sizeof_list(tmp_list_two))
		instr_list = tmp_list->next;
	else
		instr_list = tmp_list_two->next;

	// draw_status(sts_copy->a, sts_copy->b);
	// draw_status(sts_copy_copy->a, sts_copy_copy->b);

	while(instr_list)
	{
		ft_putendl(instr_list->instr);
		do_instruction(instr_list, sts_copy_copy);
		// draw_status(sts_copy->a, sts_copy->b);
		// ft_putendl("");
		instr_list = instr_list->next;
	}
	draw_status(sts_copy_copy->a, sts_copy_copy->b);
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
	int			*a_copy_copy;
	int			*b;
	int			*b_copy;
	int			*b_copy_copy;
	t_stacks	*sts;
	t_stacks	*sts_copy;
	t_stacks	*sts_copy_copy;

	int top;


	a = is_valid(ac, av);
	if (!(b = ft_memalloc(sizeof(int) * ac * 3)))
		ft_error("cannot allocate memory\n");

	a_copy = is_valid(ac, av);
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


	a_copy_copy = is_valid(ac, av);
	b_copy_copy = ft_memalloc(sizeof(int) * ac * 3);

	sts_copy_copy = (t_stacks *)ft_memalloc(sizeof(t_stacks));
	sts_copy_copy->a = a_copy_copy;
	sts_copy_copy->b = b_copy_copy;
	sts_copy_copy->top_a = ac - 2;
	sts_copy_copy->top_b = -1;

	run_sorting(sts, ac - 1, sts_copy, sts_copy_copy);


	// free(a);
	// free(b);
	exit(0);
}
