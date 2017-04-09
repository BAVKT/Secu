#include "libft.h"
typedef struct 		s_carre
{
	size_t			i;
	size_t			j;
	size_t			k;
	char			c;
}					t_carre;
t_carre				g_c;
/*
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

int main()
{
	char *str;
	ft_putendl("yo");
	str = rev_str("YOOOOA PLOP");
	ft_putendl(str);
	return (0);
}
*/

/*
** Change l'ordre de l'alphbet et met a jour le carre de polybe
*/
void	switch_alphabet(char *alpha)
{
				ft_putendl("SWWIIITTCCH");
			ft_putstr("g_c.i = ");
			ft_putnbrendl(g_c.i);
			ft_putstr("g_c.j = ");
			ft_putnbrendl(g_c.j);
	if (g_c.i == 0)
	{
		ft_putendl("Yo 1");
		g_c.i++;
		g_c.j++;
	}
	if (g_c.j + 1 < ft_strlen(alpha))
	{
		ft_putendl("Yo 2");
		alpha[g_c.i] = alpha[g_c.j];
		g_c.j++;
	}
	else if (g_c.i + 1 < ft_strlen(alpha))
	{
		ft_putendl("Yo 3");
		g_c.j = 0;
		g_c.i++;
		g_c.c = alpha[g_c.i];
	}
	else if (g_c.i + 1 >= ft_strlen(alpha))
	{
		ft_putendl("Yo 4");
		alpha[0] += 1;
		g_c.i = 0;
		g_c.j = 0;
	}
	//else
	//{
		ft_putendl("Yo 5");
		alpha[g_c.i] = alpha[g_c.j];
		alpha[g_c.j] = g_c.c;
	//}
	ft_putendl(alpha);
}

int	main()
{
	char *alpha;
	char *alphaend;

	g_c.i = 0;
	g_c.j = 0;
	g_c.k = 0;
	alpha = ft_strdup("abcde");
	alphaend = ft_strdup("edcba");
			ft_putstr("alpha = ");
			ft_putendl(alpha);
			ft_putstr("alphaend = ");
			ft_putendl(alphaend);
	g_c.c = alpha[0];
	while (ft_strcmp(alpha, alphaend))
	{
			ft_putendl("YO");
		switch_alphabet(alpha);
			ft_putendl("YA");
	}
	ft_putendl(alpha);
	return (0);
}
