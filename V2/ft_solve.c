/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_solve.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/17 17:41:20 by username         #+#    #+#              */
/*   Updated: 2026/07/20 00:22:28 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_row(int grid[4][4], int row, int *clues);
int	ft_check_col(int grid[4][4], int col, int *clues);
int	ft_is_safe(int grid[4][4], int row, int col, int value);

/* once a row or column is fully filled, check it against the view clues */
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
	/* convert the linear position (0-15) into row/col coordinates */
	row = pos / 4;
	col = pos % 4;
	value = 1;
	while (value <= 4)
	{
		/* reject value if it already appears in this row or column */
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
