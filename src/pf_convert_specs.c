/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_specs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 13:42:36 by sbrochar          #+#    #+#             */
/*   Updated: 2017/03/26 22:34:14 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static t_options	*get_all_formats(void)
{
	static t_options	ret[F_COUNT] = {
	{ F_PERCENT, "%", &opt_on_percent },
	{ F_STRING, "s", &opt_on_string },
/*	{ F_WSTRING, "S", &opt_on_wstring },
	{ F_PTR, "p", &opt_on_ptr },*/
	{ F_DIGIT, "dDi", &opt_on_digit },
	{ F_OCTAL, "oO", &opt_on_octal },
	{ F_UDIGIT, "uU", &opt_on_udigit },
	{ F_HEXA, "xX", &opt_on_hexa },
	{ F_CHAR, "c", &opt_on_char }/*,
	{ F_WCHAR, "C", &opt_on_wchar }*/
	};

	return (ret);
}
static t_conversion	*get_all_funcs(void)
{
	static t_conversion	ret[C_COUNT] = {
	{ C_PERCENT, "%", &treat_percent },
	{ C_CHAR, "chhdhhi", &treat_char },
	{ C_CHARP, "s", &treat_charp },
	{ C_UCHAR, "hhuhhohhxhhX", &treat_uchar },
	{ C_WCHAR, "lcC", &treat_wchar },
	{ C_WCHARP, "lsS", &treat_wcharp },
	{ C_PTR, "p", &treat_ptr },
	{ C_SHORT, "hdhi", &treat_short },
	{ C_USHORT, "huhohxhX", &treat_ushort },
	{ C_INT, "di", &treat_int },
	{ C_UINT, "ouxX", &treat_uint },
	{ C_LONG, "ldliD", &treat_long },
	{ C_ULONG, "luUloOlxlX", &treat_ulong },
	{ C_LONG_LONG, "lldlli", &treat_long_long },
	{ C_ULONG_LONG, "llullollxllX", &treat_ulong_long },
	{ C_INTMAX_T, "jdji", &treat_intmax_t },
	{ C_UINTMAX_T, "jujojxjX", &treat_uintmax_t },
	{ C_SIZE_T, "zdzizuzozxzX", &treat_size_t }
	};

	return (ret);
}

void				convert_specs(t_prf *env)
{
	t_conversion	*all_formats;
	int				i;
	char			*ptr;

	ptr = NULL;
	all_formats = get_all_funcs();
	if (!*(env->cur_specs->conversion))
		buff_handler(&env->buff, FILL, "(error)");
	else
	{
		i = 0;
		while (i < C_COUNT)
		{
			if ((ptr = ft_strstr(all_formats[i].conv_list, env->cur_specs->conversion)))
			{
				if (!(ptr - 1 && (*(ptr - 1) == 'h' || *(ptr - 1) == 'l'
					|| *(ptr - 1) == 'j' || *(ptr - 1) == 'z')))
				{
					all_formats[i].treat_type(env, &env->cur_specs->result);
					break ;
				}
			}
			i++;
		}
		if (!ptr)
			buff_handler(&env->buff, FILL, "(error)");
	}
}

void				apply_opt(t_prf *env)
{
	t_options		*options;
	int				i;
	char			format;

	options = get_all_formats();
	i = 0;
	format = env->cur_specs->conversion[ft_strlen(env->cur_specs->conversion) - 1];
	while (i < F_COUNT)
	{
		if (ft_strchr(options[i].formats, format))
		{
			options[i].apply_opt(env->cur_specs, &env->cur_specs->result);
			break ;
		}
		i++;
	}
}
