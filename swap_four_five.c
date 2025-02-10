/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_four_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:34:40 by jakand            #+#    #+#             */
/*   Updated: 2025/02/10 23:39:29 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_to_b(t_stack *a, t_stack *b)
{

}

void	four_num(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	three_num(a);
	pa(a, b);
	write(1, "pa\n", 3);
}
