/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_conv_fcts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 23:04:18 by challeau          #+#    #+#             */
/*   Updated: 2020/04/27 23:04:19 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	d_conv(va_list args, t_flags flg, char **buff, int *c_count)
{
	int		i_tmp;
	int		len;
	char	*arg;

	i_tmp = va_arg(args, int);
	if (!(arg = ft_itoa(i_tmp)))
		return (0);
	len = ft_strlen(arg);
	if (flg.align == 2 && len < flg.width && flg.prec < 0)
		arg = ft_add_zeros(arg, flg.width - len);
	else if (flg.prec > len)
	{
		/* if (i_tmp < 0) */
		/* 	arg = ft_add_zeros(arg, flg.prec - (len - 1)); */
		/* else */
			arg = ft_add_zeros(arg, flg.prec - len);
	}
	if (flg.prec == 0 && ft_strcmp(arg, "0") == 0)
		arg[0] = '\0';
	if (flg.width > 0 && (len = ft_strlen(arg)) < flg.width)
		arg = ft_add_spaces(arg, flg.width - len, flg.align);
	if (ft_fill_buff(buff, arg, c_count) == 0)
		return (0);
	ft_memdel(arg);
	return (1);
}

int	i_conv(va_list args, t_flags flg, char **buff, int *c_count)
{
	int		i_tmp;
	int		len;
	char	*arg;

	i_tmp = va_arg(args, int);
	if (!(arg = ft_itoa(i_tmp)))
		return (0);
	len = ft_strlen(arg);
	if (flg.align == 2 && len < flg.width && flg.prec < 0)
		arg = ft_add_zeros(arg, flg.width - len);
	else if (flg.prec > len)
	{
		if (i_tmp < 0)
			arg = ft_add_zeros(arg, flg.prec - len + 1);
		else
			arg = ft_add_zeros(arg, flg.prec - len);
	}
	if (flg.prec == 0 && ft_strcmp(arg, "0") == 0)
		arg[0] = '\0';
	if (flg.width > 0 && (len = ft_strlen(arg)) < flg.width)
		arg = ft_add_spaces(arg, flg.width - len, flg.align);
	if (ft_fill_buff(buff, arg, c_count) == 0)
		return (0);
	ft_memdel(arg);
	return (1);
}

int	u_conv(va_list args, t_flags flg, char **buff, int *c_count)
{
	int				len;
	int				i_tmp;
	unsigned int	u_num;
	char			*arg;

	i_tmp = va_arg(args, int);
	u_num = i_tmp < 0 ? (UINT_MAX + 1) + i_tmp : (unsigned int)i_tmp;
	if (!(arg = ft_utoa(u_num)))
		return (0);
	len = ft_strlen(arg);
	if (flg.align == 2 && len < flg.width && flg.prec < 0)
		arg = ft_add_zeros(arg, flg.width - len);
	else if (flg.prec > len)
		arg = ft_add_zeros(arg, flg.prec - len);
	if (flg.prec == 0 && ft_strcmp(arg, "0") == 0)
		arg[0] = '\0';
	if (flg.width > 0 && (len = ft_strlen(arg)) < flg.width)
		arg = ft_add_spaces(arg, flg.width - len, flg.align);
	if (ft_fill_buff(buff, arg, c_count) == 0)
		return (0);
	ft_memdel(arg);
	return (1);
}

int	l_x_conv(va_list args, t_flags flg, char **buff, int *c_count)
{
	int				len;
	int				i_tmp;
	unsigned int	u_num;
	char			*arg;

	i_tmp = va_arg(args, int);
	u_num = i_tmp < 0 ? (UINT_MAX + 1) + i_tmp : (unsigned int)i_tmp;
	if (!(arg = ft_dec_to_base(false, u_num, 16)))
		return (0);
	len = ft_strlen(arg);
	if (flg.align == 2 && len < flg.width && flg.prec < 0)
		arg = ft_add_zeros(arg, flg.width - len);
	else if (flg.prec > len)
		arg = ft_add_zeros(arg, flg.prec - len);
	if (flg.prec == 0 && ft_strcmp(arg, "0") == 0)
		arg[0] = '\0';
	if (flg.width > 0 && (len = ft_strlen(arg)) < flg.width)
		arg = ft_add_spaces(arg, flg.width - len, flg.align);
	if (ft_fill_buff(buff, arg, c_count) == 0)
		return (0);
	ft_memdel(arg);
	return (1);
}

int	u_x_conv(va_list args, t_flags flg, char **buff, int *c_count)
{
	int				len;
	int				i_tmp;
	unsigned int	u_num;
	char			*arg;

	i_tmp = va_arg(args, int);
	u_num = i_tmp < 0 ? (UINT_MAX + 1) + i_tmp : (unsigned int)i_tmp;
	if (!(arg = ft_dec_to_base(true, u_num, 16)))
		return (0);
	len = ft_strlen(arg);
	if (flg.align == 2 && len < flg.width && flg.prec < 0)
		arg = ft_add_zeros(arg, flg.width - len);
	else if (flg.prec > len)
		arg = ft_add_zeros(arg, flg.prec - len);
	if (flg.prec == 0 && ft_strcmp(arg, "0") == 0)
		arg[0] = '\0';
	if (flg.width > 0 && (len = ft_strlen(arg)) < flg.width)
		arg = ft_add_spaces(arg, flg.width - len, flg.align);
	if (ft_fill_buff(buff, arg, c_count) == 0)
		return (0);
	ft_memdel(arg);
	return (1);
}
