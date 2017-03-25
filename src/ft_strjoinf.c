/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 21:40:01 by sbrochar          #+#    #+#             */
/*   Updated: 2017/03/25 21:44:46 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strjoinf(char *s1, char *s2, int which)
{
	char			*ret;

	ret = NULL;
	if (s1 && s2)
		ret = ft_strnew(ft_strlen(s1 + ft_strlen(s2)));
	if (ret)
	{
		ret = ft_strcpy(ret, s1);
		ret = ft_strcat(ret, s2);
		if (which == 1)
			ft_strdel(&s1);
		if (which == 2)
			ft_strdel(&s2);
		return (ret);
	}
	return (NULL);
}
