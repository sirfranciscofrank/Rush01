/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaengsa <ssaengsa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 17:41:16 by ssaengsa          #+#    #+#             */
/*   Updated: 2026/07/18 23:59:00 by ssaengsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_left(int grid[4][4], int row);
int	ft_count_right(int grid[4][4], int row);
int	ft_count_top(int grid[4][4], int col);
int	ft_count_bottom(int grid[4][4], int col);

int	ft_check_row(int grid[4][4], int row, int *clues)
{
	if (ft_count_left(grid, row) != clues[8 + row])
		return (0);
	if (ft_count_right(grid, row) != clues[12 + row])
		return (0);
	return (1);
}

int	ft_check_col(int grid[4][4], int col, int *clues)
{
	if (ft_count_top(grid, col) != clues[col])
		return (0);
	if (ft_count_bottom(grid, col) != clues[4 + col])
		return (0);
	return (1);
}

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
