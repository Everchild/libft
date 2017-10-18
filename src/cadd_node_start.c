/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cadd_node_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:41:38 by sbrochar          #+#    #+#             */
/*   Updated: 2017/10/19 01:11:38 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_node				*cadd_node_start(t_clist **list, t_node *node)
{
	if (list && *list && node)
	{
		if (!(*list)->start && !(*list)->end)
		{
			(*list)->start = node;
			(*list)->end = node;
			node->next = (*list)->end;
		}
		else
		{
			node->next = (*list)->start;
			(*list)->start->prev = node;
			(*list)->start = node;
		}
		node->prev = (*list)->end;
		(*list)->end->next = node;
		(*list)->nb_nodes += 1;
		return ((*list)->start);
	}
	return (NULL);
}
