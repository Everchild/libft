/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listtotab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 10:55:40 by sbrochar          #+#    #+#             */
/*   Updated: 2017/08/06 11:02:21 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				**listtotab(t_dblist *list)
{
	char			**ret;
	t_node			*cur;
	size_t			i;

	if (list)
	{
		cur = list->start;
		i = 0;
		ret = (char **)ft_memalloc(sizeof(char *) * (list->nb_nodes + 1));
		while (cur)
		{
			ret[i] = ft_strdup(cur->content);
			i++;
			cur = cur->next;
		}
		return (ret);
	}
	return (NULL);
}
