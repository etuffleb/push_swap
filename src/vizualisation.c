/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 00:30:49 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/13 22:26:09 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	draw_status(t_stacks *sts, int hight)
{
	write(1, GREEN, 7);
	while (hight > -1)
	{
		ft_putstr("\t\t[");
		if (hight > sts->top_a)
			ft_putstr(" ");
		else
			ft_putnbr(sts->a[hight]);
		ft_putstr("]\t\t[");
		if (hight > sts->top_b)
			ft_putstr(" ");
		else
			ft_putnbr(sts->b[hight]);
		ft_putstr("]\n");
		hight--;
	}
	ft_putstr("\t\t------\t\t------\n\t\tstack a\t\tstack b\n\n");
	write(1, RESET, 5);
}

void	checker_vizualisation(t_stacks *sts, int top)
{
	system("clear");
	draw_status(sts, top);
}

void	start_vizualisation(t_stacks *sts, t_conv *instr_list)
{
	int hight;

	hight = sts->top_a;
	system("clear");
	draw_status(sts, hight);
	usleep(150000);
	while (instr_list)
	{
		system("clear");
		do_instruction(instr_list, sts);
		draw_status(sts, hight);
		usleep(50000);
		instr_list = instr_list->next;
	}
}
