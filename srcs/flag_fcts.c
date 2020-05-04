/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_fcts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 23:00:03 by challeau          #+#    #+#             */
/*   Updated: 2020/04/27 23:00:06 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		f_align(const char **format)
{
	bool dash;
	bool zero;

	dash = false;
	zero = false;
	while (**format == '0' || **format == '-')
	{
		while (**format == '0' && (zero = true))
			*format += 1;
		while (**format == '-' && (dash = true))
			*format += 1;
	}
	if (dash == true)
		return (1);
	if (zero == true)
		return (2);
	return (0);
}

int		f_width(const char **format, va_list args)
{
	int width;

	width = 0;
	if (**format == '*')
	{
		*format += 1;
		return (va_arg(args, int));
	}
	while (**format >= '0' && **format <= '9')
	{
		width = width * 10 + **format - 48;
		*format += 1;
	}
	return (width);
}

int		f_prec(const char **format, va_list args)
{
	int prec;

	prec = -1;
	if (**format == '.')
	{
		prec = 0;
		*format += 1;
		if (**format == '*')
		{
			*format += 1;
			return (va_arg(args, int));
		}
		while (**format >= '0' && **format <= '9')
		{
			prec = prec * 10 + **format - 48;
			*format += 1;
		}
		return (prec);
	}
	return (-1);
}

t_flags	ft_flg_handler(const char **f, va_list args)
{
	t_flags flg;

	flg.align = f_align(f);
	flg.width = f_width(f, args);
	flg.prec = f_prec(f, args);
	if (flg.width < 0)
	{
		flg.align = 1;
		flg.width *= -1;
	}
	return (flg);
}
