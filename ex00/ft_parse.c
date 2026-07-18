/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_parse.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/17 17:41:14 by username         #+#    #+#              */
/*   Updated: 2026/07/19 00:51:51 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_is_valid_format(char *str)
{
	int	i;

	if (ft_strlen(str) != 31)
		return (0);
	i = 0;
	while (i < 31)
	{
		if (i % 2 == 0)
		{
			if (str[i] < '1' || str[i] > '4')
				return (0);
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_parse(char *str, int *clues)
{
	int	i;

	if (!ft_is_valid_format(str))
		return (0);
	i = 0;
	while (i < 16)
	{
		clues[i] = str[i * 2] - '0';
		i++;
	}
	return (1);
}
