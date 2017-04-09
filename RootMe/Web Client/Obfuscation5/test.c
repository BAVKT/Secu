#include "libft.h"
/*
	function calcule() {
	s=0;
	var nb=1000;
	for(i=1;i<=nb;i++) {
		a$=i.toString()
		for(j=0;j<a$.length;j++) {
			if (a$.charAt(j)=="0") {
				s++
			}
		}
	}
	question = prompt(" Entre le mot de passe :")
	if (question==s) {
		alert("Bravo!!")
	} else {
		alert("reessaye")
	}
	}
*/
int	main()
{
	int s;
	int nb;
	int i;
	int j;
	char *a;

	i = 1;
	j = 0;
	s = 0;
	a = ft_strnew(1001);
	a[1000] = '\0';
	nb = 1000;
	while (i <= nb)
	{
		a = ft_itoa(i);
		j = 0;
		while (j < ft_strlen(a))
		{
			if (a[j] == '0')
				s++;
			j++;
		}
		i++;
	}
	ft_putnbrendl(s);
	return (0);
}