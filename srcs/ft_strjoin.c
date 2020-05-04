/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 23:03:18 by challeau          #+#    #+#             */
/*   Updated: 2020/04/27 23:03:21 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	size_t	len1;
	size_t	len2;
	char	*dst;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(dst = (char *)malloc((len1 + len2 + 1) * sizeof(char))))
		return (NULL);
	while (*s1)
	{
		dst[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		dst[i++] = *s2;
		s2++;
	}
	dst[i] = '\0';
	return (dst);
}
