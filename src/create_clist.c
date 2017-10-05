/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_clist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 18:48:02 by sbrochar          #+#    #+#             */
/*   Updated: 2017/09/27 15:37:46 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_clist				*create_clist(void)
{
	t_clist			*list;

	list = (t_clist *)ft_memalloc(sizeof(t_clist));
	if (list)
	{
		list->start = NULL;
		list->end = NULL;
		list->nb_nodes = 0;
		return (list);
	}
	return (NULL);
}
