/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_fcts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 22:59:41 by challeau          #+#    #+#             */
/*   Updated: 2020/04/27 22:59:44 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_init_buff(void)
{
	static char buff[BUFF_SZ + 1];

	ft_bzero(buff, BUFF_SZ);
	return (&buff[0]);
}

void	ft_flush_buff(char *buff, int *char_count)
{
	*char_count += ft_strlen(buff);
	ft_putstr_fd(buff, 1);
	ft_bzero(buff, BUFF_SZ);
}

int		ft_fill_buff(char **buff, char *to_add, int *char_count)
{
	if (!to_add)
		return (0);
	if ((ft_strlen(*buff) + ft_strlen(to_add)) > BUFF_SZ)
		ft_flush_buff(*buff, char_count);
	while (ft_strlen(to_add) > BUFF_SZ)
	{
		ft_strlcat(*buff, to_add, BUFF_SZ + 1);
		ft_flush_buff(*buff, char_count);
		to_add += BUFF_SZ;
	}
	ft_strcat(*buff, to_add);
	return (1);
}
