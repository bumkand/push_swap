/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:35:07 by jaandras          #+#    #+#             */
/*   Updated: 2025/02/11 16:37:19 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	execute_moves(t_stack *a, t_stack *b, int value)
// {
// 	t_node	*current;
// 	int		pos_a;
// 	int		pos_b;

// 	current = a->top;
// 	pos_a = 0;
// 	while (current->value != value)
// 	{
// 		current = current->next;
// 		pos_a++;
// 	}
// 	pos_b = get_best_position_b(b, current->value);
// 	// printf("execute:\npos_a:%d\n", pos_a);
// 	// printf("pos_b:%d\n", pos_b);
// 	if (pos_a <= (a->size / 2) && pos_a == 1)
// 	{
// 		sa(a);
// 		pos_a--;
// 		write(1, "sa\n", 3);
// 	}
// 	if (pos_a <= (a->size / 2) && pos_b <= (b->size / 2))
// 	{
// 		while (pos_a > 0 && pos_b > 0)
// 		{
// 			rr(a, b);
// 			pos_a--;
// 			pos_b--;
// 			write(1, "rr\n", 3);
// 		}
// 		while (pos_a > 0)
// 		{
// 			ra(a);
// 			pos_a--;
// 			write(1, "ra\n", 3);
// 		}
// 		while (pos_b > 0)
// 		{
// 			rb(b);
// 			pos_b--;
// 			write(1, "rb\n", 3);
// 		}
// 	}
// 	if (pos_a > (a->size / 2) && pos_b > (b->size / 2))
// 	{
// 		while (pos_a < a->size && pos_b < b->size)
// 		{
// 			rrr(a, b);
// 			pos_a++;
// 			pos_b++;
// 			write(1, "rrr\n", 4);
// 		}
// 		while (pos_a < a->size)
// 		{
// 			rra(a);
// 			pos_a++;
// 			write(1, "rra\n", 4);
// 		}
// 		while (pos_b < b->size)
// 		{
// 			rrb(b);
// 			pos_b++;
// 			write(1, "rrb\n", 4);
// 		}
// 	}
// 	if (pos_a <= (a->size / 2))
// 	{
// 		while (pos_a > 0)
// 		{
// 			ra(a);
// 			pos_a--;
// 			write(1, "ra\n", 3);
// 		}
// 	}
// 	if (pos_a > (a->size / 2))
// 	{
// 		while (pos_a < a->size)
// 		{
// 			rra(a);
// 			pos_a++;
// 			write(1, "rra\n", 4);
// 		}
// 	}
// 	if (pos_b <= (b->size / 2))
// 	{
// 		while (pos_b > 0)
// 		{
// 			rb(b);
// 			pos_b--;
// 			write(1, "rb\n", 3);
// 		}
// 	}
// 	if (pos_b > (b->size / 2))
// 	{
// 		while (pos_b < b->size)
// 		{
// 			rrb(b);
// 			pos_b++;
// 			write(1, "rrb\n", 4);
// 		}
// 	}
// 	pb(a, b);
// 	write(1, "pb\n", 3);
// }

void	execute_moves(t_stack *a, t_stack *b, int value)
{
	t_node	*current;
	int		pos_a;
	int		pos_b;
	t_pos	num;

	current = a->top;
	pos_a = 0;
	while (current->value != value)
	{
		current = current->next;
		pos_a++;
	}
	pos_b = get_best_position_b(b, current->value);
	// printf("execute:\npos_a:%d\n", pos_a);
	// printf("pos_b:%d\n", pos_b);
	num.pos_a = pos_a;
	num.pos_b = pos_b;
	swap_a(a, &num);
	rotate_both(a, b, &num);
	rev_rotate_both(a, b, &num);
	rot_rev_a(a, &num);
	rot_rev_b(b, &num);
	
	pb(a, b);
	write(1, "pb\n", 3);
}
