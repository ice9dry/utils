/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 22:06:02 by marlee            #+#    #+#             */
/*   Updated: 2025/09/09 22:06:35 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "radix_sort.h"
#include "is_sorted.h"

void	radix_sort_2(t_list **stk_a, t_list **stk_b)
{
	t_data	*data;
	int		max_bits;
	int		i;
	int		j;
	int		k;
	int		size_a;
	int		size_b;
	int		count;

	size_a = ft_lstsize(*stk_a);
	max_bits = 0;
	while ((size_a - 1) >> max_bits)
		max_bits++;
	
	i = -1;
	while (++i < max_bits)
	{
		count = 0;
		j = -1;
		size_a = ft_lstsize(*stk_a);
		while (++j < size_a && !is_sorted(*stk_a))
		{
			data = (t_data *)(*stk_a)->content;
			if (((data->index >> i) & 1) == 0)
			{
				if ((j == size_a - 1))
					break ;
				pb(stk_a, stk_b);
				count++;
			}
			else
			{
				ra(stk_a);
			}
		}
		k = -1;
		if (i < max_bits - 1)
		{
			size_b = ft_lstsize(*stk_b);
			while (++k < size_b)
			{
				data = (t_data *)(*stk_b)->content;
				if (((data->index >> (i + 1)) & 1) == 0)
					rb(stk_b);
				else
					pa(stk_a, stk_b);
			}
		}
		else
		{
			while (*stk_b)
				pa(stk_a, stk_b);
		}
	}
}