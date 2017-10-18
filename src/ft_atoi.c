/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:36:57 by sbrochar          #+#    #+#             */
/*   Updated: 2017/10/19 01:31:42 by sbrochar         ###   ########.fr       */
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
		*neg = -1;
		tmp += 1;
	}
	else if (*tmp == '+')
		tmp += 1;
	while (*tmp == '0')
		tmp++;
	tmp = ft_strdup(tmp);
	ft_strdel(&ret);
	return (tmp);
}

int					ft_atoi(const char *nptr)
{
	int				ret;
	long int		pow;
	int				neg;
	char			*n;
	int				i;

	ret = 0;
	neg = 1;
	i = 0;
	n = pre_atoi(nptr, &neg);
	pow = findpow(n);
	if (!pow)
		return (pow);
	while (pow >= 1)
	{
		ret = ret + (((n[i] - '0') * pow) * neg);
		pow /= 10;
		i++;
	}
	ft_strdel(&n);
	return (ret);
}
