/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaengsa <ssaengsa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 17:41:16 by ssaengsa          #+#    #+#             */
/*   Updated: 2026/07/17 17:41:17 by ssaengsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_get_row(int *grid, int row, int *line);
void	ft_get_col(int *grid, int col, int *line);
void	ft_reverse(int *line, int *rev);
int		ft_count_view(int *line);

int	ft_check_row(int *grid, int row, int *clues)
{
	int	line[4];
	int	rev[4];

	ft_get_row(grid, row, line);
	ft_reverse(line, rev);
	if (ft_count_view(line) != clues[8 + row])
		return (0);
	if (ft_count_view(rev) != clues[12 + row])
		return (0);
	return (1);
}

int	ft_check_col(int *grid, int col, int *clues)
{
	int	line[4];
	int	rev[4];

	ft_get_col(grid, col, line);
	ft_reverse(line, rev);
	if (ft_count_view(line) != clues[col])
		return (0);
	if (ft_count_view(rev) != clues[4 + col])
		return (0);
	return (1);
}

int	ft_is_safe(int *grid, int pos, int value)
{
	int	row;
	int	col;
	int	i;

	row = pos / 4;
	col = pos % 4;
	i = 0;
	while (i < 4)
	{
		if (grid[row * 4 + i] == value)
			return (0);
		if (grid[i * 4 + col] == value)
			return (0);
		i++;
	}
	return (1);
}
