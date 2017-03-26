/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_opt1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 15:32:03 by sbrochar          #+#    #+#             */
/*   Updated: 2017/03/26 22:34:17 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				opt_on_percent(t_specs *specs, char **result)
{
	char			*tmp;
	char			to_fill;

	to_fill = ' ';
	if (specs->field_width > 0)
	{
		tmp = (char *)ft_memalloc(sizeof(char) * (specs->field_width) + 1);
		if (specs->flags & ZERO)
			to_fill = '0';
		ft_memset(tmp, to_fill, specs->field_width);
		if (specs->flags & MINUS)
			tmp[0] = '%';
		else
			tmp[specs->field_width - 1] = '%';
		ft_strdel(&(*result));
		*result = tmp;
	}
}

void				opt_on_string(t_specs *specs, char **result)
{
	char			*tmp;
	int				len;

	tmp = NULL;
	len = ft_strlen(*result);
	if (specs->precision > len)
		specs->precision = len;
	else if (specs->precision > 0)
		len = specs->precision;
	if (len < specs->field_width)
		len = specs->field_width;
	tmp = (char *)ft_memalloc(sizeof(char) * (len + 1));
	ft_memset(tmp, ' ', len);
	if ((specs->flags & MINUS) && specs->precision > 0)
		tmp = ft_strncpy(tmp, *result, specs->precision);
	else if (specs->flags & MINUS)
		tmp = ft_strncpy(tmp, *result, ft_strlen(*result)); 
	else if (specs->precision > 0)
		ft_strncpy(tmp + (len - specs->precision), *result, specs->precision);
	else
		ft_strncpy((tmp + (len - ft_strlen(*result))), *result, ft_strlen(*result));
	ft_strdel(&(*result));
	*result = tmp;
}

/*void				opt_on_wstring(t_specs *specs, char **result)
{
}

void				opt_on_ptr(t_specs *specs, char **result)
{
}*/

void				opt_on_digit(t_specs *specs, char **result)
{
	char			*tmp;
	size_t			len;
	int				orig_len;

	if (specs->flags & PLUS && *(result[0]) != '-')
		*result = ft_strjoinf("+", *result, 2);
	else if (specs->flags & SPACE && *(result[0]) != '-')
		*result = ft_strjoinf(" ", *result, 2);
	orig_len = ft_strlen(*result);
	len = 0;
	if (orig_len > specs->precision && orig_len > specs->field_width)
		len = orig_len;
	else if (specs->precision > specs->field_width)
		len = specs->precision;
	else if (specs->field_width > specs->precision)
		len = specs->field_width;
	tmp = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (specs->flags & ZERO && !(specs->flags & MINUS))
		ft_memset(tmp, '0', len);
	else
		ft_memset(tmp, ' ', len);
	if (specs->flags & MINUS)
	{
		if (specs->precision > 0)
		{
			ft_memset(tmp, '0', specs->precision);
			ft_strncpy(tmp + (specs->precision - orig_len), *result, orig_len);
		}
		else
			tmp = ft_strncpy(tmp, *result, orig_len);
	}
	else
	{
		if (specs->precision > 0)
			ft_memset(tmp + (len - specs->precision), '0', specs->precision);
		ft_strncpy(tmp + (len - orig_len), *result, orig_len);
	}
	ft_strdel(result);
	*result = tmp;
}

void				opt_on_octal(t_specs *specs, char **result)
{
	char			*tmp;
	size_t			len;
	int				orig_len;

	if (specs->flags & HASHTAG && ft_strcmp("0", *result))
		*result = ft_strjoinf("0", *result, 2);
	orig_len = ft_strlen(*result);
	len = 0;
	if (orig_len > specs->precision && orig_len > specs->field_width)
		len = orig_len;
	else if (specs->precision > specs->field_width)
		len = specs->precision;
	else if (specs->field_width > specs->precision)
		len = specs->field_width;
	tmp = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (specs->flags & ZERO && !(specs->flags & MINUS))
		ft_memset(tmp, '0', len);
	else
		ft_memset(tmp, ' ', len);
	if (specs->flags & MINUS)
	{
		if (specs->precision > 0)
		{
			ft_memset(tmp, '0', specs->precision);
			ft_strncpy(tmp + (specs->precision - orig_len), *result, orig_len);
		}
		else
			tmp = ft_strncpy(tmp, *result, orig_len);
	}
	else
	{
		if (specs->precision > 0)
			ft_memset(tmp + (len - specs->precision), '0', specs->precision);
		ft_strncpy(tmp + (len - orig_len), *result, orig_len);
	}
		ft_strdel(result);
		*result = tmp;
}

void				opt_on_udigit(t_specs *specs, char **result)
{
	char			*tmp;
	size_t			len;
	int				orig_len;

	orig_len = ft_strlen(*result);
	len = 0;
	if (orig_len > specs->precision && orig_len > specs->field_width)
		len = orig_len;
	else if (specs->precision > specs->field_width)
		len = specs->precision;
	else if (specs->field_width > specs->precision)
		len = specs->field_width;
	tmp = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (specs->flags & ZERO && !(specs->flags & MINUS))
		ft_memset(tmp, '0', len);
	else
		ft_memset(tmp, ' ', len);
	if (specs->flags & MINUS)
	{
		if (specs->precision > 0)
		{
			ft_memset(tmp, '0', specs->precision);
			ft_strncpy(tmp + (specs->precision - orig_len), *result, orig_len);
		}
		else
			tmp = ft_strncpy(tmp, *result, orig_len);
	}
	else
	{
		if (specs->precision > 0)
			ft_memset(tmp + (len - specs->precision), '0', specs->precision);
		ft_strncpy(tmp + (len - orig_len), *result, orig_len);
	}
	ft_strdel(result);
	*result = tmp;
}
//precision
//options
//field width
void				opt_on_hexa(t_specs *specs, char **result)
{
	char			*tmp;
	size_t			len;
	int				orig_len;

	if ((specs->flags) & HASHTAG && ft_strcmp("0", *result))
		*result = ft_strjoinf("0x", *result, 2);
	orig_len = ft_strlen(*result);
	len = 0;
	if (orig_len > specs->precision && orig_len > specs->field_width)
		len = orig_len;
	else if (specs->precision > specs->field_width)
		len = specs->precision;
	else if (specs->field_width > specs->precision)
		len = specs->field_width;
	tmp = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (specs->flags & ZERO && !(specs->flags & MINUS))
		ft_memset(tmp, '0', len);
	else
		ft_memset(tmp, ' ', len);
//	printf("len: %zu, tmp: [%s]\n", len, tmp);
	if (specs->flags & MINUS)
	{
		if (specs->precision > 0)
		{
			ft_memset(tmp, '0', specs->precision);
			ft_strncpy(tmp + (specs->precision - orig_len), *result, orig_len);
		}
		else
			tmp = ft_strncpy(tmp, *result, orig_len);
	}
	else
	{
		if (specs->precision > 0)
			ft_memset(tmp + (len - specs->precision), '0', specs->precision);
		ft_strncpy(tmp + (len - orig_len), *result, orig_len);
	}
	if (specs->conversion[ft_strlen(specs->conversion) - 1] == 'X')
		ft_strupper(&tmp);
	ft_strdel(result);
	*result = tmp;
}

void				opt_on_char(t_specs *specs, char **result)
{
	char			*tmp;
	char			to_fill;

	to_fill = ' ';
	if (specs->field_width > 0)
	{
		tmp = (char *)ft_memalloc(sizeof(char) * (specs->field_width) + 1);
		if (specs->flags & ZERO)
			to_fill = '0';
		ft_memset(tmp, to_fill, specs->field_width);
		if (specs->flags & MINUS)
			tmp[0] = *(result[0]);
		else
			tmp[specs->field_width - 1] = *(result[0]);
		ft_strdel(&(*result));
		*result = tmp;
	}
}

/*void				opt_on_wchar(t_specs *specs, char **result)
{
}*/
