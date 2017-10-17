/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_batoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:36:57 by sbrochar          #+#    #+#             */
/*   Updated: 2017/10/17 22:15:16 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static long int		findpow(const char *nptr)
{
	long int		ret;

	ret = 0;
	while (ft_isdigit(*nptr))
	{
		if (!ret)
			ret = 1;
		else
			ret *= 10;
		nptr += 1;
	}
	return (ret);
}

static char			*pre_atoi(const char *nptr, int *neg)
{
	char			*ret;
	char			*tmp;

	ret = ft_strtrim(nptr);
	tmp = ret;
	if (*tmp == '-')
	{
		*neg = 1;
		tmp += 1;
	}
	else if (*tmp == '+')
		tmp += 1;
	while (*tmp == '0')
		tmp++;
	ft_strdel(&ret);
	return (tmp);
}

t_bool				ft_batoi(int *ptr, const char *nptr)
{
	long int		res;
	long int		pow;
	int				neg;
	char			*n;
	int				i;

	res = 0;
	neg = 0;
	i = 0;
	n = pre_atoi(nptr, &neg);
	pow = findpow(n);
	if (!pow)
		return (pow);
	while (pow >= 1)
	{
		res = res + ((n[i] - '0') * pow);
		if (res > INT_MAX || res < INT_MIN)
			return (B_FALSE);
		pow /= 10;
		i++;
	}
	if (neg)
		res *= -1;
	*ptr = res;
	return (B_TRUE);
}
