/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:04:59 by loamar            #+#    #+#             */
/*   Updated: 2022/03/16 15:30:05 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H
# include <unistd.h>

# define SUCCESS 0
# define ERROR -1
# define SWAP_ALL -1
# define SWAPP_LESS_FIRST -1


typedef struct data
{
  int *tab_a;
  int *tab_b;
  int size_a;
  int size_b;
  int pos_a;
  int pos_b;
}							t_data;

# define ERROR 1
# define SUCCESS 0
# endif
