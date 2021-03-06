/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbadd_node_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:41:38 by sbrochar          #+#    #+#             */
/*   Updated: 2017/11/01 16:42:41 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_node				*dbadd_node_start(t_dblist **list, t_node *node)
{
	if (list && *list && node)
	{
		if (!(*list)->start && !(*list)->end)
		{
			(*list)->start = node;
			(*list)->end = node;
			node->next = NULL;
		}
		else
		{
			node->next = (*list)->start;
			(*list)->start->prev = node;
			(*list)->start = node;
		}
		node->prev = NULL;
		(*list)->nb_nodes += 1;
		return ((*list)->start);
	}
	return (NULL);
}
