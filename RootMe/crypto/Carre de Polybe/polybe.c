/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polybe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 19:35:30 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/21 15:59:47 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* 
** Un carré de polybe ressemble a ça de base :
** -------------------------
** |   | 1 | 2 | 3 | 4 | 5 |
** |---|---|---|---|---|---|
** | A | a | b | c | d | e |
** |---|---|---|---|---|---|
** | B | f | g | h | i | j |
** |---|---|---|---|---|---|
** | C | k | l | m | n | o |
** |---|---|---|---|---|---|
** | D | p | q | r | s | t |
** |---|---|---|---|---|---|
** | E | u | v | x | y | z |
** -------------------------
**
** Commande : ./a.out abcde 12345 abcdefghijklmnopqrstuvxyz CryptedFile.txt password
**
** Compilation : gcc polybe.c libft.a
**
** Pour Determiner les indexs I et J on prend les caracteres  utilisé dans le fichier encrypté.
** Ex : "c2b1e3d4d3d1 a4e5c5b1e3c2a3d1 e3e5" on voit 'abcde' et '12345' peut aussi etre '12345' et '12345'
** En general on commence par l'index vertical qu'on couple avec l'horizontal.
**
** Commenter la partie switch alphabet en fonction et dans le main pour une utilisation normale (pas d'inversion d'alphabet)
**
*/

//
// RESTE A FAIRE FONCTIONNER SWITCH ALPHABET
// ET METRE EN PLACE LA RECHERCHE DE MOT
//

#include "polybe.h"

/*
** Met le contenu d'un fichier dans un char *
*/
char	*file_to_str(char *av)
{
			ft_putendl("file2str");
	char	*s;
	int 	fd;
	int 	ret;
	int 	nb;
	char 	buf[SIZE + 1];

	fd = open(av, O_RDONLY);
	nb = 0;
	while ((ret = read(fd, buf, SIZE)) > 0)
		nb += ret;
	close(fd);
	fd = open(av, O_RDONLY);
	s = (char *)malloc(sizeof(char) * (nb + 1));
	nb = 0;
	while ((ret = read(fd, buf, SIZE)) > 0)
	{
		s[nb] = '\0';
		nb += ret;
		s = ft_strcat(s, buf);
	}
	close(fd);
	s[nb] = '\0';
	return (s);
}

/*
** Permet d'inverser les caracteres d'une chaine 1 a 1
*/
char 	*rev_str(char *str)
{
	char	*tmp;
	int		i;
	int		x;

	i = 0;
	x = ft_strlen(str);
	tmp = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		tmp[i] = str[x - i - 1];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

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

/*
** Change l'ordre de l'alphbet et met a jour le carre de polybe
*/
void	switch_alphabet()
{
				ft_putendl("SWWIIITTCCH");
	if (g_c.j + 1 < ft_strlen(ALPHA))
	{
		ALPHA[g_c.j] = ALPHA[g_c.i];
		g_c.j++;
	}
	else if (g_c.i + 1 < ft_strlen(ALPHA))
	{
		g_c.j = 0;
		g_c.i++;
		g_c.c = ALPHA[g_c.i];
	}
	ALPHA[g_c.i] = ALPHA[g_c.j];
	ALPHA[g_c.j] = g_c.c;
}
/*
** Fonction permettant de decrypter une phrase en fonction de ce qu'on lui passe
*/
char 	*use_polybe(char **carre)
{
			ft_putendl("use_polybe");
	int		k;
	int		l;
	int		i;
	int		j;
	char	*decrypted;

	k = 0;
	l = 0;
	i = 0;
	j = 0;
	decrypted = (char *)malloc(sizeof(char) * (ft_strlen(STR) / 2) + 1);
	decrypted[ft_strlen(STR) / 2 + 1] = '\0';
	while (STR[k])
	{
		i = check_i(STR[k]);
		if (i == -1)
		{
			decrypted[l] = STR[k];
			l++;
			if (STR[k])
				k++;
		}
		else
		{
			if (STR[k])
				k++;
			j = check_j(STR[k]);
			if (i >= 0 && j >= 0)
			{
				decrypted[l] = carre[i][j];
				l++;
			}
			if (STR[k])
				k++;
		}
	}
				ft_putendl(decrypted);
	return (decrypted);
}

int main(int ac, char **av)
{
			ft_putendl("main");
	char 	**carre;
	char	*str;

	if (!check_params(ac, av))					//On check si les parametres sont bons
		return (0);
	carre = init_carre(); 						//On initialise le carré avec les parametres passés
	remp_carre(carre);
	g_c.c = ALPHA[0];
	/*while (ft_strcmp(ALPHA, g_c.alphaend))		//Tant que l'alphabet n'est pas le dernier alphabet possible
	{*/
		if (!(str = use_polybe(carre)))			//On décrypte avec le carré courant
			return (0);
		//if (ft_strstr(STR, av[5]))				//On check si le mot recherché se trouve dans le texte
		//	break ;								//Si oui, c'est fini et on sort +affichage du texte déchiffré, sinon :
		//switch_alphabet();						//On inverse un caractere de l'alphabet avec un autre
		//remp_carre(carre);						//On rempli le carré avec le nouvel alphabet
	//}
	ft_putendl(str);
	return (0);
}
