/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carre.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:59:26 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/21 15:59:41 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polybe.h"

/*
** Pour copier un tableau dans un autre
*/
char **cp_carre(char **carre, char **dst)
{
	int		i;
	int		j;

	i = 0;
	while (i < LEN)
	{
		j = 0;
		while (j < LEN)
		{
			dst[i][j] = carre[i][j];
			j++;
		}
		i++;
	}
	return (dst);
}

/*
** Affichage du carre
*/
void 	print_carre(char **str, int size)
{
			ft_putendl("print_carre");
	int i;
	int j;
		ft_putnbrendl(size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(str[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

/*
** Rempli le carré avec l'alphabet courant 
*/
void	remp_carre(char **carre)
{
	int 	i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < LEN)
	{
		j = 0;
		while (j < LEN)
		{
			carre[i][j] = ALPHA[k]; 
			j++;
			k++;
		}
		carre[i][j] = '\0';
		i++;
	}
}

/*
** Initialise et rempli le carre.
*/
char	**init_carre()
{
						ft_putendl("init_carre");
	char 	**carre;
	int 	i;

	i = 0;
	carre = (char **)malloc(sizeof(char *) * LEN + 1);
	while (i < LEN)
	{
		carre[i] = (char *)malloc(sizeof(char) * LEN + 1);
		i++;
	}
	carre[i] = NULL;
	remp_carre(carre);
	print_carre(carre, LEN);
	return (carre);
}
