/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 11:47:28 by vmercadi          #+#    #+#             */
/*   Updated: 2016/12/14 12:28:44 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lenlst(t_list *lst)
{
	int nb;

	nb = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		nb++;
	}
	return (nb);
}