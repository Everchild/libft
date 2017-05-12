/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_specs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 16:44:00 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/13 01:13:32 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				get_flag(t_prf *env, t_specs *specs)
{
	while (env->format && env->format[env->index])
	{
		if (env->format[env->index] == '#')
			specs->flags |= HASHTAG;
		else if (env->format[env->index] == '0')
			specs->flags |= ZERO;
		else if (env->format[env->index] == '-')
			specs->flags |= MINUS;
		else if (env->format[env->index] == '+')
			specs->flags |= PLUS;
		else if (env->format[env->index] == ' ')
			specs->flags |= SPACE;
		else
			break ;
		env->index++;
	}
}

void				get_field_width(t_prf *env, t_specs *specs)
{
	size_t			save;
	size_t			to_copy;
	char			*tmp;

	save = env->index;
	to_copy = 0;
	if (env->format && env->format[env->index] && env->format[env->index] == '*')
	{
		env->index++;
		specs->field_width = va_arg(env->args, int);
	}
	else
	{
		while (env->format && env->format[env->index] && ft_isdigit(env->format[env->index]))
		{
			to_copy++;
			env->index++;
		}
		tmp = ft_strsub(env->format, save, to_copy);
		specs->field_width = ft_atoi(tmp);
		ft_strdel(&tmp);
	}
}

void				get_precision(t_prf *env, t_specs *specs)
{
	size_t			save;
	size_t			to_copy;
	char			*tmp;

	if (env->format && env->format[env->index] && env->format[env->index] == '.')
	{
		env->index++;
		if (env->format && env->format[env->index] && env->format[env->index] == '*')
		{
			env->index++;
			specs->precision = va_arg(env->args, int);
		}
		else
		{
			save = env->index;
			to_copy = 0;
			while (env->format && env->format[env->index] && ft_isdigit(env->format[env->index]))
			{
				to_copy++;
				env->index++;
			}
			if (to_copy)
			{
				tmp = ft_strsub(env->format, save, to_copy);
				specs->precision = ft_atoi(tmp);
				ft_strdel(&tmp);
			}
			else
				specs->precision = 0;
		}
	}
}

void				get_conversion(t_prf *env, t_specs *specs)
{
	size_t			save;
	size_t			to_copy;
	char			*tmp;

	save = env->index;
	if (!(env->format[env->index]) || (!ft_strchr(ALL_MODIFIERS, env->format[env->index]) && !ft_strchr(ALL_FORMATS, env->format[env->index])))
		return ;
	to_copy = 1;
	while (env->format && env->format[env->index] && !ft_strchr(ALL_FORMATS, env->format[env->index]))
	{
		env->index++;
		to_copy++;
	}
	if (to_copy <= PRF_LEN_MAX_CONV)
	{
		tmp = ft_strsub(env->format, save, to_copy);
		ft_strcpy(specs->conversion, tmp);
		ft_strdel(&tmp);
		specs->format = specs->conversion[to_copy - 1];
		if (specs->format == 'o' || specs->format == 'O')
			specs->base = 8;
		else if (specs->format == 'x' || specs->format == 'X' || specs->format == 'p')
			specs->base = 16;
	}
	env->index++;
}
