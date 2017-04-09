function getSploitsValidated()
{
	aj=getHTTPObject();
	aj.open("GET", "/content/checksploits.php",true);
	aj.send(null);
	aj.onreadystatechange=function()
	{
		if (aj.readyState==4)
		{
			if (aj.status==200 || window.location.href.indexOf("http")==-1)
			{
				if (aj.responseText != "")
				{
					// on affiche les div les uns a la suite des autres.
					x = document.getElementsByClassName("sploitsBox");
					nb = x.length*60+160;
					//aj.responseText
					res = aj.responseText;
					while (res.indexOf('<div class="sploitsBox">') != -1)
					{
						res = res.replace('<div class="sploitsBox">', '<div style="top:'+nb+'px;" class="sploitsBox">');
						nb += 60;
					}
					document.body.innerHTML += res ;
				}
			}
		}
	}

}
getSploitsValidated()
setInterval(getSploitsValidated,60000);