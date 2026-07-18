/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaengsa <ssaengsa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 17:41:20 by ssaengsa          #+#    #+#             */
/*   Updated: 2026/07/18 23:59:00 by ssaengsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_row(int grid[4][4], int row, int *clues);
int	ft_check_col(int grid[4][4], int col, int *clues);
int	ft_is_safe(int grid[4][4], int row, int col, int value);

int	ft_check_partial(int grid[4][4], int row, int col, int *clues)
{
	if (col == 3 && !ft_check_row(grid, row, clues))
		return (0);
	if (row == 3 && !ft_check_col(grid, col, clues))
		return (0);
	return (1);
}

int	ft_solve(int grid[4][4], int pos, int *clues)
{
	int	row;
	int	col;
	int	value;

	if (pos == 16)
		return (1);
	row = pos / 4;
	col = pos % 4;
	value = 1;
	while (value <= 4)
	{
		if (ft_is_safe(grid, row, col, value))
		{
			grid[row][col] = value;
			if (ft_check_partial(grid, row, col, clues)
				&& ft_solve(grid, pos + 1, clues))
				return (1);
			grid[row][col] = 0;
		}
		value++;
	}
	return (0);
}
