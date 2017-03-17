/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:40:04 by sbrochar          #+#    #+#             */
/*   Updated: 2017/03/17 16:05:47 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t		findlen(long long n)
{
	int				ret;

	ret = 1;
	while (n > 9)
	{
		n /= 10;
		ret += 1;
	}
	return (ret);
}

char				*ft_itoa(long long n)
{
	char				*ret;
	size_t				len;
	size_t				i;
	unsigned long long	n_abs;

	n_abs = ft_abs(n);
	len = findlen(n_abs);
	len += n < 0 ? 1 : 0;
	ret = ft_strnew(len);
	i = 0;
	if (ret)
	{
		if (n < 0)
		{
			ret[len - 1] = '-';
			len--;
		}
		while (i < len)
		{
			ret[i] = (n_abs % 10) + '0';
			n_abs /= 10;
			i++;
		}
		ft_strrev(&ret);
		return (ret);
	}
	return (NULL);
}
