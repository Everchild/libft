/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabtostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 13:39:05 by sbrochar          #+#    #+#             */
/*   Updated: 2017/10/17 21:29:32 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t				get_size(char **tab)
{
	size_t			ret;
	size_t			nb_str;
   
	ret = 0;
	nb_str = 0;
	if (tab)
	{
		while (*tab)
		{
			ret += ft_strlen(*tab);
			tab++;
			nb_str++;
		}
	}
	return (ret + nb_str - 1);
}

char				*ft_tabtostr(char **tab)
{
	char			*ret;
	size_t			size;
	char			*tmp;

	size = get_size(tab);
	ret = ft_strnew(size);
	if (tab && ret)
	{
		while (*tab)
		{
			ft_strcat(ret, *tab);
			tab++;
			tmp = ft_strchr(ret, 0);
			tmp[0] = (*tab == NULL) ? '\0' : ' ';
		}
		return (ret);
	}
	return (NULL);
}
