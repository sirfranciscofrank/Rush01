/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaengsa <ssaengsa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 17:41:09 by ssaengsa          #+#    #+#             */
/*   Updated: 2026/07/17 17:41:10 by ssaengsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_get_row(int *grid, int row, int *line)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = grid[row * 4 + i];
		i++;
	}
}

void	ft_get_col(int *grid, int col, int *line)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = grid[i * 4 + col];
		i++;
	}
}

void	ft_reverse(int *line, int *rev)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		rev[i] = line[3 - i];
		i++;
	}
}

int	ft_count_view(int *line)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}
