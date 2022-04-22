/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:13:02 by loamar            #+#    #+#             */
/*   Updated: 2022/04/22 11:43:37 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/swap.h"

static	int	check_double(t_data *data)
{
		int		check;
		int		pos;
		int		limit;

		check = 0;
		pos = 0;
		limit = 0;
		while (limit < data->size_a)
		{
			check = data->tab_a[limit];
			while (pos < data->size_a)
			{
				if (data->tab_a[pos] == check
				&& limit != pos)
					return (ERROR);
				pos++;
			}
			limit++;
		}
		return (SUCCESS);
}

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

static	int	error_msg()
{
	ft_putstr_fd("Error", 2);
	ft_putchar_fd('\n', 2);
	return (ERROR);
}

int		main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		return (0);
	if (check_arg(argc, argv) == ERROR)
		return (error_msg());
	data.size_a = argc - 1;
	data.size_b = 0;
	data.pos_a = 0;
	data.pos_b = 0;
	if (fill_tab(&data) == ERROR)
		return (error_msg());
	if (check_double(&data) == ERROR)
		return (error_msg());
	sort_tab(&data);
}
