/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polybe.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:38:00 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/21 15:57:38 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
#include <fcntl.h>

#define VERTI g_c.vertical
#define HORI g_c.horizontal
#define ALPHA g_c.alphabet
#define STR g_c.str
#define LEN g_c.len
#define SIZE 1000

typedef struct 		s_carre
{
	char			*str; 			//le fichier a decrypter dans une str
	char			*vertical;		//lettres indexs i
	char			*horizontal; 	//lettres indexs j
	char			*alphabet; 		//l'alphabet actuel
	char			*alphabase;		//L'alphabet de base
	char			*alphaend;		//Le dernier alphabet envisageable
	char			c;				//Le tout premier caractere
	int				len; 			//Longueur de l'index et donc taille du carré
	size_t			i;				//L'index i dans l'alphabet
	size_t			j;				//L'index j dans l'alphabet
}					t_carre;
t_carre				g_c;
