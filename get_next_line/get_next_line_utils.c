/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:02:15 by lchew             #+#    #+#             */
/*   Updated: 2022/09/11 12:16:50 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (i < (dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		++i;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;

	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	if (dstsize < (dlen + 1))
		return (slen + dstsize);
	dstsize -= dlen + 1;
	dst += dlen;
	if (dstsize >= slen)
		dstsize = slen;
	while (dstsize != 0)
	{
		*dst++ = *(unsigned char *)src++;
		--dstsize;
	}
	dst[dstsize] = '\0';
	return (slen + dlen);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		sub = malloc(1);
		*sub = '\0';
		return (sub);
	}
	s += start;
	i = ft_strlen(s);
	if (i < len)
		len = i;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	*sub = '\0';
	ft_strlcpy(sub, s, len + 1);
	return (sub);
}

char	*ft_strdup(const char *src)
{
	char	*dup;
	char	*d;

	dup = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	d = dup;
	while (*src != '\0')
		*d++ = *src++;
	*d = '\0';
	return (dup);
}
