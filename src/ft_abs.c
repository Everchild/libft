/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:14:03 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/14 20:02:59 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_abs(long long n)
{
	if (n < 0)
		return (n *= -1);
	return (n);
}
