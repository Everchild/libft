/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cadd_node_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:42:23 by sbrochar          #+#    #+#             */
/*   Updated: 2017/09/27 16:30:34 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_node				*cadd_node_end(t_clist **list, t_node *node)
{
	if (list && *list && node)
	{
		if (!(*list)->start && !(*list)->end)
		{
			(*list)->start = node;
			(*list)->end = node;
			node->prev = (*list)->start;
		}
		else
		{
			node->prev = (*list)->end;
			(*list)->end->next = node;
			(*list)->end = node;
		}
		node->next = (*list)->start;
		(*list)->nb_nodes += 1;
		return ((*list)->end);
	}
	return (NULL);
}
