/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_batoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:36:57 by sbrochar          #+#    #+#             */
/*   Updated: 2017/12/13 18:05:49 by sbrochar         ###   ########.fr       */
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

static int			check_pow(long int pow, int *ptr, char **n)
{
	if (!pow)
	{
		ft_strdel(n);
		*ptr = pow;
		return (B_TRUE);
	}
	return (B_FALSE);
}

t_bool				ft_batoi(int *ptr, const char *nptr)
{
	long int		res;
	long int		pow;
	int				neg;
	char			*n;
	int				i;

	res = 0;
	neg = 1;
	i = 0;
	n = pre_atoi(nptr, &neg);
	pow = findpow(n);
	if (check_pow(pow, ptr, &n))
		return (B_TRUE);
	while (pow >= 1)
	{
		res = res + (((n[i] - '0') * pow) * neg);
		if (res > INT_MAX || res < INT_MIN)
			return (B_FALSE);
		pow /= 10;
		i++;
	}
	ft_strdel(&n);
	*ptr = res;
	return (B_TRUE);
}
