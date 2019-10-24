/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 03:48:32 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/24 17:45:06 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_list_free(t_conv *list)
{
	if (list->next)
		ft_list_free(list->next);
	free(list);
}

void		ft_free_sts(t_stacks *fresh_sts)
{
	free(fresh_sts->a);
	free(fresh_sts->b);
	free(fresh_sts);
}

void		just_push_bigger(t_conv *list, t_stacks *sts, int max_i)
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
		if (sts->a[sts->top_a] != sts->mid && sts->a[sts->top_a] != sts->min &&\
		sts->a[sts->top_a] != sts->max && sts->a[sts->top_a] < pivot)
			add_to_list(sts, list, "pb");
		else
		{
			add_to_list(sts, list, "ra");
			rest++;
		}
	}
	sts->mid = (int)ft_pivot(sts->a, sts->top_a, rest - 1);
	just_push_bigger(list, sts, rest);
}
