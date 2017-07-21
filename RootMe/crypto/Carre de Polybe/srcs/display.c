/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:54:33 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/21 15:55:13 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polybe.h"

/*
** L'usage
*/
void	usage(int i)
{
			ft_putendl("Usage");
	if (i == 1)
	{
		ft_putstrcolor("usage : a.out i j alpha fichier toFind\n", YELLOW);
		ft_putstrcolor("i       = l'index vertical.", YELLOW);
		ft_putstrcolor("j       = l'index horizontal.", YELLOW);
		ft_putstrcolor("alpha   = l'alphabet a mettre dans le carre.", YELLOW);
		ft_putstrcolor("fichier = le fichier contenant le texte a traduire.\n", YELLOW);
		ft_putstrcolor("toFind  = Le mot a trouver dans le texte decrypté\n", YELLOW);
		ft_putstrcolor("RETOUR  : Le texte décrypté qui contient le toFind qu'on lui a passé\n", YELLOW);
		ft_putstrcolor("Exemple d'utilisation et de carré de polybe : ", GREEN_BOLD);
		ft_putstrcolor("./a.out abcde 12345 abcdefghijklmnopqrstuvxyz CryptedFile.txt password\n", GREEN_BOLD);
		ft_putstrcolor("                j			 ", GREEN_BOLD);
		ft_putstrcolor("    -------------------------", GREEN_BOLD);
		ft_putstrcolor("    |   | 1 | 2 | 3 | 4 | 5 |", GREEN_BOLD);
		ft_putstrcolor("    |---|---|---|---|---|---|", GREEN_BOLD);
		ft_putstrcolor("    | A | a | b | c | d | e |", GREEN_BOLD);
		ft_putstrcolor("    |---|---|---|---|---|---|", GREEN_BOLD);
		ft_putstrcolor("    | B | f | g | h | i | j |", GREEN_BOLD);
		ft_putstrcolor("i   |---|---|---|---|---|---|", GREEN_BOLD);
		ft_putstrcolor("    | C | k | l | m | n | o |", GREEN_BOLD);
		ft_putstrcolor("    |---|---|---|---|---|---|", GREEN_BOLD);
		ft_putstrcolor("    | D | p | q | r | s | t |", GREEN_BOLD);
		ft_putstrcolor("    |---|---|---|---|---|---|", GREEN_BOLD);
		ft_putstrcolor("    | E | u | v | x | y | z |", GREEN_BOLD);
		ft_putstrcolor("    -------------------------", GREEN_BOLD);	
	}
	else if (i == 2)
		ft_putstrcolor("Les indexs doivent etre égaux en taille.", RED_BOLD);
	else if (i == 3)
		ft_putstrcolor("L'alphabet passé ne contient pas un nombre correcte de caracteres.", RED_BOLD);
	else if (i == 4)
		ft_putstrcolor("ERREUR. Le fichier comprend un caractère non existant dans les indexs.", RED_BOLD);
	else
		return ;
}

/*