/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 20:35:26 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/24 18:09:02 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_line(t_stacks *sts, int v)
{
	char		*tmp;
	int			top;
	t_conv		*instruction;

	instruction = malloc(sizeof(t_conv));
	instruction->next = NULL;
	instruction->f = NULL;
	top = sts->top_a;
	if (v)
		checker_vizualisation(sts, top);
	while (get_next_line(0, &tmp) > 0)
	{
		fill_instr(tmp, instruction);
		do_instruction(instruction, sts);
		free(tmp);
		if (v)
			checker_vizualisation(sts, top);
	}
	ft_list_free(instruction);
}

char	*run_checker(int *a, int *b, int top, int v)
{
	t_stacks	sts;

	sts.a = a;
	sts.b = b;
	sts.top_a = top - 1;
	sts.top_b = -1;
	read_line(&sts, v);
	if (check_stacks(&sts))
		return (v) ? ("✅ OK\n") : ("OK\n");
	else
		return (v) ? ("❌ KO\n") : ("KO\n");
}

int		main(int ac, char **av)
{
	int			*a;
	int			*b;
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
	if (ac < 2)
		return (0);
	if (!(a = is_valid(ac, av, &top)))
		ft_error("Error");
	if (!(b = ft_memalloc(sizeof(int) * top)))
		ft_error("Error");
	ft_putstr(run_checker(a, b, top, v));
	free(a);
	free(b);
	return (0);
}
