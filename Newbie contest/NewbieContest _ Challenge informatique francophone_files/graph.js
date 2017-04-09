function doGraph(nb, tot, div)
{
	document.write(nb);

	fact = 20;
	percent = (Math.log(nb+fact) - Math.log(fact))/ (Math.log(tot+fact)-Math.log(fact)) ;
	if (percent < 0.50 )
	{
		red = 255 ;
		green = Math.min(percent*2*255,255) ;
	}
	else
	{
		green = 255;
		red = Math.max((1-percent)*2*255, 0);
	}

  var boxes = document.getElementsByClassName(div);
  for (var i=0; i < boxes.length; i++)
  {
    boxes.item(i).style.backgroundColor = "rgb("+Math.floor(red)+", "+Math.floor(green)+", 0)" ;
    boxes.item(i).style.width = Math.floor(128*percent)+"px";    
    boxes.item(i).style.height = "21px";    
    boxes.item(i).style.display = "inline-block";    
    boxes.item(i).style.float = "left";    
    boxes.item(i).style.verticalAlign = "middle";    
    boxes.item(i).style.margin = "1px";    
  }
/*

	document.getElementById(div).style.backgroundColor = "rgb("+Math.floor(red)+", "+Math.floor(green)+", 0)" ;

	document.getElementById(div).style.width = Math.floor(128*percent)+"px";
	document.getElementById(div).style.height = "21px";
	document.getElementById(div).style.display = "inline-block";
	document.getElementById(div).style.float = "left";
	document.getElementById(div).style.verticalAlign = "middle";
	document.getElementById(div).style.margin = "1px";
*/
}
