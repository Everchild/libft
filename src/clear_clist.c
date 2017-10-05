/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_clist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 18:00:17 by sbrochar          #+#    #+#             */
/*   Updated: 2017/10/05 14:28:01 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				clear_clist(t_clist **list)
{
	t_node			*cur;
	t_node			*next;

	if (list && *list)
	{
		cur = (*list)->start;
		while (cur != (*list)->end)
		{
			next = cur->next;
			ft_memdel((void **)&(cur->content));
			ft_memdel((void **)&cur);
			cur = next;
		}
		ft_memdel((void **)&(cur->content));
		ft_memdel((void **)&cur);
		(*list)->start = NULL;
		(*list)->end = NULL;
		(*list)->nb_nodes = 0;
	}
}
