/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conv_fcts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 22:59:53 by challeau          #+#    #+#             */
/*   Updated: 2020/04/27 22:59:58 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	c_conv(va_list args, t_flags flg, char **buff, int *c_count)
{
	char	*width;

	ft_flush_buff(*buff, c_count);
	if (flg.width > 1 && (*c_count += flg.width - 1))
		width = ft_add_spaces(ft_strdup(""), flg.width - 1, flg.align);
	if (flg.width > 1 && flg.align == 1)
	{
		ft_putchar_fd(va_arg(args, int), 1);
		ft_putstr_fd(width, 1);
		ft_memdel(width);
	}
	else if (flg.width > 1 && flg.align == 0)
	{
		ft_putstr_fd(width, 1);
		ft_putchar_fd(va_arg(args, int), 1);
		ft_memdel(width);
	}
	else
		ft_putchar_fd(va_arg(args, int), 1);
	*c_count += 1;
	return (1);
}

int	s_conv(va_list args, t_flags flg, char **buff, int *c_count)
{
	int		len;
	char	*arg;
	char	*tmp;

	tmp = va_arg(args, char *);
	if (tmp == NULL)
		tmp = "(null)\0";
	len = ft_strlen(tmp);
	if (!(arg = (char *)malloc(len + 1)))
		return (0);
	ft_strlcpy(arg, tmp, len);
	if (flg.prec >= 0 && flg.prec < len && tmp != NULL)
		arg[flg.prec] = '\0';
	if ((len = ft_strlen(arg)) < flg.width)
		arg = ft_add_spaces(arg, flg.width - len, flg.align);
	if (ft_fill_buff(buff, arg, c_count) == 0)
		return (0);
	ft_memdel(arg);
	return (1);
}

int	p_conv(va_list args, t_flags flg, char **buff, int *c_count)
{
	int			len;
	long int	tmp;
	char		*arg;
	char		*s_tmp;

	tmp = va_arg(args, long int);
	if (!(s_tmp = ft_dec_to_base(false, tmp, 16)))
		return (0);
	arg = ft_strjoin("0x", s_tmp);
	if (arg == NULL)
		return (0);
	if (ft_strcmp(arg, "0x0") == 0 && flg.prec == 0)
		arg[2] = '\0';
	if ((len = ft_strlen(arg)) < flg.width)
		arg = ft_add_spaces(arg, flg.width - len, flg.align);
	if (ft_fill_buff(buff, arg, c_count) == 0)
		return (0);
	ft_memdel(arg);
	ft_memdel(s_tmp);
	return (1);
}

int	pct_conv(va_list args, t_flags flg, char **buff, int *c_count)
{
	char *arg;

	(void)args;
	(void)flg;
	if (!(arg = ft_strdup("%")))
		return (0);
	if (flg.width > 1 && flg.align == 2)
		arg = ft_add_zeros(arg, flg.width - 1);
	else if (flg.width > 1)
		arg = ft_add_spaces(arg, flg.width - 1, flg.align);
	if (ft_fill_buff(buff, arg, c_count) == 0)
		return (0);
	ft_memdel(arg);
	return (1);
}
