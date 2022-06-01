/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:54:23 by loamar            #+#    #+#             */
/*   Updated: 2022/05/31 16:55:09 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/swap.h"

void	rra(t_data *data)
{
	int	pos;
	int	stock;

	stock = 0;
	pos = 0;
	pos = data->size_a;
	if (data->size_a <= 1)
		return ;
	stock = data->tab_a[data->size_a - 1];
	while (pos > 0)
	{
		ft_swap(&data->tab_a[pos], &data->tab_a[pos - 1]);
		pos--;
	}
	data->tab_a[0] = stock;
}

void	rrb(t_data *data)
{
	int	pos;
	int	stock;

	stock = 0;
	pos = 0;
	pos = data->size_b;
	if (data->size_b <= 1)
		return ;
	stock = data->tab_b[data->size_b - 1];
	while (pos > 0)
	{
		ft_swap(&data->tab_b[pos], &data->tab_b[pos - 1]);
		pos--;
	}
	data->tab_b[0] = stock;
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
