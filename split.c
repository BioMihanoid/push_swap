/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmilan <gmilan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:16:25 by gmilan            #+#    #+#             */
/*   Updated: 2022/03/07 16:51:18 by gmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dstsize)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

static size_t	count_words(char const *str, char c)
{
	int	count;
	int	f;

	count = 0;
	f = 0;
	while (*str)
	{
		if (*str != c && f == 0)
		{
			f = 1;
			count++;
		}
		else if (*str == c)
			f = 0;
		str++;
	}
	return (count);
}

static char	*create_str(char const *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, i + 1);
	return (str);
}

static void	clear(char **arr_str, int i)
{
	while (i > 0)
		free(arr_str[i--]);
	free(arr_str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	**arr_str;

	if (!s)
		return (NULL);
	len = count_words(s, c);
	arr_str = (char **)malloc(sizeof(char *) * (len + 1));
	if (!arr_str)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		while (s[0] == c)
			s++;
		arr_str[i] = create_str(s, c);
		if (!arr_str)
		{
			clear(arr_str, i);
			return (NULL);
		}
		s = s + ft_strlen(arr_str[i]);
	}
	arr_str[i] = 0;
	return (arr_str);
}