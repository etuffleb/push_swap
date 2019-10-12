/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 20:34:58 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/12 05:30:42 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*create_vi_stacks(t_stacks *sts, int top)
{
	t_stacks	*fresh_sts;
	int			*a;
	int			*b;
	int			i;

	if (!(fresh_sts = (t_stacks *)ft_memalloc(sizeof(t_stacks))))
		ft_error("cannot allocate memory");
	if (!(a = ft_memalloc(sizeof(int) * top)))
		ft_error("cannot allocate memory");
	if (!(b = ft_memalloc(sizeof(int) * top)))
		ft_error("cannot allocate memory");
	i = 0;
	while (i < top + 1)
	{
		a[i] = sts->a[i];
		i++;
	}
	fresh_sts->a = a;
	fresh_sts->b = b;
	fresh_sts->top_a = top;
	fresh_sts->top_b = -1;
	return (fresh_sts);
}

void		start_algorithm(t_stacks *sts, int top, t_conv *tmp_list)
{
	int			min_i;

	if (top < 5)
		smart_sort(tmp_list, sts, top);
	else
	{
		just_push_b(tmp_list, sts, top);
		sort_a_in_needed_order(tmp_list, sts, 2);
		while (sts->top_b != -1)
		{
			min_i = find_min_i(sts);
			add_list_of_instr(tmp_list, sts, min_i);
		}
		rotate_until(tmp_list, sts);
	}
}

void		run_sorting(t_stacks *sts, int top, int v)
{
	t_conv		*instr_list;
	t_conv		*tmp_list;
	t_stacks	*fresh_sts;

	if (check_stacks(sts))
		return ;
	tmp_list = ft_memalloc(sizeof(t_conv));
	tmp_list->next = NULL;
	if (v)
		fresh_sts = create_vi_stacks(sts, top);
	start_algorithm(sts, top, tmp_list);
	instr_list = optimise_instructions(tmp_list);
	tmp_list = tmp_list->next;
	if (v)
		start_vizualisation(fresh_sts, tmp_list);
	else
		while (tmp_list)
		{
			ft_putendl(tmp_list->instr);
			tmp_list = tmp_list->next;
		}
	if (v)
		ft_free_sts(fresh_sts);
	ft_list_free(instr_list);
}

t_stacks	*init_stacks(int *a, int *b, int top)
{
	t_stacks	*sts;

	if (!(sts = (t_stacks *)ft_memalloc(sizeof(t_stacks))))
		ft_error("cannot allocate memory");
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
	int			*b;
	t_stacks	*sts;
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
	if (!(b = ft_memalloc(sizeof(int) * top)))
		ft_error("cannot allocate memory\n");
	sts = init_stacks(a, b, top - 1);
	run_sorting(sts, top - 1, v);
	free(sts);
	free(a);
	free(b);
	exit(0);
}
