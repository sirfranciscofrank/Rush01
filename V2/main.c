/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/17 17:41:12 by username         #+#    #+#              */
/*   Updated: 2026/07/19 01:33:32 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

int		ft_parse(char *str, int *clues);
int		ft_solve(int grid[4][4], int pos, int *clues);
void	ft_print_grid(int grid[4][4]);
void	ft_print_error(void);

/* clear the 4x4 grid so every cell starts empty (0) before solving */
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

/*
** Program entry point. Overall flow:
**   1. ft_init_grid  - empty the 4x4 grid
**   2. ft_parse      - read argv[1] into the 16 clues (needs exactly 1 arg)
**   3. ft_solve      - backtracking search that fills the grid
**   4. ft_print_grid - on success, print the solution
** Any failure (bad args, bad format, no solution) prints "Error".
*/
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
