/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printout_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:02:16 by marlee            #+#    #+#             */
/*   Updated: 2025/09/07 18:15:45 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printout_utils.h"

void	printlist(t_list *current)
{
	while (current)
	{
		ft_printf("%d (%d) -> ", *(int *)current->content,
			((t_data *)current->content)->index);
		current = current->next;
	}
	printf("NULL\n");
}

void	printlistboth(t_list *stk_a, t_list *stk_b)
{
	ft_printf("Stack A: ");
	printlist(stk_a);
	ft_printf("Stack B: ");
	printlist(stk_b);
}
