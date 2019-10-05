/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boring_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:04:23 by etuffleb          #+#    #+#             */
/*   Updated: 2019/09/21 14:11:23 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// void    sort_from_b()
// {


// }


void    ft_min_max(int *a, int top, int *min, int *max)
{
    int i;

    i= 0;
    while(i < top)
    {
        if (*min > a[i])
            *min = a[i];
        if (*max < a[i])
            *max = a[i];
        i++;
    }
}

void	boring_sort(t_conv *list, t_stacks *sts, int top)
{
	int i;
	int max;
	int min;

    // if (top <= 5)
    // {

    //     return ;
    // }
    min = sts->a[top];
    max = sts->a[top];
	ft_min_max(sts->a, sts->top_a, &min, &max);
    // printf("min = %d, max = %d\n", min, max);
    i = 0;
	while (i++ < top)
	{
        // printf("%d\n", sts->a[sts->top_a]);
        if (sts->a[sts->top_a] == min || sts->a[sts->top_a] == max)
			add_to_list(sts, list, "ra");
		else
			add_to_list(sts, list, "pb");
    }
	// sort_from_b(list, sts);
}
