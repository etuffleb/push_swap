/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 20:35:26 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/04 04:04:39 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_line(t_stacks *sts)
{
	char	*tmp;
	t_conv	*instruction;


	instruction = ft_memalloc(sizeof(t_conv*));
	while (get_next_line(0, &tmp) > 0)
	{
		fill_instr(tmp, instruction);
		do_instruction(instruction, sts);
		// free (tmp);
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
	draw_test(sts.a, sts.b);
	if (check_stacks(&sts))
		return ("OK\n");
	else
		return ("KO\n");
}

int		main(int ac, char **av)
{
	int		*a;
	int		*b;
	int		top;
	int		v;

	top = 0;
	v = 0;
	if (ft_strequ(av[1], "-v"))
	{
		av++;
		ac--;
		v = 1;
	}
	if (ac < 2)
		ft_error("");
	if (!(a = is_valid(ac, av, &top)))
		ft_error("cannot allocate memory\n");
	if (!(b = ft_memalloc(sizeof(int) * top)))
		ft_error("cannot allocate memory");
	if (!v)
		ft_putstr(run_checker(a, b, top));
	else
	{
		/* code */
	}	
	free(a);
	free(b);
	return (0);
}
