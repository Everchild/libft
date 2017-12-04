/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cremove_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:36:01 by sbrochar          #+#    #+#             */
/*   Updated: 2017/12/04 17:51:22 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				cremove_node(t_clist **list, t_node **node)
{
	t_node			*to_delete;

	if (list && *list && node && *node)
	{
		to_delete = *node;
		if ((*list)->nb_nodes > 1)
		{
			if (to_delete == (*list)->start)
				(*list)->start = to_delete->next;
			if (to_delete == (*list)->end)
				(*list)->end = to_delete->prev;
			to_delete->prev->next = to_delete->next;
			to_delete->next->prev = to_delete->prev;
		}
		else
		{
			(*list)->start = NULL;
			(*list)->end = NULL;
		}
		ft_memdel((void **)&(to_delete->content));
		ft_memdel((void **)&to_delete);
		(*list)->nb_nodes -= 1;
	}
}
