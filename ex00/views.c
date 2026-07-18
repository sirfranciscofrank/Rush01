/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaengsa <ssaengsa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 23:59:00 by ssaengsa          #+#    #+#             */
/*   Updated: 2026/07/18 23:59:00 by ssaengsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
