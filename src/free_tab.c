/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 14:51:04 by sbrochar          #+#    #+#             */
/*   Updated: 2017/12/05 19:44:14 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void				free_tab(char ***s)
{
	size_t			i;

	i = 0;
	if (s)
	{
		if (*s)
		{
			while ((*s)[i])
			{
				free((*s)[i]);
				(*s)[i] = NULL;
				i++;
			}
			free(*s);
			*s = NULL;
		}
	}
}
