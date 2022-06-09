/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:45:45 by loamar            #+#    #+#             */
/*   Updated: 2022/06/09 12:05:10 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/swap.h"

int	check_is_good(t_data *data)
{
	int	pos;
	int	pos2;

	pos = 0;
	pos2 = 1;
	while (pos2 < data->size_a)
	{
		if (data->tab_a[pos] > data->tab_a[pos2])
			return (ERROR);
		pos++;
		pos2++;
	}
	return (SUCCESS);
}

int	check_double(t_data *data)
{
	int		check;
	int		pos;
	int		limit;

	check = 0;
	limit = 0;
	while (limit < data->size_a)
	{
		pos = 0;
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

int	check_arg(int argc, char **argv)
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
			if (argv[word][pos] == '-' || argv[word][pos] == '+')
				pos++;
			if (ft_isdigit(argv[word][pos]) == 0)
				return (ERROR);
			pos++;
		}
		pos = 0;
		word++;
	}
	return (SUCCESS);
}
