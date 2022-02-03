/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:13:02 by loamar            #+#    #+#             */
/*   Updated: 2022/02/02 23:38:39 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/swap.h"

static	int	check_arg(int argc, char **argv)
{
	int		pos;
	int		word;

	word = 1;
	pos = 0;
	if (argc == 1)
		return (ERROR);
	while (word < argc)
	{
		while (argv[word][pos] != '\0')
		{
			if (ft_isdigit(argv[word][pos]) == 0)
				return (ERROR);
			pos++;
		}
		pos = 0;
		word++;
	}
	return (SUCCESS);
}

int		main(int argc, char **argv)
{
	if (check_arg(argc, argv) == ERROR)
		return (ft_error_msg("Wrong Argument\n"));

	// ;
}
