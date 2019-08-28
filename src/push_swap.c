/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 20:34:58 by etuffleb          #+#    #+#             */
/*   Updated: 2019/08/28 17:07:50 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_a(t_conv *list, t_stacks *sts, int max_i, int is_first);

void	optimise_instructions(t_conv *instr_list)
{
	t_conv		*tmp_list;
	int			optimise;
	int			mc;

	optimise = 1;
	while (optimise == 1)
	{
		tmp_list = instr_list;
		optimise = 0;
		while (tmp_list && tmp_list->next && tmp_list->next->next)
		{
			if(is_opposite(tmp_list))
			{
				tmp_list->next = tmp_list->next->next->next;
				optimise = 1;
			}
			else if ((mc = is_couple(tmp_list)))
			{
				merge_instr(tmp_list, mc, &optimise);
				optimise = 1;
			}
			tmp_list = tmp_list->next;
		}
	}
}

void add_to_list(t_stacks *sts, t_conv *list, char *str)
{
	t_conv *new;

	while (list->next != NULL)
	{
		list = list->next;
	}
	new = ft_memalloc(sizeof(t_conv));
	new->instr = str;
	fill_instr(str, new);
	new->next = NULL;
	list->next = new;
	ft_putendl(new->instr);
	do_instruction(new, sts);
}

int ft_middle(int *stack, int top, int size)
{
	int mid;
	int i;

	i = 0;
	mid = 0;
	while (i < size)
	{
		mid += stack[top - i];
		i++;
	}
	return (mid / i);
}

void	push_from_b(t_conv *list, t_stacks *sts, int size)
{
	int j;
	int i;
	double mid;

	j = 0;
	i = 0;
	if (sts->top_b == -1)
	{
		return;
	}
	mid = ft_middle(sts->b, sts->top_b, size);
	printf("mid = %f, top b = %d, size = %d\n", mid, sts->b[sts->top_b], size);
	while (size--)
	{
		if (sts->b[sts->top_b] < mid)
		{
			// if (sts->top_b > 0 && sts->b[sts->top_b] > sts->b[sts->top_b - 1])
			// {
			// 	add_to_list(sts, list, "sb");
			// 	draw_status(sts->a, sts->b);
			// }
			add_to_list(sts, list, "pa");
			draw_status(sts->a, sts->b);
			i++;
		}
		else// if (sts->top_b > 1)
		{
			add_to_list(sts, list, "rb");
			draw_status(sts->a, sts->b);
			j++;
		}
	}
	while (j--)
	{
		add_to_list(sts, list, "rrb");
		draw_status(sts->a, sts->b);
	}
	sort_a(list, sts, i, 0);
}

void sort_a(t_conv *list, t_stacks *sts, int max_i, int is_first)
{
	double mid;
	int i;
	int j;
	int m;
	int sch;

	if (sts->top_a == 0 || max_i <= 1)
		return ;
	mid = ft_middle(sts->a, sts->top_a, max_i);
	printf("|mid = %f|\n", mid);
	j = 0;
	i = 0;
	sch = 0;
	while (sch < max_i)
	{
		if (sts->a[sts->top_a] > mid)
		{
			add_to_list(sts, list, "pb");
			draw_status(sts->a, sts->b);
			j++;
		}

		else //if (sts->top_a > 0)
		{
			add_to_list(sts, list, "ra");
			draw_status(sts->a, sts->b);
			i++;
		}
		sch++;
	}

	m = i;
	if (!is_first)
		while (m--)
		{
			add_to_list(sts, list, "rra");
			draw_status(sts->a, sts->b);
		}
	printf("|j = %d|\n", j);
	sort_a(list, sts, i, is_first);
	printf("|j = %d|\n", j);

	while (sts->top_b != -1)
	{
		printf("|*j = %d|\n", j);
		push_from_b(list, sts, j);
	}
}

int		ft_pivot(int *stack, int top_a, int size)
{
	int		middle;
	int		pivot;
	int		tmp;
	int		i;
	int		modul;

	middle = ft_middle(stack, top_a, size);
	i = 0;
	pivot = stack[size - i];
	modul = stack[size - i] - middle;
	modul = (modul < 0) ? modul * -1 : modul;
	while (i <= size)
	{
		tmp = stack[size - i] - middle;
		tmp = (tmp < 0) ? tmp * -1 : tmp;
		if (tmp < modul)
		{
			modul = tmp;
			pivot = stack[size - i];
		}
		i++;
	}
	return (pivot);
}

void sort_stack_a(t_conv *list, t_stacks *sts, int max_i, int is_first)
{
	int pivot;

	pivot = ft_pivot(sts->a, sts->top_a, sts->top_a);

	while (max_i--)
		if (sts->a[sts->top_a] >= pivot)
			add_to_list(sts, list, "pb");
		else
			add_to_list(sts, list, "ra");
	if (!is_first)
		while(max_i--)
			add_to_list(sts, list, "rra");

}










void	create_algorithm(t_conv *list, t_stacks *sts, int max_i)
{
	sort_stack_a(list, sts, max_i, 1);
//	push_from_b(list, sts, max_i);
}

void	run_sorting(t_stacks *sts, int top, t_stacks *sts_copy)
{
	t_conv		*instr_list;
	t_conv		*tmp_list;

	instr_list = ft_memalloc(sizeof(t_conv));
	instr_list->next = NULL;

	create_algorithm(instr_list, sts, top);
	//optimise_instructions(instr_list);

	tmp_list = instr_list->next;
	(void)sts_copy;
	// draw_status(sts_copy->a, sts_copy->b);
	// while(tmp_list)
	// {
	// 	ft_putendl(tmp_list->instr);

	// 	do_instruction(tmp_list, sts_copy);
	// 	//draw_status(sts_copy->a, sts_copy->b);
	// 	tmp_list = tmp_list->next;
	// 	ft_putendl("");
	// }
	// draw_status(sts_copy->a, sts_copy->b);
	free(sts);
	free(instr_list);
}

int main(int ac, char **av)
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
	if (!(b = ft_memalloc(sizeof(int) * ac * 2)))
		ft_error("cannot allocate memory\n");

	a_copy = create_stack(ac, av);
	b_copy = ft_memalloc(sizeof(int) * ac * 2);

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

	free(a);
	free(b);
	exit(0);
}
