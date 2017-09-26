/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabtostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 13:39:05 by sbrochar          #+#    #+#             */
/*   Updated: 2017/09/26 14:38:37 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t				get_size(char **tab)
{
	size_t			ret;
   
	ret = 0;
	if (tab)
	{
		while (*tab)
		{
			ret += ft_strlen(*tab);
			tab++;
		}
	}
	return (ret);
}

char				*ft_tabtostr(char **tab)
{
	char			*ret;
	size_t			size;

	size = get_size(tab);
	ret = ft_strnew(size);
	if (tab && ret)
	{
		while (*tab)
		{
			ft_strcat(ret, *tab);
			tab++;
		}
		return (ret);
	}
	return (NULL);
}
