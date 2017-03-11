#include <libft.h>

void				treat_char(t_prf *env)
{
/*	char			to_format;

	to_format = va_arg(env->args, char);*/
	buff_handler(env->buff, FILL, "(char)");
}

void				treat_charp(t_prf *env)
{
/*	char			*to_format;

	to_format = va_arg(env->args, char *);*/
	buff_handler(env->buff, FILL, "(char *)");
}

void				treat_uchar(t_prf *env)
{
/*	unsigned char	to_format;

	to_format = va_arg(env->args, unsigned char);*/
	buff_handler(env->buff, FILL, "(unsigned char)");
}

void				treat_wchar(t_prf *env)
{
/*	wchar_t			to_format;

	to_format = va_arg(env->args, wchar_t);*/
	buff_handler(env->buff, FILL, "(wide char)");
}

void				treat_wcharp(t_prf *env)
{
/*	wchar_t			*to_format;

	to_format = va_arg(env->args, wchar_t *);*/
	buff_handler(env->buff, FILL, "(wide char *)");
}

void				treat_ptr(t_prf *env)
{
/*		to_format;

	to_format = va_arg(env->args, );*/
	buff_handler(env->buff, FILL, "(pointer)");
}

void				treat_short(t_prf *env)
{
/*	short			to_format;

	to_format = va_arg(env->args, short);*/
	buff_handler(env->buff, FILL, "(short)");
}

void				treat_ushort(t_prf *env)
{
/*	unsigned short	to_format;

	to_format = va_arg(env->args, unsigned short);*/
	buff_handler(env->buff, FILL, "(unsigned short)");
}

void				treat_int(t_prf *env)
{
/*	int				to_format;

	to_format = va_arg(env->args, int);*/
	buff_handler(env->buff, FILL, "(int)");
}

void				treat_uint(t_prf *env)
{
/*	unsigned int	to_format;

	to_format = va_arg(env->args, unsigned int);*/
	buff_handler(env->buff, FILL, "(unsigned int)");
}

void				treat_long(t_prf *env)
{
/*	long			to_format;

	to_format = va_arg(env->args, long);*/
	buff_handler(env->buff, FILL, "(long)");
}

void				treat_ulong(t_prf *env)
{
/*	unsigned long	to_format;

	to_format = va_arg(env->args, unsigned long);*/
	buff_handler(env->buff, FILL, "(unsigned long)");
}

void				treat_long_long(t_prf *env)
{
/*	long long		to_format;

	to_format = va_arg(env->args, long long);*/
	buff_handler(env->buff, FILL, "(long long)");
}

void				treat_ulong_long(t_prf *env)
{
/*	unsigned long long	to_format;

	to_format = va_arg(env->args, unsigned long long);*/
	buff_handler(env->buff, FILL, "(unsigned long long)");
}

void				treat_intmax_t(t_prf *env)
{
/*				to_format;

	to_format = va_arg(env->args, );*/
	buff_handler(env->buff, FILL, "(intmax_t)");
}

void				treat_uintmax_t(t_prf *env)
{
/*				to_format;

	to_format = va_arg(env->args, );*/
	buff_handler(env->buff, FILL, "(uintmax_t)");
}

void				treat_size_t(t_prf *env)
{
/*				to_format;

	to_format = va_arg(env->args, );*/
	buff_handler(env->buff, FILL, "(size_t)");
}
