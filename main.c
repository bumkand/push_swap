/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:19:52 by jakand            #+#    #+#             */
/*   Updated: 2025/02/07 21:01:45 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
    int     j;
	t_stack	*a;
	t_stack	*b;
    char    **nmbrs;

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
	while (i < argc) // Prechádzame cez všetky argumenty
	{
		nmbrs = ft_split(argv[i], ' '); // Rozdelíme argument na jednotlivé čísla
		if (!nmbrs)
			return (write(2, "Error\n", 6), 1);

		j = 0;
		while (nmbrs[j]) // Prechádzame cez jednotlivé čísla
		{
			if (push_stack_a(a, ft_atoi(nmbrs[j])) == -1)
			{
				write(2, "Error\n", 6);
				free_stack(a);
				free_stack(b);
				free_split(nmbrs); // Uvoľnenie pamäte
				return (1);
			}
			j++;
		}
		free_split(nmbrs); // Uvoľnenie pamäte po spracovaní argumentu
		i++;
	}
    // write_stack(a, b);
	first_move(a, b);
    // write_stack(a, b);

	while (a->size != 0) // Spustenie funkcie x krat
	{
		move_best_to_b(a, b);
        // write_stack(a, b);
	}
    
    biggest_to_top(b);
    // write_stack(a, b);

    while (b->size != 0)
    {
        pa(a, b);
        write(1, "pa\n", 3);
        // write_stack(a, b);
    }
    
    // print_stack(a);

    // printf("Amount of Operations: %d\n", a->operations + b->operations);

	free_stack(a);
	free_stack(b);

	return (0);
}

void    free_split(char **arr)
{
    int i;

    if (!arr)
        return ;
    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void    write_stack(t_stack *a, t_stack *b)
{
    int		i;
    int		j;
    t_node  *current_a;
    t_node  *current_b;
    
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
}

void print_stack(t_stack *stack)
{
    t_node *tmp;
	
	tmp = stack->top;
    printf("Stack (from top to bottom): ");
    while (tmp)
    {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
    tmp = stack->bottom;
    printf("Stack (from bottom to top): ");
    while (tmp)
    {
        printf("%d ", tmp->value);
        tmp = tmp->prew;
    }
    printf("\n");
}