/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 08:45:25 by szheng            #+#    #+#             */
/*   Updated: 2018/07/14 17:25:25 by szheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordcount(char const *str, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!str || !c)
		return (0);
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			j++;
		while (str[i] != c && str[i])
			i++;
	}
	return (j);
}

static char		*ft_strpart(char const *s, int slen, long index)
{
	char	*str;

	str = ft_strnew(slen);
	if (str == NULL)
		return (NULL);
	str[slen--] = '\0';
	while (slen >= 0)
		str[slen--] = s[index--];
	return (str);
}

static char		**ft_strsparse(char const *s, char **array, int word_ct, char c)
{
	int		slen;
	long	i;
	int		j;

	i = 0;
	j = 0;
	while (j < word_ct)
	{
		slen = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			slen++;
		}
		if (s[i] == '\0' || s[i] == c)
			array[j++] = ft_strpart(s, slen, i - 1);
	}
	array[j] = NULL;
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		word_count;

	if (s == NULL)
		return (NULL);
	word_count = ft_wordcount(s, c);
	if (!(array = (char **)malloc(sizeof(char *) * word_count + 1)))
		return (NULL);
	return (ft_strsparse(s, array, word_count, c));
}
