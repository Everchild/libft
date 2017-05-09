/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctombc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:13:34 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/09 17:15:25 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_wctombc(wchar_t c)
{
	char			*ret;

	ret = (char *)ft_memalloc(sizeof(char) * 5);
	if (c <= 0x7f)
		ret[0] = c;
	else if (c <= 0x7ff)
	{
		ft_putendl("2 bytes");
		ret[0] = (c >> 6) | 0xc0;
		ret[1] = (c & 0x3f) | 0x80;
	}
	else if (c <= 0x7ffff)
	{
		ft_putendl("3 bytes");
		ret[0] = (c >> 12) | 0xe0;
		ret[1] = ((c >> 6) & 0x3f) | 0x80;
		ret[2] = (c & 0x3f) | 0x80;
	}
	else
	{
		ft_putendl("4 bytes");
		ret[0] = (c >> 18) | 0xf0;
		ret[1] = ((c >> 12) & 0x3f) | 0x80;
		ret[2] = ((c >> 6) & 0x3f) | 0x80;
		ret[3] = (c & 0x3f) | 0x80;
	}
	return (ret);
}
