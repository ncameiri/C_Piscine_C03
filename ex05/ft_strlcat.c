/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:05:04 by ncameiri          #+#    #+#             */
/*   Updated: 2020/10/29 18:53:18 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_str_length_fast(char *dest)
{
	unsigned int	count;

	count = 0;
	while (dest[count] != '\0')
		count++;
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*dst;
	char			*src_start;
	unsigned int	dst_length;
	unsigned int	remaining;

	dst = dest;
	src_start = src;
	remaining = size;
	while (remaining-- != 0 && *dst != '\0')
		dst++;
	dst_length = dst - dest;
	remaining = size - dst_length;
	if (remaining == 0)
		return (dst_length + ft_str_length_fast(src));
	while (*src != '\0')
	{
		if (remaining > 1)
		{
			*dst++ = *src;
			remaining--;
		}
		src++;
	}
	*dst = '\0';
	return (dst_length + (src - src_start));
}
