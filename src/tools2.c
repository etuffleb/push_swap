/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 03:48:32 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/12 03:58:07 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_list_free(t_conv *list)
{
	if (!list)
		return ;
	ft_list_free(list->next);
	free(list);
}

void		ft_free_sts(t_stacks *fresh_sts)
{
	free(fresh_sts->a);
	free(fresh_sts->b);
	free(fresh_sts);
}
