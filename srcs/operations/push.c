/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:51:48 by loamar            #+#    #+#             */
/*   Updated: 2022/05/31 16:52:08 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/swap.h"

void	pa(t_data *data)
{
	int	stock;

	stock = 0;
	if (data->size_b == 0)
		return ;
	stock = data->tab_b[0];
	data->size_a++;
	rb(data);
	data->size_b--;
	rra(data);
	data->tab_a[0] = stock;
}

void	pb(t_data *data)
{
	int	stock;

	stock = 0;
	if (data->size_a == 0)
		return ;
	stock = data->tab_a[0];
	data->size_b++;
	if (data->size_a > 1)
		ra(data);
	data->size_a--;
	if (data->size_b > 1)
	rrb(data);
	data->tab_b[0] = stock;
}
