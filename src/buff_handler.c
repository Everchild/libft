#include <libft.h>

static void         flush_buff(char *buff)
{
    if (buff)
    {
        ft_putstr(buff);
        ft_bzero(buff, BUFF_SIZE + 1);
    }
}

static void         fill_buff(char *buff, char *s)
{
    flush_buff(buff);
    while (s && *s)
    {
        ft_strncpy(buff, s, BUFF_SIZE);
        s += BUFF_SIZE;
        flush_buff(buff);
    }
}

void				buff_handler(char *buff, int action, char *s)
{
    if (buff)
    {
        if (action == FILL)
            fill_buff(buff, s);
        else if (action == FLUSH)
            flush_buff(buff);
    }
}
