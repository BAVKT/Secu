/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:31:30 by vmercadi          #+#    #+#             */
/*   Updated: 2017/03/23 17:33:14 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// Compilation : compil rot.c libft.a

#include "libft.h"
#include <fcntl.h>

#define size 1000  

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
** Decale chaque caractere de str par sa valeur ascii + nb dans la fourchette ascii de start a end.
*/
void 	rot(int nb, char *str, int start, int end)
{
	int 	i;
	char 	*s;

	s = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	while (str[i])
	{
		s[i] = ((str[i] + nb - start) % ((end - 1) - start)) + start;
		i++;
	}
	s[i] = '\0';
	ft_putendl(s);
	free(s);
}

int 	main(int ac, char **av)
{
	int 	i;
	int 	nb;
	int 	start;
	int 	end;
	char 	*s;

	if (ac != 5)
	{
		ft_putstrcolor("usage : a.out nbrot fichier start end\n", YELLOW);
		ft_putstrcolor("- nbrot = Nombre de rotation precise qu'on veut effectuer. 0 pour toute la table ascii 1 par 1.\n", YELLOW);
		ft_putstrcolor("- start = Ou commncer dans la table ascii.\n- end = jusqu'a ou dans la table ascii", YELLOW);
		ft_putstrcolor("Exemple : a.out 0 test.txt 32 127", YELLOW);
		return (0);
	}
	i = 32;
	nb = ft_atoi(av[1]);
	start = ft_atoi(av[3]);
	end = ft_atoi(av[4]);
	s = file_to_str(av[2]);
	if (nb == 0)
	{
		while (i < end) 				//On fait toute la table ascii depuis espace
		{
			rot(i, s, start, end);
			i++;
			ft_putchar('\n');
		}
	}
	else
		rot(nb, s, start, end);
	free(s);
	return(0);
}
