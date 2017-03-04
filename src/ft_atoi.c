/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:36:57 by sbrochar          #+#    #+#             */
/*   Updated: 2016/10/19 18:48:07 by sbrochar         ###   ########.fr       */
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

	ret = ft_strtrim(nptr);
	if (*ret == '-')
	{
		*neg = 1;
		ret += 1;
	}
	else if (*ret == '+')
		ret += 1;
	while (*ret == '0')
		ret++;
	return (ret);
}

int					ft_atoi(const char *nptr)
{
	int				ret;
	long int		pow;
	int				neg;
	char			*n;

	ret = 0;
	neg = 0;
	n = pre_atoi(nptr, &neg);
	pow = findpow(n);
	if (!pow)
		return (pow);
	while (pow >= 1)
	{
		ret = ret + ((*n - '0') * pow);
		pow /= 10;
		n += 1;
	}
	if (neg)
		ret *= -1;
	return (ret);
}
