/*
**	charCodeAt()		// Retourne une valeur entre 0 et 65535. les 128 premiers sont des valeurs ascii. 
**						//Si on lui donne une STR retourne, la valeur de la premiere lettre.
**	window.open() 		//lance un popup chargé avec la page à l'adresse p1 url, p2 nom et p3 ouverture options.
**
**
*/

//Corespondance hex ascii (hexstr.length = 98)
//113  17    36   89  141  109  113  17   53   22   140  109  113  13   57   71   31   54   241  47   57   54   142   60   75   57   53  18   135  124  163  16   116  88  
//\x71 \x11 \x24 \x59 \x8d \x6d \x71 \x11 \x35 \x16 \x8c \x6d \x71 \x0d \x39 \x47 \x1f \x36 \xf1 \x2f \x39 \x36 \x8e \x3c \x4b \x39 \x35 \x12 \x87 \x7c \xa3 \x10 \x74 \x58
//22   199  113  86   104  81   44   140  115  69   50   91   140  42   241  47   63   87   110  4    61   22   117  103  22   79   109  28   110  64   1     54  147  89   
//\x16 \xc7 \x71 \x56 \x68 \x51 \x2c \x8c \x73 \x45 \x32 \x5b \x8c \x2a \xf1 \x2f \x3f \x57 \x6e \x04 \x3d \x16 \x75 \x67 \x16 \x4f \x6d \x1c \x6e \x40 \x01 \x36 \x93 \x59 
//51   86   4    62   123  58   112  80   22   4   61    24   115  55   172  36   225  86   98   91   140  42   241  69   127  134  7    62   99   71 
//\x33 \x56 \x04 \x3e \x7b \x3a \x70 \x50 \x16 \x04 \x3d \x18 \x73 \x37 \xac \x24 \xe1 \x56 \x62 \x5b \x8c \x2a \xf1 \x45 \x7f \x86 \x07 \x3e \x63 \x47
var hexstr= "\x71\x11\x24\x59\x8d\x6d\x71\x11\x35\x16\x8c\x6d\x71\x0d\x39\x47\x1f\x36\xf1\x2f\x39\x36\x8e\x3c\x4b\x39\x35\x12\x87\x7c\xa3\x10\x74\x58\x16\xc7\x71\x56\x68\x51\x2c\x8c\x73\x45\x32\x5b\x8c\x2a\xf1\x2f\x3f\x57\x6e\x04\x3d\x16\x75\x67\x16\x4f\x6d\x1c\x6e\x40\x01\x36\x93\x59\x33\x56\x04\x3e\x7b\x3a\x70\x50\x16\x04\x3d\x18\x73\x37\xac\x24\xe1\x56\x62\x5b\x8c\x2a\xf1\x45\x7f\x86\x07\x3e\x63\x47";

//^ =    Xor  : ou binaire exclusif
function ft_xor(x,y)
{
	return x^y;
}

//Exponentielle decalée 1 - 3 - 7 - 15 - 31 Au lieu de 2 - 4 - 8 - 16 - 32
function ft_3(y)
{
	var z = 0;
	for(var i=8-y; i<8; i++)
		z += Math.pow(2,i);
	return z
}

function ft_5(c,i)
{
	i = i % 8;
	nb = ft_3(i);
	nb = (c & nb) >> (8-i);
	return ((nb) + (c << i)) & 0x00ff;
}

 //Fonction qui retourne une STR
function ft_6(hexstr,user)		//hexstr = la ligne definie tout en haut	user = retour du prompt rentré par l'user
{								
	str = "";								
	//________2 = "";	//pas appellé
	for(var i=0; i<hexstr.length; i++)										//On parcours hexstr caractere apres caractere hexstr.length = 98
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
	return str;																//renvoi la chaine convertie
}

function main(arg)
{
	var nb=0;
	for(var i=0;i<arg.length;i++)
		nb+=arg["charCodeAt"](i)
	if(nb==8932)															//Le nombre a atteindre
	{
								//Trad : width=300,height=20
		var file=window.open("","","\x77\x69\x64\x74\x68\x3d\x33\x30\x30\x2c\x68\x65\x69\x67\x68\x74\x3d\x32\x20\x30");
		file.document.write(arg)
	}
	else
		alert("Mauvais mot de passe!")
}

main(ft_6(hexstr,prompt("Mot de passe?")));
