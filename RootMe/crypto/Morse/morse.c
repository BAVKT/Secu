/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 21:50:34 by vincent           #+#    #+#             */
/*   Updated: 2017/08/06 23:48:02 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**
**
** SEGFAULT des familles, je pas comprendre presque fini pour morse->abc
**
**
*/




/*
** tab = Alphabet + num
** abcdefghijklmnopqrstuvwxyz0123456789
*/
char *morse_tab[36] = {
".-","-...","-.-.","-..",".","..-.","--.","....","..",
".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
"...","-","..-","...-",".--","-..-","-.--","--..","-----",
".----","..---","...--","....-",".....","-....","--...",
"---..","----."
};

char *abc_tab[36] = {
"a","b","c","d","e","f","g","h","i","j","k","l","m",
"n","o","p","q","r","s","t","u","v","w","x","y","z",
"0","1","2","3","4","5","6","7","8","9"
};

/*
** errors
*/
void	error(int e)
{
	if (e == 1)
		ft_putendl("You have to write only 'a-z', '1-9' & spaces for abc trad.");
	else if (e == 2)			
		ft_putendl("You have to write only '-', '.' & spaces for morse trad.");
	else if (e == 3)	
		ft_putendl("Unidentified characters, please enter correct str.");
	else if (e == 4)
		ft_putendl("Please enter a morse str or a normal str to conv.");
	exit(1);
}

/*
** Check if the passed arg is in tab
*/
char	*check_morse_tab(char *str)
{
	int	i;

	i = 0;
	while (morse_tab[i])
	{
		if (!ft_strcmp(str, morse_tab[i]))
			return (abc_tab[i]);
		i++;
	}
	return (NULL);
}

/*
** Check if there are only good characters
*/
void	check_str(char *s)
{
	int	i;

	i = 0;
	if ((s[0] >= 65 && s[0] <= 90) || 
		(s[0] >= 97 && s[0] <= 122) || (s[0] == ' '))
	{
		while (s[i])
		{
			if ((s[i] >= 65 && s[i] <= 90) || 
				(s[i] >= 97 && s[i] <= 122) || (s[i] == ' '))
			i++;
			else
				error(1);
		}
	}
	else if ((s[0] == '-') || (s[0] == '.') || (s[0] == ' '))
	{
		while (s[i])
		{
			if ((s[i] == '-') || (s[i] == '.') || (s[i] == ' '))
				i++;
			else
				error(2);
		}
	}	
	else
		error(3);
}

/*
**	Check if the char is uppercase
*/
int		is_upper(char s)
{		
	if (s >= 65 && s <= 90)
		return (1);
	return (0);
}

/*
** Convert normal strings to no-maj string
*/
char	*no_case(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnew(ft_strlen(str));
	while (str[i])
	{
		if (is_upper(str[i]))
			tmp[i] = str[i] + 32;
		else 
			tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	ft_strdel(&str);
	return (tmp);
}

/*
** Trad from abc to morse & vice-versa
*/
char	*morse_to_abc(char *encrypted)
{
	int		i;
	int		j;
	int		size;
	char	*tmp;
	char	*decrypted;

	i = 0;
	j = 0;
	size = 0;
	while (encrypted[i])
	{
				ft_putendl("yo 1");
				ft_putnbrendl(i);
		tmp = ft_strnew(0);
		while (encrypted[i] && encrypted[i] != ' ')
			tmp[j++] = encrypted[i++];
		if (encrypted[i] == ' ')
		{
				ft_putendl("yo 2");
			tmp[j] = '\0';
			decrypted = ft_strjoin(decrypted, check_morse_tab(tmp));
			//ft_strdel(&tmp);
			size++;
			j = 0;
				ft_putendl("yo 3");
		}
		if (encrypted[i + 1] == ' ')
		{
				ft_putendl("yo 4");
			decrypted = ft_strjoin(decrypted, " ");
			i++;
				ft_putendl("yo 5");
		}
		i++;
	}
	decrypted[size + 1] = '\0';
	//ft_strdel(&encrypted);
	return (decrypted);
}

int		main(int ac, char **av)
{
	(void)ac;
	if (!av[1])
		error(4);
	else 
		check_str(av[1]);
	ft_putendl(morse_to_abc(av[1]));
	return (0);
}