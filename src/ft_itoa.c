/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:40:04 by sbrochar          #+#    #+#             */
/*   Updated: 2016/10/19 19:58:37 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int			findlen(long int n)
{
	int				ret;

	ret = 1;
	while (n >= 9)
	{
		n /= 10;
		ret += 1;
	}
	return (ret);
}

static void			doitoa(int len, long int n_abs, long int pow, char **ret)
{
	int				i;

	i = (((*ret)[0]) == '-') ? 1 : 0;
	while (i < len)
	{
		(*ret)[i] = (n_abs / pow) + '0';
		n_abs %= pow;
		pow /= 10;
		i++;
	}
}

char				*ft_itoa(int n)
{
	char			*ret;
	int				len;
	long int		pow;
	long int		n_abs;

	n_abs = ft_abs(n);
	len = findlen(n_abs);
	pow = ft_pow(10, len - 1);
	len += n < 0 ? 1 : 0;
	ret = ft_strnew(len);
	if (ret)
	{
		if (n < 0)
			ret[0] = '-';
		doitoa(len, n_abs, pow, &ret);
		return (ret);
	}
	return (NULL);
}
