/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 20:34:58 by etuffleb          #+#    #+#             */
/*   Updated: 2019/08/22 21:55:31 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_a(t_conv *list, t_stacks *sts, int mid, int max_i);

void add_to_list(t_stacks *sts, t_conv *list, char *str)
{
	t_conv *new;



	while (list->next != NULL)
	{

		list = list->next;
	}
	new = malloc(sizeof(t_conv));
	new->instr = str;
	fill_instr(str, new);
	new->next = NULL;
	list->next = new;
	do_instruction(new, sts);
}

// void	sort_pushing_element()
// {
// 	if (a[top] < a[top - 1])
// 		add_to_list(ra);

// }

void	push_from_b(t_conv *list, t_stacks *sts, int size, int mid)
{
	int j;
	int i;
	int min;
	int max;
	int maxInited = 0;

	j = 0;
	while (size--)
	{
		if (sts->b[sts->top_b] < mid) {
			if (maxInited == 0) 
			{
				maxInited = 1;
				min = sts->b[sts->top_b];
				max = min;
			} 
			else
			{
				min = (min > sts->b[sts->top_b]) ? sts->b[sts->top_b] : min;
				max = (max < sts->b[sts->top_b]) ? sts->b[sts->top_b] : max;
			}
			add_to_list(sts, list, "pa");
		}
		//	sort_pushing_element(sts->a, sts->top_a);
		else
		{
			add_to_list(sts, list, "rb");
			j++;
		}

	}
	i = j;
	while (j--)
		add_to_list(sts, list, "rrb");

	sort_a(list, sts, (max + min) / 2, i);

}

void sort_a(t_conv *list, t_stacks *sts, int mid, int max_i)
{
	int min;
	int max;
	int min2;
	int max2;
	int max2Inited = 0;
	int i;

	if (sts->top_a == 0 || max_i <= 1)
		return ;
	min = sts->a[sts->top_a];
	max = min;
	i = 0;
	while (i++ <= sts->top_a)
	{

		if (sts->a[sts->top_a] > mid) 
		{
			if (max2Inited == 0) 
			{
				max2Inited = 1;
				min2 = sts->a[sts->top_a];
				max2 = min2;
			} 
			else
			{
				min2 = (min2 > sts->a[sts->top_a]) ? sts->a[sts->top_a] : min2;
				max2 = (max2 < sts->a[sts->top_a]) ? sts->a[sts->top_a] : max2;
			}
			add_to_list(sts, list, "pb");
		}
		else
		{
			min = (min > sts->a[sts->top_a]) ? sts->a[sts->top_a] : min;
			max = (max < sts->a[sts->top_a]) ? sts->a[sts->top_a] : max;
			add_to_list(sts, list, "ra");
		}
	}
	sort_a(list, sts, (min + max) / 2, i);
	push_from_b(list, sts, i, (min2 + max2)/2);
}



void	create_algorithm(t_conv *list, t_stacks *sts, int mid)
{
	sort_a(list, sts, mid, sts->top_a + 1);
	//push_from_b(list, sts);
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

void	run_sorting(int *a, int *b, int mid, int top)
{
	t_stacks	sts;
	int			i;
	t_conv		*instr_list;
	t_conv		*tmp_list;

	sts.a = a;
	sts.b = b;
	sts.top_a = top;
	sts.top_b = -1;

	instr_list = malloc(sizeof(t_conv));
	instr_list->next = NULL;
	create_algorithm(instr_list, &sts, mid);
	// optimise_instructions(instr_list);

	i = 0;
	tmp_list = instr_list->next;
	while(tmp_list)
	{
		ft_putendl(tmp_list->instr);
		//draw_status(&sts);
		tmp_list = tmp_list->next;
	}
	//free instr
}

int main(int ac, char **av)
{
	int *a;
	int *b;
	int middle;

	if (ac < 2)
		ft_error("");
	middle = 1;
	is_valid(ac, av);
	if (!(a = create_stack(ac, av, &middle)))//init {0} !!!
		ft_error("cannot allocate memory\n");
	if (!(b = ft_memalloc(sizeof(int) * ac)))
		ft_error("cannot allocate memory\n");
	run_sorting(a, b, middle, ac - 2);

	free(a);
	free(b);
	return (0);
}







