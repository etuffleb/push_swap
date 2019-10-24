/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:14:40 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/22 23:56:17 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_opposite(t_conv *list)
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

int			is_couple(t_conv *list)
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

void		merge_instr(t_conv *list, int merge_case, int *optimise)
{
	t_conv *list_to_free;

	list_to_free = list->next;
	*optimise = 1;
	list->next = list->next->next;
	free(list_to_free);
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

void		delete_opposite(t_conv *list, int *optimise)
{
	t_conv		*list_to_free;

	list_to_free = list->next;
	free(list_to_free);
	list->next = list->next->next->next;
	free(list_to_free->next);
	*optimise = 1;
}

t_conv		*optimise_instructions(t_conv *instr_list)
{
	t_conv		*list_to_free;
	t_conv		*tmp_list;
	int			optimise;
	int			mc;

	optimise = 1;
	list_to_free = instr_list;
	while (optimise == 1)
	{
		tmp_list = instr_list;
		optimise = 0;
		while (tmp_list && tmp_list->next && tmp_list->next->next)
		{
			if (is_opposite(tmp_list))
				delete_opposite(tmp_list, &optimise);
			else if ((mc = is_couple(tmp_list)))
				merge_instr(tmp_list, mc, &optimise);
			tmp_list = tmp_list->next;
		}
	}
	return (list_to_free);
}
