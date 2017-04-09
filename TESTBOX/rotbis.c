#include "libft.h"

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
		if (str[i] >= 'A' && str[i] <= 'Z')
		{

			s[i] = ((str[i] + nb - 'A') % (('Z' - 1) - 'A')) + 'A';
			i++;
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			s[i] = ((str[i] + nb - 'a') % (('z' - 1) - 'a')) + 'a';
			i++;	
		}
		else
		{
			s[i] = str[i];
			i++;
		}
	}
	s[i] = '\0';
	ft_putendl(s);
	free(s);
}

int main()
{
	rot(13, "Gur cnffjbeq vf 5Gr8L4qetPEsPk8htqjhRK8XSP6x2RHh");
}