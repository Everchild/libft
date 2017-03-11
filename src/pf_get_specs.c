/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_specs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 16:44:00 by sbrochar          #+#    #+#             */
/*   Updated: 2017/03/11 16:44:02 by sbrochar         ###   ########.fr       */
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

	save = env->index;
	to_copy = 0;
	while (env->format && env->format[env->index] && ft_isdigit(env->format[env->index]))
	{
		to_copy++;
		env->index++;
	}
	specs->field_width = ft_atoi(ft_strsub(env->format, save, to_copy));
}

void				get_precision(t_prf *env, t_specs *specs)
{
	size_t			save;
	size_t			to_copy;

	if (env->format[env->index] == '.')
	{
		env->index++;
		save = env->index;
		to_copy = 0;
		while (env->format && env->format[env->index] && ft_isdigit(env->format[env->index]))
		{
			to_copy++;
			env->index++;
		}
		specs->precision = ft_atoi(ft_strsub(env->format, save, to_copy));
	}
}

void				get_conversion(t_prf *env, t_specs *specs)
{
	size_t			save;
	size_t			to_copy;

	save = env->index;
	to_copy = 1;
	while (env->format && env->format[env->index] && !ft_strchr(ALL_FORMATS, env->format[env->index]))
	{
		env->index++;
		to_copy++;
	}
	if (to_copy <= PRF_LEN_MAX_CONV)
		ft_strcpy(specs->conversion, ft_strsub(env->format, save, to_copy));
	env->index++;
}
