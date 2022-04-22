/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 23:33:54 by loamar            #+#    #+#             */
/*   Updated: 2022/04/22 11:43:03 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/swap.h"

void	print_status((&operation)(data), int action)
{
	if (action == SA)
		ft_putstr_fd("sa\n", 1);
	else if (action == SB)
		ft_putstr_fd("sb\n", 1);
	else if (action == SS)
		ft_putstr_fd("ss\n", 1);
	else if (action == PA)
		ft_putstr_fd("pa\n", 1);
	else if (action == PB)
		ft_putstr_fd("pb\n", 1);
	else if (action == RA)
		ft_putstr_fd("ra\n", 1);
	else if (action == RB)
		ft_putstr_fd("rb\n", 1);
	else if (action == RR)
		ft_putstr_fd("rr\n", 1);
	else if (action == RRA)
		ft_putstr_fd("rra\n", 1);
	else if (action == RRB)
		ft_putstr_fd("rrb\n", 1);
	else if (action == RRR)
		ft_putstr_fd("rrr\n", 1);
}
