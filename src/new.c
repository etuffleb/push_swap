/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:48:03 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/05 19:44:17 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_in_needed_order(t_conv *list, t_stacks *sts, int top)
{
	int *a;

	a = sts->a;
	if ((a[top] < a[top - 1]) && a[top - 1] < a[top - 2])
		add_to_list(sts, list, "rra");
	else if (a[top - 2] < a[top - 1] && a[top - 2] > a[top])
		add_to_list(sts, list, "sa");
	else if (a[top] < a[top - 1] && a[top] > a[top - 2])
		add_to_list(sts, list, "ra");
	else if (a[top - 1] > a[top - 2] && a[top - 1] < a[top])
	{
		add_to_list(sts, list, "rra");
		add_to_list(sts, list, "sa");
	}
	else if (a[top] > a[top - 1] && a[top] < a[top - 2])
	{
		add_to_list(sts, list, "ra");
		add_to_list(sts, list, "sa");
	}
}

int		op_counter(int i, t_stacks *sts)
{
	int rot_b;//rb or rrb
	int rot_a;//ra or rra
	int op;
	int j;

	if ((sts->top_b - i) < (i + 1))
		rot_b = sts->top_b - i;//rb
	else
		rot_b = i + 1;//rrb
	j = 0;
	if (!(sts->b[i] < sts->a[sts->top_a] && sts->b[i] > sts->a[0]))
		while (j < sts->top_a)//
		{
			if (sts->b[i] < sts->a[j] && (j != sts->top_a && sts->b[i] > sts->a[j + 1]))//j != top_a lishnee
				break ;
			j++;
		}
	else
		j = -1;

	if ((sts->top_a - j) < (j + 1))
		rot_a = sts->top_a - j;//ra
	else
		rot_a = j + 1;//rra

	//printf("rot a = %d, rot b = %d\n", rot_a, rot_b);

	op = rot_b + rot_a + 1;//pa
	return (op);
	// rra = i + 1;
	// ra = top_b - (i )
}

void	add_list_of_instr(t_conv *list, t_stacks *sts, int i)
{
	int j;
	int k;

	j = 0;
	if ((sts->top_b - i) < (i + 1))
		while (j < sts->top_b - i)
		{
			add_to_list(sts, list, "rb");
			j++;
		}
	else
	{
		while (j < (i + 1))
		{
			add_to_list(sts, list, "rrb");
			j++;
		}
	}
	j = 0;
	if (!(sts->b[sts->top_b] < sts->a[sts->top_a] && sts->b[sts->top_b] > sts->a[0]))
	{
		// printf ("ALERT sts->top_b = %d\n", sts->top_b);
		// draw_test(sts->a, sts->b);
		while (j < sts->top_a)
		{
			if (sts->b[sts->top_b] < sts->a[j] && (j != sts->top_a && sts->b[sts->top_b] > sts->a[j + 1]))
				break ;
			j++;
		}
        k = 0;
        if ((sts->top_a - j) < (j + 1))
        {
            while (k < sts->top_a - j)
            {
                add_to_list(sts, list, "ra");
                k++;
            }
        }
        else
        {
            while (k < (j + 1))
            {
                add_to_list(sts, list, "rra");
                k++;
            }
        }
	}
	add_to_list(sts, list, "pa");
}

int		find_min_i(t_stacks *sts)//min_i is [i] of array a, with minimal len of instr list
{
	int i;
	int min_i;
	int tmp;
	int res;

	res = 0;
	i = 0;
	min_i = op_counter(i, sts);
	// printf("for i = %d, tmp = %d\n", i, min_i);
	while (++i <= sts->top_b)
	{
		tmp = op_counter(i, sts);//some ideas for optimisation: if tmp == 1, break
		// printf("for i = %d, tmp = %d\n", i, tmp);
		if (min_i > tmp)
		{
			min_i = tmp;
			res = i;
		}
	}
	return (res);
}

