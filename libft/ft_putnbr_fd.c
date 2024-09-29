/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:53:38 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 13:53:39 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr(long int n, int fd)
{
	char		temp[11];
	int			size;
	long int	num;

	size = 0;
	num = n;
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		*(temp + size) = num % 10;
		num = num / 10;
		size++;
	}
	size--;
	if (n < 0)
		ft_putchar_fd('-', fd);
	while (size >= 0)
	{
		ft_putchar_fd(temp[size] + '0', fd);
		size--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
		putnbr(n, fd);
}
