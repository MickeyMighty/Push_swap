/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:13:02 by loamar            #+#    #+#             */
/*   Updated: 2022/05/31 16:51:17 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/swap.h"

static	int	check_double(t_data *data)
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
			// if (check > 2147483647 || check < (-2147483647 - 1))
			// 	return (ERROR);
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

static	int	error_msg()
{
	ft_putstr_fd("Error", 2);
	ft_putchar_fd('\n', 2);
	return (ERROR);
}

void print_tab(t_data *data) // pour afficher test
{
	int pos;

	pos = 0;
	printf("===============\n");
	printf("|-tab A-|\n");
	while (pos < data->size_a)
	{
		printf("%d-[%d]\n", pos, data->tab_a[pos]);
		pos++;
	}
	pos = 0;
	printf("|-tab B-|\n");
	while (pos < data->size_b)
	{
		printf("%d-[%d]\n", pos, data->tab_b[pos]);
		pos++;
	}
	printf("===============\n");
}

void free_data(t_data *data, int flag)
{
	if (flag == 1 || flag == 2)
	{
		free(data->tab_a);
		free(data->tab_b);
		if (flag == 2)
		{
			printf("2\n");
			free(data->lair_tab[0]);
			printf("3\n");
			free(data->lair_tab[1]);
			printf("4\n");
			free(data->lair_tab);
			printf("5\n");
		}
	}
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
	data.size_lair = argc - 1;
	if (fill_tab(&data, argv) == ERROR)
		return (error_msg());
	if (check_double(&data) == ERROR)
	{
		free_data(&data, 1);
		return (error_msg());
	}
	sort_tab(&data);
}
