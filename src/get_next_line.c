/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 14:06:18 by sbrochar          #+#    #+#             */
/*   Updated: 2018/02/02 18:32:53 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>

static int			process_old_data(char buf[BUFF_SIZE], char **line,
		size_t *size)
{
	int				posline;
	int				posbuf;

	if (buf[0])
	{
		*line = (char *)ft_memdup(buf, BUFF_SIZE);
		if (!*line)
			return (GNL_ER_MALLOC);
		posline = ft_strnpos(*line, '\n', BUFF_SIZE);
		posbuf = ft_strnpos(buf, '\n', BUFF_SIZE);
		if (posline >= 0)
		{
			ft_bzero(*line + posline, BUFF_SIZE - posline + 1);
			ft_memmove(buf, buf + posbuf + 1, BUFF_SIZE - (posbuf + 1));
			ft_bzero(buf + (BUFF_SIZE - (posbuf + 1)), posbuf + 1);
			return (GNL_BUF_HAS_LINE);
		}
		else
		{
			*size = ft_strlen(buf);
			return (GNL_BUF_HAS_DATA);
		}
	}
	return (GNL_FIRST_CALL);
}

static void			handle_newline_in_buf(t_gnl *env, char buf[BUFF_SIZE],
		char **line)
{
	int				posline;
	int				posbuf;

	posline = ft_strnpos(*line + env->size, '\n', BUFF_SIZE);
	posbuf = ft_strnpos(buf, '\n', BUFF_SIZE);
	if (posline >= 0)
	{
		ft_bzero(*line + env->size + posline, BUFF_SIZE - posline + 1);
		ft_memmove(buf, buf + posbuf + 1, BUFF_SIZE - (posbuf + 1));
		ft_bzero(buf + (BUFF_SIZE - (posbuf + 1)), posbuf + 1);
	}
	env->ret = GNL_BUF_HAS_LINE;
}

static int			process_buf(t_gnl *env, char buf[BUFF_SIZE], char **line)
{
	if (!(env->ret == GNL_READ_ERROR))
	{
		if (!(env->ret == GNL_END_OF_FILE))
			handle_newline_in_buf(env, buf, line);
		else
		{
			if (*line)
			{
				ft_bzero(buf, BUFF_SIZE);
				env->ret = GNL_BUF_HAS_LINE;
			}
		}
	}
	return (env->ret);
}

static void			ft_get_line(t_gnl *env, char **line, char buf[BUFF_SIZE])
{
	while ((env->ret = read(env->fd, buf, BUFF_SIZE)) > 0)
	{
		*line = (char *)ft_realloc(*line, env->size + BUFF_SIZE + 1);
		ft_bzero(*line + env->size, BUFF_SIZE + 1);
		ft_memmove(*line + env->size, buf, BUFF_SIZE);
		if (ft_memchr(*line + env->size, '\n', BUFF_SIZE))
			return ;
		env->size += BUFF_SIZE;
		ft_bzero(buf, BUFF_SIZE);
	}
}

int					get_next_line(int fd, char **line)
{
	static char		buf[BUFF_SIZE] = { 0 };
	t_gnl			env;
	int				buf_state;

	env.size = 0;
	env.ret = -2;
	env.fd = fd;
	if (fd > -1 && line)
	{
		*line = NULL;
		buf_state = process_old_data(buf, line, &(env.size));
		if (buf_state == GNL_BUF_HAS_LINE)
			return (GNL_BUF_HAS_LINE);
		else if (buf_state == GNL_BUF_HAS_DATA || buf_state == GNL_FIRST_CALL)
		{
			ft_bzero(buf, BUFF_SIZE);
			ft_get_line(&env, line, buf);
		}
		else if (buf_state == GNL_ER_MALLOC)
			return (GNL_READ_ERROR);
		return (process_buf(&env, buf, line));
	}
	return (GNL_READ_ERROR);
}
