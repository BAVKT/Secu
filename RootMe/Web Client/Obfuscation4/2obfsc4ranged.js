/*
**	charCodeAt()		// Retourne une valeur entre 0 et 65535. les 128 premiers sont des valeurs ascii. 
**						//Si on lui donne une STR retourne, la valeur de la premiere lettre.
**	
**
**
*/



//q$Ymq5mq9G6ñ/96<K95|£tXÇqVhQ,sE2[*ñ/?Wn=ugOmn@6Y3V>{:pP=s7¬$áVb[*ñE>cG
var hexstr= "\x71\x11\x24\x59\x8d\x6d\x71\x11\x35\x16\x8c\x6d\x71\x0d\x39\x47\x1f\x36\xf1\x2f\x39\x36\x8e\x3c\x4b\x39\x35\x12\x87\x7c\xa3\x10\x74\x58\x16\xc7\x71\x56\x68\x51\x2c\x8c\x73\x45\x32\x5b\x8c\x2a\xf1\x2f\x3f\x57\x6e\x04\x3d\x16\x75\x67\x16\x4f\x6d\x1c\x6e\x40\x01\x36\x93\x59\x33\x56\x04\x3e\x7b\x3a\x70\x50\x16\x04\x3d\x18\x73\x37\xac\x24\xe1\x56\x62\x5b\x8c\x2a\xf1\x45\x7f\x86\x07\x3e\x63\x47";

function ft_xor(x,y)
{
	return x^y;		//^ =    Xor  : ou binaire exclusif
}

function ft_exponentiel(y)
{
	var z = 0;
	for(var i = 0; i < y; i++)
		z += Math.pow(2,i);
	return z;
}

function ft_3(y)
{
	var z = 0;
	for(var i=8-y; i<8; i++)
		z += Math.pow(2,i);
	return z
}
/* Pas utilisé
function ____(x,y)
{
	y = y % 8;
	nb = ft_exponntiel(y);
	nb = (x & nb) << (8-y);
	return (nb) + (x >> y);
}
*/
function ft_5(c,i)
{
	i = i % 8;
	nb = ft_3(i);
	nb = (c & nb) >> (8-i);
	return ((nb) + (c << i)) & 0x00ff;
}
/*Appelle et retourne ft_5 donc inutile
function ______(x,y)
{
	return ft_5(x,y)
}
*/

/*
** Fonction qui retourne une STR
*/

function ft_6(hexstr,user)		//hexstr = la ligne definie tout en haut	user = retour du prompt rentré par l'user
{								
	str = "";								
	//________2 = "";	//pas appellé
	for(var i=0; i<hexstr.length; i++)										//On parcours hexstr caractere apres caractere
	{								
		c = hexstr.charCodeAt(i);											//On met dans c la valeur ascii de hexstr[i]
		if(i != 0)															//Si i n'est pas NULL
		{								
			t = str.charCodeAt(i-1)%2;										//Rempli t avec 1 ou 0 
			switch(t)
			{
				case 0: cr = ft_xor(c, user.charCodeAt(i % user.length));	//Si t est un 0 on fait un xor de hexstr[i] et ?.. qu'on met dans cr
					break;
				case 1: cr = ft_5(c, user.charCodeAt(i % user.length));		//Sinon on met dans cr le resultat de ft_5(hexstr[i])
					break;
			}
		}
		else																//Si i == 0 (donc uniquement pour la premiere lettre de la chaine) 
			cr = ft_xor(c, user.charCodeAt(i % user.length));				//On fait comme pour case0
		str += String.fromCharCode(cr);										//Transforme cr en valeur ascii et le concatene a str.
	}
	return str;
}

function ft_main(arg)
{
	var nb=0;
	for(var i=0;i<arg.length;i++)
		nb+=arg["charCodeAt"](i)
	if(nb==8932)
	{
		var ç=window.open("","","\x77\x69\x64\x74\x68\x3d\x33\x30\x30\x2c\x68\x65\x69\x67\x68\x74\x3d\x32\x20\x30");
		ç.document.write(arg)
	}
	else
		alert("Mauvais mot de passe!")
}
ft_main(ft_6(hexstr,prompt("Mot de passe?")));
