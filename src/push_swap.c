/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 20:34:58 by etuffleb          #+#    #+#             */
/*   Updated: 2019/08/24 18:19:19 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_a(t_conv *list, t_stacks *sts, int max_i);

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
	do_instruction(new, sts);
}

int ft_middle(int *stack, int top, int size)
{
	int min = stack[top];
	int max = min;
	int i;

	i = 0;
	while (i < size)
	{
		if (min > stack[top - i])
			min = stack[top - i];
		if (max < stack[top - i])
			max = stack[top - i];
		i++;
	}

	return ((min + max)/ 2);
}

void	push_from_b(t_conv *list, t_stacks *sts, int size)
{
	int j;
	int i;
	int mid;

	j = 0;
	i = 0;
	if (sts->top_b == 0)
	{
		printf("|top b = 0|\n");
		size = 1;
	}
	mid = ft_middle(sts->b, sts->top_b, size);
	// printf("|top b = %d, size = %d|\n", sts->top_b, size);
	// printf("|mid b = %d|\n", mid);
	while (size--)
	{
		if (sts->b[sts->top_b] <= mid)
		{
			add_to_list(sts, list, "pa");
			i++;
			printf("|b[top b] = %d, mid = %d|\n",sts->b[sts->top_b], mid);
		}
		else
		{
			if (sts->top_b > 1)
			{
				add_to_list(sts, list, "rb");
				j++;
			}
		}
	}
	//i = j;
	while (j--)
		add_to_list(sts, list, "rrb");//  ->

	sort_a(list, sts, i);//               <-

}

void sort_a(t_conv *list, t_stacks *sts, int max_i)
{
	int mid;
	int i;

	if (sts->top_a == 0 || max_i <= 1)
		return ;
	mid = ft_middle(sts->a, sts->top_a, max_i);
	// printf("|a%d|\n", mid);
	i = 0;
	while (i <= sts->top_a)
	{
		if (sts->a[sts->top_a] > mid)
			add_to_list(sts, list, "pb");
		else
			add_to_list(sts, list, "ra");
		i++;
	}
	// printf("|i = %d|\n", i);
	sort_a(list, sts, i);
	push_from_b(list, sts, i);
}

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
		while (tmp_list && tmp_list->next && tmp_list->next->next)// !!!! tmp_list
		{
			if(is_opposite(tmp_list))
			{
				tmp_list->next = tmp_list->next->next->next;
				optimise = 1;
			}
			else if ((mc = is_couple(tmp_list)))
				merge_instr(tmp_list, mc, &optimise);
			tmp_list = tmp_list->next;
		}
	}
}

void	run_sorting(t_stacks *sts, int top)
{
	t_conv		*instr_list;
	t_conv		*tmp_list;

	instr_list = ft_memalloc(sizeof(t_conv));
	instr_list->next = NULL;
	draw_status(sts->a, sts->b);

	sort_a(instr_list, sts, top);
	// printf("sorting done\n");
	// draw_status(sts->a, sts->b);
	optimise_instructions(instr_list);
	// printf("opt done\n");
	tmp_list = instr_list->next;
	draw_status(sts->a, sts->b);

	while(tmp_list)
	{
		ft_putendl(tmp_list->instr);
		// do_instruction(tmp_list, &sts);
		// draw_status(&sts);
		tmp_list = tmp_list->next;
	}
	free(sts);
	free(instr_list);
}

int main(int ac, char **av)
{
	int			*a;
	int			*b;
	t_stacks	*sts;

	if (ac < 2)
		ft_error("");

	is_valid(ac, av);
	if (!(a = create_stack(ac, av)))
		ft_error("cannot allocate memory\n");
	if (!(b = ft_memalloc(sizeof(int) * ac * 2)))
		ft_error("cannot allocate memory\n");

	sts = (t_stacks *)ft_memalloc(sizeof(t_stacks));

	sts->a = a;
	sts->b = b;
	sts->top_a = ac - 2;
	sts->top_b = -1;

	run_sorting(sts, ac - 1);

	free(a);
	free(b);
	exit(0);
}
