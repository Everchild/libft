#include <libft.h>

static void			parsing_flag(t_prf *env)
{
	env->index++;
	if (env->format[env->index] == '%')
	{
		if (!(env->len_result % BUFF_SIZE))
			flush_buff(env->buff);
		ft_strcat(env->buff, "%");
	}
	else
	{
		if (!(env->len_result % BUFF_SIZE))
			flush_buff(env->buff);
		ft_strcat(env->buff, "(flag)");
	}
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
		while (env->format[env->index] && env->format[env->index] != '%' && to_copy < BUFF_SIZE)
		{
			env->index++;
			to_copy++;
		}
		ft_strncat(env->buff, env->format + save, to_copy);
		env->len_result += to_copy;
		if (env->format[env->index] == '%')
			parsing_flag(env);
		else if (!(env->len_result % BUFF_SIZE))
			flush_buff(env->buff);
	}
}
