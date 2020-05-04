/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 23:02:41 by challeau          #+#    #+#             */
/*   Updated: 2020/04/27 23:02:43 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_realloc(char *src, size_t new_sz)
{
	char	*new;
	size_t	src_sz;

	if (!src)
		return ((char *)malloc(new_sz));
	src_sz = ft_strlen(src);
	if (new_sz <= src_sz)
		return (src);
	new = (char *)malloc(new_sz);
	ft_strlcpy(new, src, src_sz);
	ft_memdel(src);
	return (new);
}
