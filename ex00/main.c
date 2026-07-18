/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaengsa <ssaengsa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 17:41:12 by ssaengsa          #+#    #+#             */
/*   Updated: 2026/07/18 23:59:00 by ssaengsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_parse(char *str, int *clues);
int		ft_solve(int grid[4][4], int pos, int *clues);
void	ft_print_grid(int grid[4][4]);
void	ft_print_error(void);

void	ft_init_grid(int grid[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
}

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	clues[16];

	ft_init_grid(grid);
	if (argc != 2 || !ft_parse(argv[1], clues))
	{
		ft_print_error();
		return (1);
	}
	if (!ft_solve(grid, 0, clues))
	{
		ft_print_error();
		return (1);
	}
	ft_print_grid(grid);
	return (0);
}
