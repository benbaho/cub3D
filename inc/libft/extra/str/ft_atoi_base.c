/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirci <ademirci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:47:35 by ademirci          #+#    #+#             */
/*   Updated: 2022/08/28 17:47:54 by ademirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_atoi_base(const char *str, int base)
{
	int	i;
	int	n;
	int	res;

	i = 0;
	n = 1;
	res = 0;
	if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		res *= base;
		if (str[i] >= '0' && str[i] <= '9')
			res += str[i] - 48;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			res += str[i] - 55;
		else if (str[i] >= 'a' && str[i] <= 'z')
			res += str[i] - 87;
		i++;
	}
	return (res * n);
}
