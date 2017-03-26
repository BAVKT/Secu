/*
Obfuscation 
.Niveau : Tr�s Difficile
.By Hel0ck
.The mission : 
	Retrouvez le password :)
	Vous allez en baver HAHAHAHAHHAHHHAHAHHAHAHAHAHHA :x
	
	/!\ ---------------------------------------------------
	INFO !
	Pour que le script marche, vous devez d'abord trouver comment d�coder le ttt.js 
	Ce n'est pas trop difficile, faut chercher :D
	------------------------------------------------------- /!\
	
	You need my help ? IRC : irc.root-me.org #root-me
*/

t1 = 'function recfn0(){ return 0;}';
t2 = 0; 
t3 = '';

eval(t1); 														//		Trouve un resultat a :  'function recfn0(){ return 0;}'

for(t10 = 0; t10 < parseInt(100.15786224552145); t10++)			//(?) 	Fais une boucle de 0 a 99
{ 
	n = t10+1; 													//		n = nb d'iteration +1
	t3 += 'function recfn'+n+'(){ return recfn'+t10+'();}';  	//		Et t3 += des trucs chelous
}
eval(t3); 														//		On fait une eval de t3
eval(recfn100());  												//(?)	Je sais pas ce que c'est recfn
t4 = this;														//		t4 devient l'objet courant

for(t5 in t4) 													//(?)
{
	if(t5.length == parseInt(10.125625)) 						//(?)	si la longueur de t5 = 10
	{
		if(t5.charCodeAt(0) == Math.min(115,12654)) 			//(?)	Compare le caractere UTF16 de la case 0 de t5 avec 115
		{
			if(t5.charCodeAt(9) == 116) break; 					//(?) 	Si t5[9] == 116 On break
		}
	}
} 
var t11 = new Date(); 											//		Cree un objet avec l'heure et la date actuelle
t9 = t11['getSeconds'](); 										//(?) 	t9 les secondes de la date enregistrées dans t11
t4[t5]('t13("'+login.password.value+'")', t14(2000));  			//(?)		
function t14(v0) 												
{ 
	var v1,v2,v3,v4,v5,d,r; 

	v1 = v0;
	v2 += v1>>(v4-v1);
	v3 -= v4+v1+1337; 
	v5 = r^v3+v1; 
	return v1; 
}  

function v3(v6) 												//(Fonction troll)	Retourne la valeur passee en argument	
{ 
	return v6;
} 

function _______________1(PKDFjidfjezif8756265) 				//(Fonction troll)	Retourne la valeur passee en argument
{ 
	t16 = PKDFjidfjezif8756265; 
	t17 = 145; 

	if(t16==1)
	{
		return parseInt(1.256); 								
	} 
	if(t16==2)
	{
		return parseInt(2.145); 								
	} 
	if(t16==3)
	{
		return parseInt(3.145);													
	} 
	if(t16>3) 													
	{ 
		t16 = t17+t16-t17; 										
		return t16;
	} 
	return t16; 
} 

function t19(t14 ,t15) 											//(Fonction troll ou alors dans tts.js) MEME PAS APPELE CETTE FONCTION DE MERDE
{ 
	t12 = '8aZ{E$+rT yU}1#2(IOP<qs,DFg.)H*Jk~L6M7]W;X%VxB:N!^-03/9[4&5|"?Kz';
	t9 = escape(t15+t14+"eDer");
	output = ""; 

	var a1, a2, a3 = "";
	var _3, _1, _2, _0 = "";
	t6 = 0;
	t13 = t12;
	do 
	{ 
		a1 = t9.charCodeAt(t6++);
		a2 = t9.charCodeAt(t6++);
		a3 = t9.charCodeAt(t6++); 
		_3 = a1 >> _______________1(2);
		_1 = ((a1 & _______________1(3)) << 4) | (a2 >> _______________1(4));
		_2 = ((a2 & _______________1(15)) << _______________1(2)) | (a3 >> 6);
		_0 = a3 & 63;  
		if (isNaN(a2)) 
		{ 
			_2 = _0 = 64;
		} 
		else if (isNaN(a3)) 
		{ 
			_0 = 64; 
		}

		output = output + t13.charAt(_3) + t12.charAt(_1) + t13.charAt(_2) + t12.charAt(_0);
		if(arguments.callee.toString().length != 1731)
		{ 
			output = "ESF0 ('7p(:5J";
		} 
		a1 = a2 = a3 = "";
		_3 = _1 = _2 = _0 = "";
	} 
	while (t6 < t9.length);
	if(v7(output, t2) == v7("}8iH5:}Ypi}*VL}", 13)+v3("^2d2S*,~")+":"+String["fr"+"om"+"C"+"harCode"](74,76,69,83,70,48,32,40,39,55,112,40,44,53,74,39,60,44,50,112,114,70,69,47,87))
	{ 
		window.location.href = t14+".php";
	} 
	else 
	{ 
		alert("MOUHAHAHAHHAHAHAHAHA"); 
	} 
} 

function v7(v8, t2) 										//(Fonction troll) Appelé dans t19 qui n'est jamais appelé...
{ 
	v9 = ""; 
	v10 = ""; 
	t15 = 0000000000; 
	for(t15; t15< 13-2; t15++) 
	{ 
		v9 = v8.length^t2; 
		if(v9 != "") 
			v9 = ""; 
	} 
	v11 = v9; 
	v10 = v11; 
	for(i = 0; i < v8.length; i++)
	{
		if(v11 == "ESF0 ('7p(,5J')") 
		{
			v11 += String[unescape("66%72%6f%6d%43%68%61%72%43%6f%64%65")](t2 ^ v8.charCodeAt(i)+12);}else{v11 += String.fromCharCode(t2 ^ v8.charCodeAt(i));
		}      
	} 
	if(arguments.callee.toString().length != 1169)
	{ 
		v11 = "ESF0 ('7p(:5J";
	}
	if(v10 == "sfeze5825qsde8rfq--")
	{
		for(t6 = 0; t6 > -1; t6++)
		{
			v10 = "\x6e\x6f\x6f\x62\x20\x6e\x6f\x6f\x62";
		}
	}
	return v11;
} 





























