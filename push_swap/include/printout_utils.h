/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printout_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:04:57 by marlee            #+#    #+#             */
/*   Updated: 2025/09/07 22:27:44 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTOUT_UTILS_H
# define PRINTOUT_UTILS_H

# include "ft_printf.h"
# include "parse_utils1.h"

void	printlist(t_list *current);
void	printlistboth(t_list *stk_a, t_list *stk_b);

#endif