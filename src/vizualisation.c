/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 00:30:49 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/02 23:50:45 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	draw_status(t_stacks *sts, int hight)
{
	int i;

	i = 0;
	while (hight > -1)
	{
		printf("%s\t\t[%d]\t\t[%d]\n", GREEN, sts->a[hight], sts->b[hight]);
		hight--;
	}
	printf("\t\t------\t\t------\n\t\tstack a\t\tstack b\n\n%s", RESET);
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
		usleep(100000);
		instr_list = instr_list->next;
	}
}
