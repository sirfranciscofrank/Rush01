/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaengsa <ssaengsa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 17:41:12 by ssaengsa          #+#    #+#             */
/*   Updated: 2026/07/17 17:41:13 by ssaengsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_parse(char *str, int *clues);
int		ft_solve(int *grid, int pos, int *clues);
void	ft_print_grid(int *grid);
void	ft_print_error(void);

void	ft_init_grid(int *grid)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		grid[i] = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	grid[16];
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
