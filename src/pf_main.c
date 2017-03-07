/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 17:50:27 by sbrochar          #+#    #+#             */
/*   Updated: 2017/03/04 19:20:35 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			    init_specs(t_specs *specs)
{
	specs->flags = 0;
	specs->field_width = -1;
	specs->precision = -1;
	ft_bzero(specs->conversion, PRF_LEN_MAX_CONV + 1);
}

int					ft_printf(const char *format, ...)
{
	t_prf			env;

	env.format = format;
	env.index = 0;
	va_start(env.args, format);
	ft_bzero(env.buff, BUFF_SIZE + 1);
	env.len_result = 0;
	parsing_format(&env);
	buff_handler(env.buff, FLUSH, NULL);
	va_end(env.args);
	return (env.len_result);
}
