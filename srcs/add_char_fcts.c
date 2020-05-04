/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char_fcts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 22:59:27 by challeau          #+#    #+#             */
/*   Updated: 2020/04/27 22:59:32 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_add_spaces(char *src, int to_add_len, int align)
{
	int		i;
	char	*to_add;
	char	*new;

	i = -1;
	if (!(to_add = (char *)malloc(to_add_len + 1)))
		return (NULL);
	while (i++ < to_add_len - 1)
		to_add[i] = ' ';
	to_add[i] = '\0';
	new = align != 1 ? ft_strjoin(to_add, src) : ft_strjoin(src, to_add);
	ft_memdel(src);
	ft_memdel(to_add);
	return (new);
}

char	*ft_add_zeros(char *src, int to_add_len)
{
	int		i;
	char	*to_add;
	char	*new;

	i = -1;
	if (!(to_add = (char *)malloc(to_add_len + 1)))
		return (NULL);
	while (i++ < to_add_len - 1)
		to_add[i] = '0';
	to_add[i] = '\0';
	new = ft_strjoin(to_add, src);
	if (src[0] == '-')
	{
		new[0] = '-';
		new[to_add_len] = '0';
	}
	ft_memdel(src);
	ft_memdel(to_add);
	return (new);
}
