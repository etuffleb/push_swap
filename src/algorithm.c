/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:14:40 by etuffleb          #+#    #+#             */
/*   Updated: 2019/08/25 20:34:19 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
//	pa-pb
//	ra-rra
//	rb-rrb
//	rr-rrr
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
	if ((!ft_strcmp(s1, "rr") && !ft_strcmp(s2, "rrb")) || \
		(!ft_strcmp(s1, "rrb") && !ft_strcmp(s2, "rr")))
		return (4);
	if ((!ft_strcmp(s1, "rr") && !ft_strcmp(s2, "rra")) || \
		(!ft_strcmp(s1, "rra") && !ft_strcmp(s2, "rr")))
		return (5);
	return (0);
//	1)	sa-sb -> ss
//	2)	ra-rb -> rr
//	3)	rra-rrb->rrr
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
	if (merge_case == 4)
	{
		list->next->instr = "ra";
		list->next->f = *rrr;
	}
	if (merge_case == 5)
	{
		list->next->instr = "rb";
		list->next->f = *rrr;
	}
}
