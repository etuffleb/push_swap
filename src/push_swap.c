/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 20:34:58 by etuffleb          #+#    #+#             */
/*   Updated: 2019/08/22 15:15:47 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_algorithm(t_conv **list, int mid)
{

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
	return (0);
//  1)	sa-sb -> ss
//  2)	ra-rb -> rr
//  3)	rra-rrb->rrr
}

void	remove_instr(t_conv list, int *optimise)
{
	*optimise = 1;
	if (list->next->next)
		list->next = list->next->next->next;
}

void	merge_instr(t_conv list, int merge_case, int *optimise)
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
	t_conv      *tmp_list;
	int			optimise;
	int			mc;

	optimise = 1;
	while (optimise == 1)
	{
		tmp_list = instr_list;
		optimise = 0;
		while (tmp_list && tmp_list->next && tmp_list-next->next)// !!!! tmp_list
		{
			if(is_opposite(tmp_list->next, tmp_list->next->next))
			{
				tmp_list->next = tmp_list->next->next->next;
                opimise = 1;
			}
			else if ((mc = is_couple(tmp_list->next, tmp_list->next->next)))
				merge_instr(tmp_list, mc, &opimise);
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
	create_algorithm(&instr_list, mid);
	opimise_instructions(instr_arr);//del
	i = 0;
	tmp = instr
	while(tmp_list)
	{
		//do_instruction(instr_arr[i], &sts);
		ft_putstr(instr_list->instr);
		if 
			put \n;
		//draw_status(&sts);
		instr_list = instr_list->next;
	}
	put \0;
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
	if (!(b = ft_memalloc(ac)))
		ft_error("cannot allocate memory\n");

	run_sorting(a, b, middle, ac - 2);

	free(a);
	free(b);
	return (0);
}
