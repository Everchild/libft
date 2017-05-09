/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_type1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 14:05:37 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/09 17:04:00 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void				treat_percent(t_prf *env, char **result)
{
	(void)env;
	*result = (char *)ft_memalloc(sizeof(char) * 2);
	*(result[0]) = '%';
}

void				treat_char(t_prf *env, char **result)
{
	char			to_format;

	if (env->cur_specs->conversion[ft_strlen(env->cur_specs->conversion) - 1] == 'c')
	{
		to_format = va_arg(env->args, int);
		*result = (char *)ft_memalloc(sizeof(char) * 2);
		*(result[0]) = to_format;
		if (!to_format)
			env->len_result++;
	}
	else
	{
		to_format = va_arg(env->args, int);
		*result = ft_itoa(to_format);
	}
		
}

void				treat_charp(t_prf *env, char **result)
{
	char			*to_format;

	to_format = va_arg(env->args, char *);
	if (to_format)
		*result = ft_strdup(to_format);
	else
		*result = ft_strdup("(null)");
}

void				treat_uchar(t_prf *env, char **result)
{
	unsigned char	to_format;

	to_format = va_arg(env->args, int);
	*result = ft_itoa_base(to_format, env->cur_specs->base);
}

void				treat_wchar(t_prf *env, char **result)
{
	wchar_t			to_format;

	to_format = va_arg(env->args, wchar_t);
	*result = ft_wctombc(to_format);
	if (!to_format)
		env->len_result++;
}

void				treat_wcharp(t_prf *env, char **result)
{
	wchar_t			*to_format;

	to_format = va_arg(env->args, wchar_t *);
	if (!to_format)
		*result = ft_strdup("(null)");
	else
	{
		*result = (char *)ft_memalloc(sizeof(char) * (ft_wstrlen(to_format) + 1));
		while (to_format && *to_format)
		{
			*result = ft_strcat(*result, ft_wctombc(*to_format));
			to_format++;
		}
	}
}

void				treat_ptr(t_prf *env, char **result)
{
	unsigned long int	to_format;

	to_format = va_arg(env->args, unsigned long int);
	*result = ft_itoa_base(to_format, env->cur_specs->base);
	*result = ft_strjoinf("0x", *result, 2);
}

void				treat_short(t_prf *env, char **result)
{
	short			to_format;

	to_format = va_arg(env->args, int);
	*result = ft_itoa(to_format);
}

void				treat_ushort(t_prf *env, char **result)
{
	unsigned short	to_format;

	to_format = va_arg(env->args, unsigned int);
	*result = ft_itoa_base(to_format, env->cur_specs->base);
}

void				treat_int(t_prf *env, char **result)
{
	int				to_format;

	to_format = va_arg(env->args, int);
	*result = ft_itoa(to_format);
}

void				treat_uint(t_prf *env, char **result)
{
	unsigned int	to_format;

	to_format = va_arg(env->args, unsigned int);
	*result = ft_itoa_base(to_format, env->cur_specs->base);
}

void				treat_long(t_prf *env, char **result)
{
	long			to_format;

	to_format = va_arg(env->args, long);
	*result = ft_itoa(to_format);
}

void				treat_ulong(t_prf *env, char **result)
{
	unsigned long	to_format;

	to_format = va_arg(env->args, unsigned long);
	*result = ft_itoa_base(to_format, env->cur_specs->base);
}

void				treat_long_long(t_prf *env, char **result)
{
	long long		to_format;

	to_format = va_arg(env->args, long long);
	*result = ft_itoa(to_format);
}

void				treat_ulong_long(t_prf *env, char **result)
{
	unsigned long long	to_format;

	to_format = va_arg(env->args, unsigned long long);
	*result = ft_itoa_base(to_format, env->cur_specs->base);
}

void				treat_intmax_t(t_prf *env, char **result)
{
	intmax_t		to_format;

	to_format = va_arg(env->args, intmax_t);
	*result = ft_itoa(to_format);
}

void				treat_uintmax_t(t_prf *env, char **result)
{
	uintmax_t		to_format;

	to_format = va_arg(env->args, uintmax_t);
	*result = ft_itoa_base(to_format, env->cur_specs->base);
}

void				treat_size_t(t_prf *env, char **result)
{
	size_t			to_format;

	to_format = va_arg(env->args, size_t);
	*result = ft_itoa_base(to_format, env->cur_specs->base);
}
