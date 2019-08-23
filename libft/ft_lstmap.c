/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:11:15 by etuffleb          #+#    #+#             */
/*   Updated: 2018/12/08 21:58:33 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((new_list = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new_list = f(lst);
	new_list->next = ft_lstmap(lst->next, f);
	return (new_list);
}
