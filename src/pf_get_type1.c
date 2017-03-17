/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_type1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 14:05:37 by sbrochar          #+#    #+#             */
/*   Updated: 2017/03/17 21:01:27 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void				apply_opt(t_specs *specs, char **result)
{
	char			format;
	char			*cpy;

	format = specs->conversion[ft_strlen(specs->conversion) - 1];
	cpy = ft_strdup(*result);
	if (format == 'X')
		ft_strupper(result);
	if ((specs->flags | HASHTAG) && (format == 'X' || format == 'x'))
		ft_memmove(*result, *result + 2);
}

void				treat_percent(t_prf *env)
{
	char			*result;

	result = (char *)ft_memalloc(sizeof(char)* 2);
	result[0] = '%';
	env->len_result += ft_strlen(result);
	apply_opt(env->cur_specs, &result);
	buff_handler(&env->buff, FILL, result);
	ft_strdel(&result);
}

void				treat_char(t_prf *env)
{
	char			to_format;
	char			*result;

	to_format = va_arg(env->args, int);
	result = (char *)ft_memalloc(sizeof(char)* 2);
	result[0] = to_format;
	env->len_result += ft_strlen(result);
	apply_opt(env->cur_specs, &result);
	buff_handler(&env->buff, FILL, result);
	ft_strdel(&result);
}

void				treat_charp(t_prf *env)
{
	char			*to_format;

	to_format = va_arg(env->args, char *);
	env->len_result += ft_strlen(to_format);
	apply_opt(env->cur_specs, &to_format);
	buff_handler(&env->buff, FILL, to_format);
}

void				treat_uchar(t_prf *env)
{
	unsigned char	to_format;
	char			*result;

	to_format = va_arg(env->args, int);
	result = ft_itoa_base(to_format, env->cur_specs->base);
	env->len_result += ft_strlen(result);
	apply_opt(env->cur_specs, &result);
	buff_handler(&env->buff, FILL, result);
	ft_strdel(&result);
}

void				treat_wchar(t_prf *env)
{
/*	wchar_t			to_format;

	to_format = va_arg(env->args, wchar_t);*/
	buff_handler(&env->buff, FILL, "(wide char)");
}

void				treat_wcharp(t_prf *env)
{
/*	wchar_t			*to_format;

	to_format = va_arg(env->args, wchar_t *);*/
	buff_handler(&env->buff, FILL, "(wide char *)");
}

void				treat_ptr(t_prf *env)
{
/*		to_format;

	to_format = va_arg(env->args, );*/
	buff_handler(&env->buff, FILL, "(pointer)");
}

void				treat_short(t_prf *env)
{
	short			to_format;
	char			*result;

	to_format = va_arg(env->args, int);
	result = ft_itoa(to_format);
	env->len_result += ft_strlen(result);
	apply_opt(env->cur_specs, &result);
	buff_handler(&env->buff, FILL, result);
	ft_strdel(&result);
}

void				treat_ushort(t_prf *env)
{
	unsigned short	to_format;
	char			*result;

	to_format = va_arg(env->args, unsigned int);
	result = ft_itoa_base(to_format, env->cur_specs->base);
	env->len_result += ft_strlen(result);
	apply_opt(env->cur_specs, &result);
	buff_handler(&env->buff, FILL, result);
	ft_strdel(&result);
}

void				treat_int(t_prf *env)
{
	int				to_format;
	char			*result;

	to_format = va_arg(env->args, int);
	result = ft_itoa(to_format);
	env->len_result += ft_strlen(result);
	apply_opt(env->cur_specs, &result);
	buff_handler(&env->buff, FILL, result);
	ft_strdel(&result);
}

void				treat_uint(t_prf *env)
{
	unsigned int	to_format;
	char			*result;

	to_format = va_arg(env->args, unsigned int);
	result = ft_itoa_base(to_format, env->cur_specs->base);
	env->len_result += ft_strlen(result);
	apply_opt(env->cur_specs, &result);
	buff_handler(&env->buff, FILL, result);
	ft_strdel(&result);
}

void				treat_long(t_prf *env)
{
	long			to_format;
	char			*result;

	to_format = va_arg(env->args, long);
	result = ft_itoa(to_format);
	env->len_result += ft_strlen(result);
	apply_opt(env->cur_specs, &result);
	buff_handler(&env->buff, FILL, result);
	ft_strdel(&result);
}

void				treat_ulong(t_prf *env)
{
	unsigned long	to_format;
	char			*result;

	to_format = va_arg(env->args, unsigned long);
	result = ft_itoa_base(to_format, env->cur_specs->base);
	env->len_result += ft_strlen(result);
	apply_opt(env->cur_specs, &result);
	buff_handler(&env->buff, FILL, result);
	ft_strdel(&result);
}

void				treat_long_long(t_prf *env)
{
	long long		to_format;
	char			*result;

	to_format = va_arg(env->args, long long);
	result = ft_itoa(to_format);
	env->len_result += ft_strlen(result);
	apply_opt(env->cur_specs, &result);
	buff_handler(&env->buff, FILL, result);
	ft_strdel(&result);
}

void				treat_ulong_long(t_prf *env)
{
	unsigned long long	to_format;
	char			*result;

	to_format = va_arg(env->args, unsigned long long);
	result = ft_itoa_base(to_format, env->cur_specs->base);
	env->len_result += ft_strlen(result);
	apply_opt(env->cur_specs, &result);
	buff_handler(&env->buff, FILL, result);
	ft_strdel(&result);
}

void				treat_intmax_t(t_prf *env)
{
	intmax_t		to_format;
	char			*result;

	to_format = va_arg(env->args, intmax_t);
	result = ft_itoa(to_format);
	env->len_result += ft_strlen(result);
	apply_opt(env->cur_specs, &result);
	buff_handler(&env->buff, FILL, result);
	ft_strdel(&result);
}

void				treat_uintmax_t(t_prf *env)
{
	uintmax_t		to_format;
	char			*result;

	to_format = va_arg(env->args, uintmax_t);
	result = ft_itoa_base(to_format, env->cur_specs->base);
	env->len_result += ft_strlen(result);
	apply_opt(env->cur_specs, &result);
	buff_handler(&env->buff, FILL, result);
	ft_strdel(&result);
}

void				treat_size_t(t_prf *env)
{
	size_t			to_format;
	char			*result;

	to_format = va_arg(env->args, size_t);
	result = ft_itoa_base(to_format, env->cur_specs->base);
	env->len_result += ft_strlen(result);
	apply_opt(env->cur_specs, &result);
	buff_handler(&env->buff, FILL, result);
	ft_strdel(&result);
}
