/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_opt1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 15:32:03 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/13 01:43:12 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

void				opt_on_percent(t_prf *env, t_specs *specs, char **orig_s)
{
	char			*result;
	char			to_fill;

	to_fill = ' ';
	if (specs->field_width > 0)
	{
		result = (char *)ft_memalloc(sizeof(char) * (specs->field_width) + 1);
		if (specs->flags & ZERO)
			to_fill = '0';
		ft_memset(result, to_fill, specs->field_width);
		if (specs->flags & MINUS)
			result[0] = '%';
		else
			result[specs->field_width - 1] = '%';
	}
	else
		result = ft_strdup(*orig_s);
	buff_handler(&env->buff, FILL, result);
	env->len_result += ft_strlen(result);
	ft_strdel(orig_s);
	ft_strdel(&result);
}

void				opt_on_string(t_prf *env, t_specs *specs, char **orig_s)
{
	char			*result;
	int				len;
	int				orig_len;
	char			to_fill;

	orig_len = ft_strlen(*orig_s);
	len = specs->field_width > orig_len ? specs->field_width : orig_len;
	to_fill = specs->flags & ZERO ? '0' : ' ';
	result = (char *)ft_memalloc(sizeof(char) * (len + 1));
	ft_memset(result, to_fill, len);
	if (specs->flags & MINUS)
		result = ft_strncpy(result, *orig_s, orig_len); 
	else
		ft_strncpy(result + (len - orig_len), *orig_s, orig_len);
	buff_handler(&env->buff, FILL, result);
	env->len_result += ft_strlen(result);
	ft_strdel(orig_s);
	ft_strdel(&result);
}

void				opt_on_wstring(t_prf *env, t_specs *specs, char **orig_s)
{
	char			*result;
	int				len;
	int				orig_len;
	char			to_fill;

	orig_len = ft_strlen(*orig_s);
	len = specs->field_width > orig_len ? specs->field_width : orig_len;
	to_fill = specs->flags & ZERO ? '0' : ' ';
	result = (char *)ft_memalloc(sizeof(char) * (len + 1));
	ft_memset(result, to_fill, len);
	if (specs->flags & MINUS)
		result = ft_strncpy(result, *orig_s, orig_len);
	else
		ft_strncpy(result + (len - orig_len), *orig_s, orig_len);
	buff_handler(&env->buff, FILL, result);
	env->len_result += ft_strlen(result);
	ft_strdel(orig_s);
	ft_strdel(&result);
}

void				opt_on_ptr(t_prf *env, t_specs *specs, char **orig_s)
{
	char			*result;
	size_t			len;
	int				orig_len;

	orig_len = ft_strlen(*orig_s);
	len = specs->field_width > orig_len ? specs->field_width : orig_len;
	result = (char *)ft_memalloc(sizeof(char) * (len + 1));
	ft_memset(result, ' ', len);
	if (specs->flags & MINUS)
		result = ft_strncpy(result, *orig_s, orig_len);
	else
		ft_strncpy(result + (len - orig_len), *orig_s, orig_len);
	buff_handler(&env->buff, FILL, result);
	env->len_result += ft_strlen(result);
	ft_strdel(orig_s);
	ft_strdel(&result);
}

void				opt_on_digit(t_prf *env, t_specs *specs, char **orig_s)
{
	char			*result;
	int 			len;
	int				orig_len;

	if (specs->flags & PLUS && !ft_strchr(*orig_s, '-'))
		*orig_s = ft_strjoinf("+", *orig_s, 2);
	else if (specs->flags & SPACE && !ft_strchr(*orig_s, '-'))
		*orig_s = ft_strjoinf(" ", *orig_s, 2);
	orig_len = ft_strlen(*orig_s);
	len = specs->field_width > orig_len ? specs->field_width : orig_len;
	result = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (specs->flags & ZERO && !(specs->flags & MINUS) && specs->precision < 0)
		ft_memset(result, '0', len);
	else
		ft_memset(result, ' ', len);
	if (specs->flags & MINUS)
		result = ft_strncpy(result, *orig_s, orig_len);
	else
		ft_strncpy(result + (len - orig_len), *orig_s, orig_len);
	ft_strdel(orig_s);
	if (specs->flags & ZERO && ((*orig_s = ft_strchr(result, '+')) != 0) && result != *orig_s)
	{
		**orig_s = '0';
		*result = '+';
	}
	else if (specs->flags & ZERO && ((*orig_s = ft_strchr(result, '-')) != 0) && result != *orig_s)
	{
		**orig_s = '0';
		*result = '-';
	}
	else if (specs->flags & ZERO && ((*orig_s = ft_strchr(result, ' ')) != 0) && result != *orig_s && !(specs->flags & MINUS))
	{
		**orig_s = '0';
		*result = ' ';
	}
	buff_handler(&env->buff, FILL, result);
	env->len_result += ft_strlen(result);
	ft_strdel(&result);
}

void				opt_on_octal(t_prf *env, t_specs *specs, char **orig_s)
{
	char			*result;
	size_t			len;
	int				orig_len;

	if (specs->flags & HASHTAG && **orig_s != '0')
		*orig_s = ft_strjoinf("0", *orig_s, 2);
	orig_len = ft_strlen(*orig_s);
	len = specs->field_width > orig_len ? specs->field_width : orig_len;
	result = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (specs->flags & ZERO && !(specs->flags & MINUS))
		ft_memset(result, '0', len);
	else
		ft_memset(result, ' ', len);
	if (specs->flags & MINUS)
		result = ft_strncpy(result, *orig_s, orig_len);
	else
		ft_strncpy(result + (len - orig_len), *orig_s, orig_len);
	buff_handler(&env->buff, FILL, result);
	env->len_result += ft_strlen(result);
	ft_strdel(orig_s);
	ft_strdel(&result);
}

void				opt_on_udigit(t_prf *env, t_specs *specs, char **orig_s)
{
	char			*result;
	size_t			len;
	int				orig_len;

	orig_len = ft_strlen(*orig_s);
	len = specs->field_width > orig_len ? specs->field_width : orig_len;
	result = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (specs->flags & ZERO && !(specs->flags & MINUS))
		ft_memset(result, '0', len);
	else
		ft_memset(result, ' ', len);
	if (specs->flags & MINUS)
		result = ft_strncpy(result, *orig_s, orig_len);
	else
		ft_strncpy(result + (len - orig_len), *orig_s, orig_len);
	buff_handler(&env->buff, FILL, result);
	env->len_result += ft_strlen(result);
	ft_strdel(orig_s);
	ft_strdel(&result);
}

void				opt_on_hexa(t_prf *env, t_specs *specs, char **orig_s)
{
	char			*result;
	int 			len;
	int				orig_len;

	if (!ft_strcmp(*orig_s, "0") && specs->flags & HASHTAG)
		specs->flags &= ~HASHTAG;
	if (**orig_s && specs->flags & HASHTAG)
		*orig_s = ft_strjoinf("0x", *orig_s, 2);
	orig_len = ft_strlen(*orig_s);
	len = specs->field_width > orig_len ? specs->field_width : orig_len;
	result = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (specs->flags & ZERO && !(specs->flags & MINUS) && specs->precision < 0)
		ft_memset(result, '0', len);
	else
		ft_memset(result, ' ', len);
	if (specs->flags & MINUS)
		result = ft_strncpy(result, *orig_s, orig_len);
	else
		ft_strncpy(result + (len - orig_len), *orig_s, orig_len);
	if (specs->format == 'X')
		ft_strupper(&result);
	ft_strdel(orig_s);
	if (specs->flags & ZERO && (*orig_s = ft_strchr(result, 'x')) != 0)
	{
		**orig_s = '0';
		result[1] = 'x';
	}
	buff_handler(&env->buff, FILL, result);
	env->len_result += ft_strlen(result);
	ft_strdel(&result);
}

void				opt_on_char(t_prf *env, t_specs *specs, char **orig_s)
{
	char			*result;
	char			to_fill;

	to_fill = ' ';
	if (specs->field_width > 0)
	{
		result = (char *)ft_memalloc(sizeof(char) * (specs->field_width) + 1);
		if (specs->flags & ZERO)
			to_fill = '0';
		ft_memset(result, to_fill, specs->field_width);
		if (specs->flags & MINUS)
			result[0] = *(orig_s[0]);
		else
			result[specs->field_width - 1] = *(orig_s[0]);
	}
	else
		result = ft_strdup(*orig_s);
	if (env->null_char && specs->flags & MINUS)
	{
		env->len_result += ft_strlen(result);
		buff_handler(&env->buff, FLUSH, NULL);
		write(1, "\0", 1);
		env->null_char = FALSE;
	}
	else if (env->null_char)
	{
		env->len_result += ft_strlen(result);
		buff_handler(&env->buff, FILL, result);
		buff_handler(&env->buff, FLUSH, NULL);
		write(1, "\0", 1);
		env->null_char = FALSE;
	}
	else
	{
		buff_handler(&env->buff, FILL, result);
		env->len_result += ft_strlen(result);
	}
	ft_strdel(orig_s);
	ft_strdel(&result);
}

void				opt_on_wchar(t_prf *env, t_specs *specs, char **orig_s)
{
	char			*result;
	int				orig_len;
	int				len;

	orig_len = ft_strlen(*orig_s);
	len = specs->field_width > orig_len ? specs->field_width : orig_len;
	result = (char *)ft_memalloc(sizeof(char) * (len + 1));
	ft_memset(result, ' ', len);
	if (specs->flags & MINUS)
		result = ft_strncpy(result, *orig_s, len);
	else	
		ft_strncpy(result + (len - orig_len), *orig_s, orig_len);
	if (env->null_char && specs->flags & MINUS)
	{
		env->len_result += ft_strlen(result);
		buff_handler(&env->buff, FLUSH, NULL);
		write(1, "\0", 1);
		env->null_char = FALSE;
	}
	else if (env->null_char)
	{
		env->len_result += ft_strlen(result);
		buff_handler(&env->buff, FILL, result);
		buff_handler(&env->buff, FLUSH, NULL);
		write(1, "\0", 1);
		env->null_char = FALSE;
	}
	else
	{
		buff_handler(&env->buff, FILL, result);
		env->len_result += ft_strlen(result);
	}
	ft_strdel(orig_s);
	ft_strdel(&result);
}
