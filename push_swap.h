/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:27:45 by jakand            #+#    #+#             */
/*   Updated: 2025/01/25 15:47:32 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prew;
}	t_node;

typedef struct	s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;	
}	t_stack;



t_stack 	*init_stack (void);
int		push_stack (t_stack *stack, int value);
int		pop_stack (t_stack *stack);
void		free_stack (t_stack *stack);
int		main(int argc, char *argv[]);
int		ft_atoi(const char *nptr);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	first_move(t_stack *a, t_stack *b);
int		get_best_position_b(t_stack *b, int value);
int		calculate_operations(t_stack *a, t_stack *b, int value);
void	move_best_to_b(t_stack *a, t_stack *b);
void	execute_moves(t_stack *a, t_stack *b, int value);


// void	calculate_chunks(int *array, int size, int chunk_count, int *chunk_limits);
// void	move_to_b(t_stack *a, t_stack *b, int	*chunk_limits, int chunk_count);
// void	move_back_to_a(t_stack *a, t_stack *b);
// void	sort_array(int *array, int size);
// int		has_numbers_in_chunk(t_stack *stack, int limit);
// int		find_max(t_stack *stack);
// void	bring_to_top(t_stack *stack, int value);



#endif
