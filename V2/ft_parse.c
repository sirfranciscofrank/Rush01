/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_parse.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/17 17:41:14 by username         #+#    #+#              */
/*   Updated: 2026/07/19 01:32:43 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

/* count characters in str up to the null terminator */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* valid input = 31 chars: digits 1-4 at even indexes, spaces at odd ones */
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

/*
** Validate the format, then pull the 16 clue digits out of the string.
** Clue order stored in the array:
**   clues[0..3]   top    (columns, seen from above)
**   clues[4..7]   bottom (columns, seen from below)
**   clues[8..11]  left   (rows, seen from the left)
**   clues[12..15] right  (rows, seen from the right)
*/
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
