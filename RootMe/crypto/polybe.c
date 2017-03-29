/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polybe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 19:35:30 by vmercadi          #+#    #+#             */
/*   Updated: 2017/03/29 15:56:35 by vmercadi         ###   ########.fr       */
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
** Commande : ./a.out abcde 12345 abcdefghijklmnopqrstuvxyz CryptedFile.txt
**
** Pour Determiner les indexs I et J on prend les caracteres  utilisé dans le fichier encrypté.
** Ex : "c2b1e3d4d3d1 a4e5c5b1e3c2a3d1 e3e5" on voit 'abcde' et '12345' peut aussi etre '12345' et '12345'
** En general on commence par l'index vertical qu'on couple avec l'horizontal.
*/

#include "libft.h"
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
	char			*vertical;		//index i
	char			*horizontal; 	//index j
	char			*alphabet; 		//l'alphabet actuel
	char			*alphabase;		//L'alphabet de base
	int				len; 			//Longueur de l'index et donc taille du carré
}					t_carre;
t_carre				g_c;

/*
** L'usage
*/
void	usage(int i)
{
			ft_putendl("Usage");
	if (i == 1)
	{
		ft_putstrcolor("usage : a.out i j alpha fichier\n", YELLOW);
		ft_putstrcolor("i       = l'index vertical.", YELLOW);
		ft_putstrcolor("j       = l'index horizontal.", YELLOW);
		ft_putstrcolor("alpha   = l'alphabet a mettre dans le carre.", YELLOW);
		ft_putstrcolor("fichier = le fichier contenant le texte a traduire.\n", YELLOW);
		ft_putstrcolor("Exemple d'utilisation et de carré de polybe : ", GREEN_BOLD);
		ft_putstrcolor("./a.out abcde 12345 abcdefghijklmnopqrstuvxyz CryptedFile.txt\n", GREEN_BOLD);
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
	STR = file_to_str(av[4]);
	LEN = ft_strlen(av[1]);
	return (1);
}


/*
** Affichage du carre
*/
void 	print_carre(char **str, int size)
{
			ft_putendl("print_carre");
	ft_putendl("printcarre");
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
** Initialise et rempli le carre.
*/
char	**init_carre()
{
						ft_putendl("init_carre");
	char 	**carre;
	int 	i;
	int		j;
	int		k;

	i = 0;
	carre = (char **)malloc(sizeof(char *) * LEN + 1);
	while (i < LEN)
	{
		carre[i] = (char *)malloc(sizeof(char) * LEN + 1);
		i++;
	}
	carre[i] = NULL;
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
	print_carre(carre, LEN);
	return (carre);
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
			ft_putendl("CHECK IN I");
			ft_putstr("c = ");
			ft_putcharendl(c);
			ft_putstr("VERTI[i] = ");
			ft_putcharendl(VERTI[i]);
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
			ft_putendl("CHECK IN J");
			ft_putstr("HORI[i] = ");
			ft_putcharendl(HORI[i]);
		if (HORI[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

/*
** Change l'ordre de l'alphbet
*/
/*int		switch_alphabet(char **carre)
{
	int i;

	i = 0;
	while (i < )

}*/

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

/*
** On passe 3 arguments au main : l'index vertical, l'horizontal et l'ordre des lettres a placer dans la grille.
*/
int main(int ac, char **av)
{
			ft_putendl("main");
	char 	**carre;
	char	*str;

	if (!check_params(ac, av))
		return (0);
	carre = init_carre();
	//while (switch_alphabet(carre))
	//{
					ft_putendl(STR);
		if (!(str = use_polybe(carre)))
			return (0);
		ft_putendl(str);
	//}
	return (0);
}
