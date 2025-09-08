/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:47:26 by marlee            #+#    #+#             */
/*   Updated: 2025/09/05 19:40:25 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk_sort.h"

// static int	get_min_index(t_list **stack)
// {
// 	int		min;
// 	t_list	*current;

// 	min = ((t_data *)(*stack)->content)->index;
// 	current = (*stack)->next;
// 	while (current)
// 	{
// 		if (((t_data *)current->content)->index < min)
// 			min = ((t_data *)current->content)->index;
// 		current = current->next;
// 	}
// 	return (min);
// }

static int	get_max_index(t_list **stack)
{
	int		max;
	t_list	*current;

	max = ((t_data *)(*stack)->content)->index;
	current = (*stack)->next;
	while (current)
	{
		if (((t_data *)current->content)->index > max)
			max = ((t_data *)current->content)->index;
		current = current->next;
	}
	return (max);
}
static void	sort_stack_b(t_list **stk_a, t_list **stk_b)
{
	int	max_index;
	int	list_size;
	int	pos;

	while (*stk_b)
	{
		max_index = get_max_index(stk_b);
		list_size = ft_lstsize(*stk_b);
		pos = 0; // Find the position of the max index
		t_list *current = *stk_b;
		while (current)
		{
			if (((t_data *)current->content)->index == max_index)
				break;
			pos++;
			current = current->next;
		}
		if (pos <= list_size / 2) // If element is in the top half
		{
			while (((t_data *)(*stk_b)->content)->index != max_index)
				rb(stk_b);
		}
		else // If element is in the bottom half
		{
			while (((t_data *)(*stk_b)->content)->index != max_index)
				rrb(stk_b);
		}
		pa(stk_a, stk_b); // Push the largest element to stack A
	}
}

void	chunk_sort(t_list **stk_a, t_list **stk_b)
{
	int	chunk_size;
	int	total_elements;
	int	chunk_end;
	int	pushed_count;

	total_elements = ft_lstsize(*stk_a);
	chunk_size = 10; // A good starting point for N < 100
	chunk_end = chunk_size - 1;
	pushed_count = 0;
	while (*stk_a)
	{
		if (pushed_count >= chunk_end)
		{
			pushed_count = 0;
			chunk_end += chunk_size;
		}
		if (((t_data *)(*stk_a)->content)->index <= chunk_end)
		{
			pb(stk_a, stk_b);
			pushed_count++;
		}
		else
			ra(stk_a);
	}
	sort_stack_b(stk_a, stk_b);
}
