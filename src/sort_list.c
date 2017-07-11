/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 02:51:32 by sbrochar          #+#    #+#             */
/*   Updated: 2017/07/11 02:57:52 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				sort_list(t_dblist **list)
{
	t_bool			issort;
	t_node			*node;

	issort = FALSE;
	if (*list && (*list)->start)
	{
		while (!issort)
		{
			issort = TRUE;
			node = (*list)->start;
			while (node->content && node && node != (*list)->end)
			{
				if (ft_strcmp(node->content, node->next->content) > 0)
				{
					issort = FALSE;
					swap_nodes(&node, &node->next);
				}
				node = node->next;
			}
		}
	}
}
