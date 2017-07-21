/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:56:05 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/21 16:41:12 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polybe.h"

/*
** Calcule la size des indexs par rapport à l'entrée reçu
*/
void	set_size()
{

}

/*
** Sort les indexs verticaux. 
** Si il y a un nombre impaire de caracteres les deux seront identiques.
** Si le nombre de chiffres == au nombre de lettres, met les chiffre d'un cotes
*/
void	set_hori_verti(char *str)
{
	int		i;
	int		j;
	int		nb;
	int		line;
	int		size;
	char	*tmp;

	i = 0;
	j = 0;
	line = ft_strnew(0);
	while (str[i])
	{
		if (!ft_strchr(line, str[i])) //Met tous les differents caracteres dans line
		{
			line[j++] = str[i];
			line[j++] = '\0';
		}
		i++;
	}
	size = ft_strlen(line);
	while (line[i])					//On regarde si il y a des digits
	{
		if (ft_isdigit(line[i]))
			nb++;
		i++;
	}
	if (size / 2 == 0 && nb && nb == size / 2)	//Si il y a un nombre pair de caracteres
	{
		i = 0;
		j = 0;
		nb = 0;							//On se sert du nb comme index pour pas recreer une var
		while (line[i])
		{
			if (ft_isdigit(line[i]))	//On met les digits dans VERTI
			{
				VERTI[j++] = line[i];
				VERTI[j++] = '\0';
			}
			else						//Et le reste dans HORI
			{
				HORI[nb++] = line[i];
				HORI[nb++] = '\0';
			}					
			i++;
		}			
	}
	else			//Si il n'y a pas un nombre pair de caracteres, HORI et VERTI sont identiques.
	{
		HORI = line;
		VERTI = line;
	}
}

