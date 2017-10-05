/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_clist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:45:56 by sbrochar          #+#    #+#             */
/*   Updated: 2017/10/05 14:46:45 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_node				*iter_clist(t_clist **list, int (*f)(t_node *))
{
	t_node			*cur;

	if (list && *list && f)
	{
		cur = (*list)->start;
		while (cur != (*list)->end && f(cur))
			cur = cur->next;
		if (cur == (*list)->end && f(cur))
			return (cur);
	}
	return (NULL);
}
