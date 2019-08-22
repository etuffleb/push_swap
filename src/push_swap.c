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

void add_to_list(t_stacks *sts, t_conv *list, char *str)
{
	t_conv *new;


	write(1, "t\n", 2);

	while (list->next != NULL)
	{
		write(1, "list\n", 5);
		list = list->next;
	}
	write(1, "m\n", 2);
	new = malloc(sizeof(t_conv));
	new->instr = str;
	fill_instr(str, new);
	new->next = NULL;
	list->next = new;
	write(1, "d\n", 2);
	do_instruction(new, sts);
}

// void	sort_pushing_element()
// {
// 	if (a[top] < a[top - 1])
// 		add_to_list(ra);

// }

// void	push_from_b(t_conv *list, t_stacks *sts, int i, int mid)
// {
// 	int j;

// 	j = 0;
// 	while (i--)
// 	{
// 		if (sts->b[top_b] < mid)
// 			add_to_list(sts, list, "pa");
// 		//	sort_pushing_element(sts->a, sts->top_a);
// 		else
// 		{
// 			add_to_list(sts, list, "rb");
// 			j++;
// 		}

// 	}
// 	while (j--)
// 		add_to_list(sts, list, "rrb");

// 	sort_pushing_element

//}

void sort_a(t_conv **list, t_stacks *sts, int mid)
{
	int min;
	int max;
	int i;
	t_conv *tmp;

	tmp = *list;
	if (sts->top_a == 0)
		return ;
	min = sts->a[sts->top_a];
	max = min;
	i = 0;
	while (i++ < sts->top_a + 1)
	{
		write(1, "3\n", 2);
		if (sts->a[sts->top_a] > mid)
			add_to_list(sts, tmp, "pb");
			// min2
			// max2
		else
		{
			min = (min > sts->a[sts->top_a]) ? sts->a[sts->top_a] : min;
			max = (max < sts->a[sts->top_a]) ? sts->a[sts->top_a] : max;
			add_to_list(sts, tmp, "ra");
		}
	}
	sort_a(list, sts, (min + max) / 2);
	//push_from_b(list, sts, i, (min2 + max2)/2)

}



void	create_algorithm(t_conv **list, t_stacks *sts, int mid)
{
	sort_a(list, sts, mid);
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
	write(1, "2\n", 2);
	create_algorithm(&instr_list, &sts, mid);
	write(1, "5\n", 2);
	optimise_instructions(instr_list);

	i = 0;
	tmp_list = instr_list;
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
	if (!(a = create_stack(ac, av, &middle)))
		ft_error("cannot allocate memory\n");
	if (!(b = ft_memalloc(sizeof(int) * ac)))
		ft_error("cannot allocate memory\n");
	write(1, "1\n", 2);
	run_sorting(a, b, middle, ac - 2);

	free(a);
	free(b);
	return (0);
}
