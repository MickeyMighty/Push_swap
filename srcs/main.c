/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:13:02 by loamar            #+#    #+#             */
/*   Updated: 2022/03/15 13:31:37 by loamar           ###   ########.fr       */
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
	t_data	data;

	if (check_arg(argc, argv) == ERROR)
		return (ft_error_msg("Wrong Argument\n"));

	data.size_a = argc - 1;
	data.size_b = 0;
	data.pos_a = 0;
	data.pos_b = 0;
	if (fill_tab(&data) == ERROR)
		return (0);
	sort_tab(&data);
	// ;
}
