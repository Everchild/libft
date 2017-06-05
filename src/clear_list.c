/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 18:00:17 by sbrochar          #+#    #+#             */
/*   Updated: 2017/06/05 18:00:37 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				clear_list(t_dblist **list)
{
	t_node			*cur;
	t_node			*next;

	if (list && *list)
	{
		cur = (*list)->start;
		while (cur)
		{
			next = cur->next;
			ft_memdel((void **)&(cur->content));
			ft_memdel((void **)&cur);
			cur = next;
		}
	}
}
