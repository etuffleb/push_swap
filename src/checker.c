/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 20:35:26 by etuffleb          #+#    #+#             */
/*   Updated: 2019/09/05 22:47:16 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_stacks(t_stacks *sts)
{
	int top;

	top = sts->top_a;
	if (sts->top_b != -1)
		return (0);
	while (top > 0)
	{
		if (sts->a[top] < sts->a[top - 1])
			return (0);
		top--;
	}
	return (1);
}



void	read_line(t_stacks *sts)
{
	char	*tmp;
	t_conv	*instruction;

	instruction = ft_memalloc(sizeof(t_conv*));
	while (get_next_line(0, &tmp) > 0)
	{
		fill_instr(tmp, instruction);
		do_instruction(instruction, sts);
	}
	free(instruction);
}

char	*run_checker(int *a, int *b, int top)
{
	t_stacks	sts;

	sts.a = a;
	sts.b = b;
	sts.top_a = top - 1;
	sts.top_b = -1;
	read_line(&sts);
	draw_status(sts.a, sts.b);
	if (check_stacks(&sts))
		return ("OK\n");
	else
		return ("KO\n");
}

int		main(int ac, char **av)
{
	int *a;
	int *b;

	if (ac < 2)
		ft_error("");
	is_valid(ac, av);
	if (!(a = create_stack(ac, av)))
		ft_error("cannot allocate memory");
	if (!(b = ft_memalloc(sizeof(int) * ac * 2)))
		ft_error("cannot allocate memory");
	if (ac == 2)
		ft_putstr("OK\n");
	else
		ft_putstr(run_checker(a, b, ac - 1));
	free(a);
	free(b);
	return (0);
}
