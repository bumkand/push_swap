/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:19:52 by jakand            #+#    #+#             */
/*   Updated: 2025/01/26 20:21:16 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	t_stack	*a;
	t_stack	*b;
    t_node  *current_a;
    t_node  *current_b;

	if (argc < 2)
		return (write(1, "You fuck** up with arguments\n", 29), 0);

	a = init_stack();
	b = init_stack();

	if (!a || !b)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (push_stack(a, ft_atoi(argv[i])) == -1)
		{
			write(2, "Error\n", 6);
			free_stack(a);
			free_stack(b);
			return (1);
		}
		i++;
	}

    current_a = a->top;
    i = a->size - 1;
    while (current_a)
    {
        printf("Stack A[%d] = %d\n", i, current_a->value);
        current_a = current_a->next;
        i--;
    }
    write(1, "\n", 1);
    current_b = b->top;
    j = b->size - 1;
    while (current_b)
    {
        printf("Stack b[%d] = %d\n", j, current_b->value);
        current_b = current_b->next;
        j--;
    }
	
    write(1, "\n", 1);
	i = 0;
	first_move(a, b);
	while (i != 2) // Spustenie funkcie x krat
	{
		move_best_to_b(a, b);
		i++;
	}
	
    current_a = a->top;
    i = a->size - 1;
    while (current_a)
    {
        printf("Stack A[%d] = %d\n", i, current_a->value);
        current_a = current_a->next;
        i--;
    }
    write(1, "\n", 1);
    current_b = b->top;
    j = b->size - 1;
    while (current_b)
    {
        printf("Stack b[%d] = %d\n", j, current_b->value);
        current_b = current_b->next;
        j--;
    }

	free_stack(a);
	free_stack(b);

	return (0);
}
