/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_rules.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/17 17:41:16 by username         #+#    #+#              */
/*   Updated: 2026/07/19 01:33:10 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_left(int grid[4][4], int row);
int	ft_count_right(int grid[4][4], int row);
int	ft_count_top(int grid[4][4], int col);
int	ft_count_bottom(int grid[4][4], int col);

/* a full row is valid only if its left/right visible counts match the clues */
int	ft_check_row(int grid[4][4], int row, int *clues)
{
	if (ft_count_left(grid, row) != clues[8 + row])
		return (0);
	if (ft_count_right(grid, row) != clues[12 + row])
		return (0);
	return (1);
}

/* a full column is valid only if its top/bottom counts match the clues */
int	ft_check_col(int grid[4][4], int col, int *clues)
{
	if (ft_count_top(grid, col) != clues[col])
		return (0);
	if (ft_count_bottom(grid, col) != clues[4 + col])
		return (0);
	return (1);
}

/* value is safe only if it is not already used in this row or column */
int	ft_is_safe(int grid[4][4], int row, int col, int value)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == value || grid[i][col] == value)
			return (0);
		i++;
	}
	return (1);
}
