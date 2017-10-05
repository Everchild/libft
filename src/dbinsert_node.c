/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbinsert_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 17:20:22 by sbrochar          #+#    #+#             */
/*   Updated: 2017/10/05 14:14:13 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_node				*dbinsert_node(t_dblist **list, t_node *new, t_node *next)
{
	if (list && *list && new && next)
	{
		if ((*list)->start == next)
			return (dbadd_node_start(list, new));
		else
		{
			new->prev = next->prev;
			new->next = next;
			next->prev = new;
			new->prev->next = new;
			(*list)->nb_nodes += 1;
			return (new);
		}
	}
	return (NULL);
}
