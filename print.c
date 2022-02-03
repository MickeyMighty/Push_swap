/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 23:33:54 by loamar            #+#    #+#             */
/*   Updated: 2022/02/02 23:38:15 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_status(int action)
{
	if (action == SA)
		ft_putstr("sa\n");
	else if (action == SB)
		ft_putstr("sb\n");
	else if (action == SS)
		ft_putstr("ss\n");
	else if (action == PA)
		ft_putstr("pa\n");
	else if (action == PB)
		ft_putstr("pb\n");
	else if (action == RA)
		ft_putstr("ra\n");
	else if (action == RB)
		ft_putstr("rb\n");
	else if (action == RR)
		ft_putstr("rr\n");
	else if (action == RRA)
		ft_putstr("rra\n");
	else if (action == RRB)
		ft_putstr("rrb\n");
	else if (action == RRR)
		ft_putstr("rrr\n");
}
