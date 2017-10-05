/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_clist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:40:12 by sbrochar          #+#    #+#             */
/*   Updated: 2017/10/05 14:37:35 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				free_clist(t_clist **list)
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
		ft_memdel((void **)list);
	}
}
