/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 07:50:27 by szheng            #+#    #+#             */
/*   Updated: 2018/07/10 19:05:45 by szheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int is_neg;
	int num;

	i = 0;
	is_neg = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
	|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		is_neg = 1;
	if ((str[i] == '-' || str[i] == '+'))
		i++;
	while ((str[i] >= '0' && (str[i] <= '9')))
	{
		num *= 10;
		num += (str[i] - '0');
		i++;
	}
	if (is_neg == 1)
		return (-num);
	return (num);
}
