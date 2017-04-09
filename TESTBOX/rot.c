/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:31:30 by vmercadi          #+#    #+#             */
/*   Updated: 2017/04/08 16:43:35 by vmercadi         ###   ########.fr       */
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
void 	rot(int nb, char *str)
{
	int 	i;
	char 	*s;

	s = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	while (str[i])
	{
		if (str[i] < 'A' && str[i] > 'Z')
		{
			s[i] = str[i];
			i++;
		}
		else
		{
			s[i] = str[i] + nb;
			i++;
		}
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

	if (ac != 3)
	{
		ft_putstrcolor("usage : a.out nbrot fichier start end\n", YELLOW);
		ft_putstrcolor("- nbrot = Nombre de rotation precise qu'on veut effectuer. 0 pour toute la table ascii 1 par 1.\n", YELLOW);
		ft_putstrcolor("- start = Ou commncer dans la table ascii.\n- end = jusqu'a ou dans la table ascii", YELLOW);
		ft_putstrcolor("Exemple : a.out 0 test.txt 32 127", YELLOW);
		return (0);
	}
	nb = ft_atoi(av[1]);
	start = ft_atoi(av[3]);
	end = ft_atoi(av[4]);
	s = file_to_str(av[2]);
	i = start;
	if (nb == 0)
	{
		while (i < end) 				//On fait toute la table ascii depuis espace
		{
			rot(i, s);
			i++;
			ft_putchar('\n');
		}
	}
	else
		rot(nb, s);
	free(s);
	return(0);
}
