#include <libft.h>

void				flush_buff(char *buff)
{
	if (buff)
	{
		ft_putstr(buff);
		ft_bzero(buff, ft_strlen(buff) + 1);
	}
}
