/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 16:00:26 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/21 16:00:44 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polybe.c"

/*
** Check si les parametres passés sont gud et les met dans les define.
*/
int		check_params(int ac, char **av)
{
			ft_putendl("check_params");
	if (ac != 5)
	{
		usage(1);
		return (0);
	}
	if (ft_strlen(av[1]) != ft_strlen(av[2]))
	{
		usage(2);
		return (0);
	}
	if (ft_strlen(av[3]) != ft_strlen(av[1]) * ft_strlen(av[2]))
	{
		usage(3);
		return (0);
	}
	VERTI = av[1];
	HORI = av[2];
	ALPHA = av[3];
	g_c.alphabase = ALPHA;
	g_c.alphaend = rev_str(ALPHA);
	g_c.i = 0;
	STR = file_to_str(av[4]);
	LEN = ft_strlen(av[1]);
	return (1);
}

/*
** Renvoi l'index de VERTI correspondant.
*/
int		check_i(char c)
{
	int i;

	i = 0;
	while (VERTI[i])
	{
		if (VERTI[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

/*
** Renvoi L'index de HORI correspondant.
*/
int		check_j(char c)
{
	int i;

	i = 0;
	while (HORI[i])
	{
		if (HORI[i] == c)
			return (i);
		i++;
	}
	return (-1);
}