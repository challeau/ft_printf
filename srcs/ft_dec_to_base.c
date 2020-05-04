/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 23:00:25 by challeau          #+#    #+#             */
/*   Updated: 2020/04/27 23:00:28 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_dec_to_base(bool cap, unsigned long num, unsigned int base_len)
{
	int		i;
	char	*base;
	char	*dst;

	i = 0;
	base = "0123456789ABCDEF";
	if (base_len > 16 || !(dst = (char *)malloc(ft_intlen(num) + 1)))
		return (NULL);
	if (num == 0)
		dst[i++] = '0';
	while (num != 0)
	{
		if (num < base_len)
			dst[i++] = base[num];
		else
			dst[i++] = base[num % base_len];
		num /= base_len;
	}
	dst[i] = '\0';
	ft_strrev(dst);
	if (cap == false)
		ft_strlowcase(dst);
	return (dst);
}
