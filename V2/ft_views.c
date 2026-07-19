/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_views.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/18 23:59:00 by username         #+#    #+#              */
/*   Updated: 2026/07/19 01:33:24 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

/*
** These four helpers count how many buildings are "visible" from one side.
** A building is visible if it is taller than every building before it,
** so the returned count can be compared against the view clue.
** ft_count_left scans the row from left to right.
*/
int	ft_count_left(int grid[4][4], int row)
{
	int	col;
	int	max;
	int	visible;

	col = 0;
	max = 0;
	visible = 0;
	while (col < 4)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			visible++;
		}
		col++;
	}
	return (visible);
}

/* ft_count_right scans the row from right to left */
int	ft_count_right(int grid[4][4], int row)
{
	int	col;
	int	max;
	int	visible;

	col = 3;
	max = 0;
	visible = 0;
	while (col >= 0)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			visible++;
		}
		col--;
	}
	return (visible);
}

/* ft_count_top scans the column from top to bottom */
int	ft_count_top(int grid[4][4], int col)
{
	int	row;
	int	max;
	int	visible;

	row = 0;
	max = 0;
	visible = 0;
	while (row < 4)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			visible++;
		}
		row++;
	}
	return (visible);
}

/* ft_count_bottom scans the column from bottom to top */
int	ft_count_bottom(int grid[4][4], int col)
{
	int	row;
	int	max;
	int	visible;

	row = 3;
	max = 0;
	visible = 0;
	while (row >= 0)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			visible++;
		}
		row--;
	}
	return (visible);
}
