/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:37:54 by sbrochar          #+#    #+#             */
/*   Updated: 2016/10/05 17:13:59 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*s;

	s = NULL;
	if (s1 && s2)
		s = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s1)
					+ ft_strlen(s2) + 1));
	if (s)
	{
		s = ft_strcpy(s, s1);
		s = ft_strcat(s, s2);
		return (s);
	}
	return (NULL);
}
