/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaandras <jaandras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:17:44 by jaandras          #+#    #+#             */
/*   Updated: 2025/02/09 19:19:14 by jaandras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *a, t_pos *num)
{
	if (num->pos_a <= (a->size / 2) && num->pos_a == 1)
	{
		sa(a);
		num->pos_a--;
		write(1, "sa\n", 3);
	}
}

void	rotate_both(t_stack *a, t_stack *b, t_pos *num)
{
	if (num->pos_a <= (a->size / 2) && num->pos_b <= (b->size / 2))
	{
		while (num->pos_a > 0 && num->pos_b > 0)
		{
			rr(a, b);
			num->pos_a--;
			num->pos_b--;
			write(1, "rr\n", 3);
		}
		while (num->pos_a > 0)
		{
			ra(a);
			num->pos_a--;
			write(1, "ra\n", 3);
		}
		while (num->pos_b > 0)
		{
			rb(b);
			num->pos_b--;
			write(1, "rb\n", 3);
		}
	}
}

void	rev_rotate_both(t_stack *a, t_stack *b, t_pos *num)
{
	if (num->pos_a > (a->size / 2) && num->pos_b > (b->size / 2))
	{
		while (num->pos_a < a->size && num->pos_b < b->size)
		{
			rrr(a, b);
			num->pos_a++;
			num->pos_b++;
			write(1, "rrr\n", 4);
		}
		while (num->pos_a < a->size)
		{
			rra(a);
			num->pos_a++;
			write(1, "rra\n", 4);
		}
		while (num->pos_b < b->size)
		{
			rrb(b);
			num->pos_b++;
			write(1, "rrb\n", 4);
		}
	}
}

void	rot_rev_a(t_stack *a, t_pos *num)
{
	if (num->pos_a <= (a->size / 2))
	{
		while (num->pos_a > 0)
		{
			ra(a);
			num->pos_a--;
			write(1, "ra\n", 3);
		}
	}
	if (num->pos_a > (a->size / 2))
	{
		while (num->pos_a < a->size)
		{
			rra(a);
			num->pos_a++;
			write(1, "rra\n", 4);
		}
	}
}

void	rot_rev_b(t_stack *b, t_pos *num)
{
	if (num->pos_b <= (b->size / 2))
	{
		while (num->pos_b > 0)
		{
			rb(b);
			num->pos_b--;
			write(1, "rb\n", 3);
		}
	}
	if (num->pos_b > (b->size / 2))
	{
		while (num->pos_b < b->size)
		{
			rrb(b);
			num->pos_b++;
			write(1, "rrb\n", 4);
		}
	}
}
