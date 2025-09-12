/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 22:25:22 by marlee            #+#    #+#             */
/*   Updated: 2025/09/08 21:48:39 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "radix_sort.h"

void	radix_sort(t_list **stk_a, t_list **stk_b)
{
	t_data	*data;
	int		max_bits;
	int		i;
	int		j;
	int		size;

	size = ft_lstsize(*stk_a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			data = (t_data *)(*stk_a)->content;
			if (((data->index >> i) & 1) == 0)
				pb(stk_a, stk_b);
			else
				ra(stk_a);
		}
		while (*stk_b)
			pa(stk_a, stk_b);
	}
}
