#include <libft.h>

/*void				get_flag(t_prf *env)
{
}*/

void				get_field_width(t_prf *env)
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
    env->cur_specs.field_width = ft_atoi(ft_strsub(env->format, save, to_copy));
}

void				get_precision(t_prf *env)
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
        env->cur_specs.field_width = ft_atoi(ft_strsub(env->format, save, to_copy));
    }
}

/*void				get_conversion(t_prf *env)
{
}*/
