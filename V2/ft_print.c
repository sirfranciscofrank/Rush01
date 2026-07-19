/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_print.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/17 17:41:07 by username         #+#    #+#              */
/*   Updated: 2026/07/19 01:33:05 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* write a single character to standard output */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* write a string to standard output, one character at a time */
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

/* print the "Error" message required on any failure */
void	ft_print_error(void)
{
	ft_putstr("Error\n");
}

/* print the solved grid: digits separated by spaces, one row per line */
void	ft_print_grid(int grid[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			ft_putchar('0' + grid[row][col]);
			if (col < 3)
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
