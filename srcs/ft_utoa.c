/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 23:04:01 by challeau          #+#    #+#             */
/*   Updated: 2020/04/27 23:04:04 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_utoa(unsigned int num)
{
	int			i;
	int			len;
	char		*dst;

	i = 0;
	len = ft_intlen(num);
	if (!(dst = (char *)malloc(len + 1)))
		return (NULL);
	while (i < len)
	{
		dst[i++] = (num % 10) + 48;
		num /= 10;
	}
	dst[len] = '\0';
	ft_strrev(dst);
	return (dst);
}
