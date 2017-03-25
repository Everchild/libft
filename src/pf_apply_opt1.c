/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_opt1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 15:32:03 by sbrochar          #+#    #+#             */
/*   Updated: 2017/03/21 20:04:02 by sbrochar         ###   ########.fr       */
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
	char			to_fill;
	int				len;

	tmp = NULL;
	to_fill = ' ';
	len = ft_strlen(*result); // len = 6
	if (specs->precision > 0)
	{
		if (specs->precision > len)
			specs->precision = len;
		else
			len = specs->precision;
	}
	if (len < specs->field_width) // 6 < 10
		len = specs->field_width; // len = 10
	tmp = (char *)ft_memalloc(sizeof(char) * (len + 1)); // tmp = 10 charac
	ft_memset(tmp, to_fill, len); // tmp = "          "
	if (specs->flags & MINUS)
	{
		if (specs->precision > 0)
			tmp = ft_strncpy(tmp, *result, specs->precision);
		else
			tmp = ft_strncpy(tmp, *result, ft_strlen(*result) - 1); 
	}
	else
	{
		if (specs->precision > 0)
			tmp = ft_strncpy(tmp + (len - specs->precision), *result, specs->precision);
		else
		{
//			printf("tmp: [%s], len: %d, strlen(result): %d\n", tmp, len, ft_strlen(*result));
			tmp = ft_strncpy(tmp + (len - ft_strlen(*result)), *result, ft_strlen(*result));
		}
	}
//	ft_strdel(&(*result));
	*result = tmp;
}

/*void				opt_on_wstring(t_specs *specs, char **result)
{
}

void				opt_on_ptr(t_specs *specs, char **result)
{
}

void				opt_on_digit(t_specs *specs, char **result)
{
}

void				opt_on_octal(t_specs *specs, char **result)
{
}

void				opt_on_udigit(t_specs *specs, char **result)
{
}*/

void				opt_on_hexa(t_specs *specs, char **result)
{
	if (specs->conversion[ft_strlen(specs->conversion) - 1] == 'X')
		ft_strupper(result);
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
			tmp[0] = '%';
		else
			tmp[specs->field_width - 1] = *(result[0]);
		ft_strdel(&(*result));
		*result = tmp;
	}
}

/*void				opt_on_wchar(t_specs *specs, char **result)
{
}*/
