/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polybe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 19:35:30 by vmercadi          #+#    #+#             */
/*   Updated: 2017/03/27 22:53:45 by vmercadi         ###   ########.fr       */
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
*/

#include "libft.h"


typedef struct 		s_cube
{
	char			*str; 			//le fichier a decrypter dans une str
}					t_cube;
t_cube				g_c;


/*
** L'usage
*/
void	usage(int i)
{
	if (i == 1)
	{
		ft_putstrcolor("Mauvais nombre d'arguments passés\n", RED_BOLD);
		ft_putstrcolor("usage : a.out i j alpha fichier", YELLOW);
		ft_putstrcolor("i 		= l'index vertical.", YELLOW);
		ft_putstrcolor("j 		= l'index horizontal.", YELLOW);
		ft_putstrcolor("alpha 	= l'alphabet a mettre dans le cube.", YELLOW);
		ft_putstrcolor("fichier = le fichier contenant le texte a traduire.\n", YELLOW);
		ft_putstrcolor("Exemple : ", YELLOW);
		ft_putstrcolor("./a.out ABCDE 12345 abcdefghijklmnopqrstuvxyz CryptedFile.txt\n", YELLOW)
		ft_putendl("Exemple de cube :");
		ft_putstrcolor(
			"				j
				-------------------------\n
				|   | 1 | 2 | 3 | 4 | 5 |\n
				|---|---|---|---|---|---|\n
				| A | a | b | c | d | e |\n
				|---|---|---|---|---|---|\n
				| B | f | g | h | i | j |\n
			i	|---|---|---|---|---|---|\n
				| C | k | l | m | n | o |\n
				|---|---|---|---|---|---|\n
				| D | p | q | r | s | t |\n
				|---|---|---|---|---|---|\n
				| E | u | v | x | y | z |\n
				-------------------------", GREEN_BOLD);	
	}
	else if (i == 2)
		ft_putstrcolor("Les indexs doivent etre égaux en taille.", RED_BOLD);
	else if (i == 3)
		ft_putstrcolor("L'alphabet passé ne contient pas un nombre correcte de caracteres.", RED_BOLD);
}

/*
** Check si les parametres passés sont gud.
*/
int		check_params(int ac, char **av)
{
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
	return (1);
}

/*
** Met le contenu d'un fichier dans un char *
*/
char	*file_to_str(char *av)
{
	char	*s;
	int 	fd;
	int 	ret;
	int 	nb;
	char 	buf[size + 1];

	fd = open(av, O_RDONLY);
	nb = 0;
	while ((ret = read(fd, buf, size)) > 0)
		nb += ret;
	close(fd);
	fd = open(av, O_RDONLY);
	s = (char *)malloc(sizeof(char) * (nb + 1));
	nb = 0;
	while ((ret = read(fd, buf, size)) > 0)
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
** Affichage du cube
*/
void 	print_cube(char **str, int size)
{
	ft_putendl("printcube");
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
** Initialise le cube et rempli le cube.
*/
char	**init_cube(char **av)
{
	char 	**cube;
	char	*str;
	int 	i;
	int		j;
	int		k;
	int 	len;

	i = 0;
	len = ft_strlen(av[1]);
	cube = (char **)malloc(sizeof(char *) * len + 1);
	str = file_to_str(av[4]);
	while (i++ < len)
	{
		cube[i] = (char *)malloc(sizeof(char) * len + 1);
		cube[i][len] = '\0'; 									//Pas sur qu'on puisse faire ca direct
	}
	cube[len] = NULL;
	i = 0;
	j = 0;
	k = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			cube[i][j] = str[k]; 
			j++;
			k++;
		}
		i++;
	}
	print_cube(cube, len);
}


/*
** Fonction permettant de decrypter une phrase en fonction de ce qu'on lui passe
*/
char 	*use_polybe(char **av)
{
	char 	**cube;

	cube = init_cube(av);


}

/*
** On passe 3 arguments au main : l'index vertical, l'horizontal et l'ordre des lettres a placer dans la grille.
*/
int main(int ac, char **av)
{

	if (!check_params(ac, av))
		return (0);
	use_polybe(av);
	return (0);
}
