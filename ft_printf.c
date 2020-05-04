/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 23:00:57 by challeau          #+#    #+#             */
/*   Updated: 2020/04/27 23:01:03 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	ft_conv_handler(const char **f, va_list args, char **buff, int *c_count)
{
	int		conv_spe;
	t_flags	flg;
	int		(*conv_fcts[9])(va_list, t_flags, char **, int *);

	conv_fcts[0] = &c_conv;
	conv_fcts[1] = &s_conv;
	conv_fcts[2] = &p_conv;
	conv_fcts[3] = &d_conv;
	conv_fcts[4] = &i_conv;
	conv_fcts[5] = &u_conv;
	conv_fcts[6] = &l_x_conv;
	conv_fcts[7] = &u_x_conv;
	conv_fcts[8] = &pct_conv;
	flg = ft_flg_handler(f, args);
	if ((conv_spe = ft_strchr_index(CONVS, **f)) >= 0 && conv_spe <= 8)
	{
		if ((*conv_fcts[conv_spe])(args, flg, buff, c_count) == 0)
			return (0);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		c_count;
	char	*buff;
	va_list	args;

	c_count = 0;
	buff = ft_init_buff();
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && format++)
		{
			if (ft_conv_handler(&format, args, &buff, &c_count) == 0)
				return (-1);
		}
		else if (ft_fill_buff(&buff, ft_char_to_str(*format), &c_count) == 0)
			return (-1);
		format++;
	}
	ft_flush_buff(buff, &c_count);
	va_end(args);
	return (c_count);
}
