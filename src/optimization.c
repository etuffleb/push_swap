/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:14:40 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/05 18:26:45 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int		check_stacks(t_stacks *sts)
{
	int top;

	top = sts->top_a;
	if (sts->top_b != -1)
		return (0);
	if (sts->a[top] > sts->a[top - 1])
	{
		while (top > 0)
		{
			if (sts->a[top] < sts->a[top - 1])
				return (0);
			top--;
		}
	}
	else
	{
		top = sts->top_a;
		while (top > 0)
		{
			if (sts->a[top] > sts->a[top - 1])
				return (0);
			top--;
		}
	}
	return (1);
}

int		is_opposite(t_conv *list)
{
	char *s1;
	char *s2;

	s1 = list->next->instr;
	s2 = list->next->next->instr;
	if ((!ft_strcmp(s1, "pa") && !ft_strcmp(s2, "pb")) || \
		(!ft_strcmp(s1, "pb") && !ft_strcmp(s2, "pa")) || \
		(!ft_strcmp(s1, "ra") && !ft_strcmp(s2, "rra")) || \
		(!ft_strcmp(s1, "rra") && !ft_strcmp(s2, "ra")) || \
		(!ft_strcmp(s1, "rb") && !ft_strcmp(s2, "rrb")) || \
		(!ft_strcmp(s1, "rrb") && !ft_strcmp(s2, "rb")) || \
		(!ft_strcmp(s1, "rr") && !ft_strcmp(s2, "rrr")) || \
		(!ft_strcmp(s1, "rrr") && !ft_strcmp(s2, "rr")))
		return (1);
	return (0);
}


int		is_couple(t_conv *list)
{
	char *s1;
	char *s2;

	s1 = list->next->instr;
	s2 = list->next->next->instr;
	if ((!ft_strcmp(s1, "sa") && !ft_strcmp(s2, "sb")) || \
		(!ft_strcmp(s1, "sb") && !ft_strcmp(s2, "sa")))
		return (1);
	if ((!ft_strcmp(s1, "ra") && !ft_strcmp(s2, "rb")) || \
		(!ft_strcmp(s1, "rb") && !ft_strcmp(s2, "ra")))
		return (2);
	if ((!ft_strcmp(s1, "rra") && !ft_strcmp(s2, "rrb")) || \
		(!ft_strcmp(s1, "rrb") && !ft_strcmp(s2, "rra")))
		return (3);
	return (0);
}

void	merge_instr(t_conv *list, int merge_case, int *optimise)
{
	*optimise = 1;
	list->next = list->next->next;
	if (merge_case == 1)
	{
		list->next->instr = "ss";
		list->next->f = *ss;
	}
	if (merge_case == 2)
	{
		list->next->instr = "rr";
		list->next->f = *rr;
	}
	if (merge_case == 3)
	{
		list->next->instr = "rrr";
		list->next->f = *rrr;
	}
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
		while (tmp_list && tmp_list->next && tmp_list->next->next)
		{
			if (is_opposite(tmp_list))
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


void	add_to_list(t_stacks *sts, t_conv *list, char *str)
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
	// free(new);
}

