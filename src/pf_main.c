/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 17:50:27 by sbrochar          #+#    #+#             */
/*   Updated: 2017/03/15 17:49:38 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void			init_env(t_prf *env, const char *format)
{
	env->format = format;
	env->index = 0;
	env->buff = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
	ft_bzero(env->buff, BUFF_SIZE + 1);
	env->len_result = 0;
	env->cur_specs = (t_specs *)ft_memalloc(sizeof(t_specs) * 1);
}

int					ft_printf(const char *format, ...)
{
	t_prf			env;

	va_start(env.args, format);
	init_env(&env, format);
	formating_string(&env);
	ft_putstr(env.buff);
	va_end(env.args);
	ft_memdel((void **)&(env.cur_specs));
	return (env.len_result);
}
