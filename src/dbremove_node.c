/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbremove_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:36:01 by sbrochar          #+#    #+#             */
/*   Updated: 2017/12/04 17:52:51 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				dbremove_node(t_dblist **list, t_node **node)
{
	t_node			*to_delete;

	if (list && *list && node && *node)
	{
		to_delete = *node;
		if ((*node)->prev)
			(*node)->prev->next = (*node)->next;
		if ((*node)->next)
			(*node)->next->prev = (*node)->prev;
		if ((*node) == (*list)->start)
			(*list)->start = (*node)->next;
		if ((*node) == (*list)->end)
			(*list)->end = (*node)->prev;
		ft_memdel((void **)&(to_delete->content));
		ft_memdel((void **)&to_delete);
		(*list)->nb_nodes -= 1;
	}
}
