/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulutas <eulutas@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:11:46 by eulutas           #+#    #+#             */
/*   Updated: 2023/08/31 13:34:32 by eulutas          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	arrwrite(char *array, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		write(1, &array[i], 1);
		i++;
	}
	if (array[0] != '0' + (10 - n))
	{
		write(1, ", ", 2);
	}
}

void	backtrack(int i, int start, char *array, int n)
{
	int		a;
	int		ch;

	if (i == n)
	{
		arrwrite(array, n);
		return ;
	}
	a = start;
	while (a < 10)
	{
		ch = '0' + a;
		array[i] = ch;
		backtrack(i + 1, a + 1, array, n);
		a++;
	}
}

void	ft_print_combn(int n)
{
	int		i;
	char	array[10];

	i = 0;
	while (i < 10)
	{
		array[i] = 0;
		i++;
	}
	if (n < 10 && n > 0)
	{
		backtrack(0, 0, array, n);
	}
}
