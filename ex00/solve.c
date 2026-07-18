/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaengsa <ssaengsa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 17:41:20 by ssaengsa          #+#    #+#             */
/*   Updated: 2026/07/17 17:41:21 by ssaengsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_row(int *grid, int row, int *clues);
int	ft_check_col(int *grid, int col, int *clues);
int	ft_is_safe(int *grid, int pos, int value);

int	ft_check_partial(int *grid, int pos, int *clues)
{
	int	row;
	int	col;

	row = pos / 4;
	col = pos % 4;
	if (col == 3 && !ft_check_row(grid, row, clues))
		return (0);
	if (row == 3 && !ft_check_col(grid, col, clues))
		return (0);
	return (1);
}

int	ft_solve(int *grid, int pos, int *clues)
{
	int	value;

	if (pos == 16)
		return (1);
	value = 1;
	while (value <= 4)
	{
		if (ft_is_safe(grid, pos, value))
		{
			grid[pos] = value;
			if (ft_check_partial(grid, pos, clues))
			{
				if (ft_solve(grid, pos + 1, clues))
					return (1);
			}
			grid[pos] = 0;
		}
		value++;
	}
	return (0);
}
