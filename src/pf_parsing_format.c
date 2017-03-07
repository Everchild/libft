#include <libft.h>

static void			parsing_flag(t_prf *env)
{
	env->index++;
	if (env->format[env->index] == '%')
        buff_handler(env->buff, FILL, "%");
	else
    {
        init_specs(&(env->cur_specs));
//        get_flag(env);
        get_field_width(env);
        get_precision(env);
//        get_conversion(env);
    }
    buff_handler(env->buff, FILL, "(flag)");
	env->index++;
}

void				parsing_format(t_prf *env)
{
	size_t			save;
	size_t			to_copy;

	while (env->format && env->format[env->index])
	{
		to_copy = 0;
		save = env->index;
		while (env->format[env->index] && env->format[env->index] != '%')
		{
			env->index++;
			to_copy++;
		}
		buff_handler(env->buff, FILL, ft_strsub(env->format, save, to_copy));
		env->len_result += to_copy;
		if (env->format[env->index] == '%')
			parsing_flag(env);
	}
}
