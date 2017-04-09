function BulleWrite(txt)
{
if (hidden == 1)
{
  document.getElementById("Bulle").innerHTML = "<table style=\"width:100%;\"><tr><td class=\"tCell\">"+txt+"</td></tr></table>";
  document.getElementById("Bulle").style.display = "block";
}
}

function BulleHide()
{
document.getElementById("Bulle").style.display = "none";
hidden = 1;
}

function BulleMove(event)
{

  document.getElementById("Bulle").style.top = (event.pageY+document.body.scrollTop+8)+"px";
  if (!!window.chrome && !!window.chrome.webstore)
  { // firefox detection
    document.getElementById("Bulle").style.top = (event.clientY+document.body.scrollTop+8)+"px";
  }
  document.getElementById("Bulle").style.left = (event.clientX+document.body.scrollLeft+8)+"px";
}
hidden = 1;
Html ='<div id="Bulle" style="position:absolute; left:auto; top:auto; width:auto; height:auto; z-index:210; display:none"></div>';
document.write( Html);

/*
//-------------------------------------------------------------
//  Nom Document : GFBULLE.JS
//-------------------------------------------------------------
//  Mise à Jour  : 29.05.2006
//  Objet        : Compatibilité IE6 et DOCTYPE
//  -----------------------------------------------------------
var DOM = (document.getElementById ? true : false);
var IE  = (document.all && !DOM ? true : false);
var NS4 = (document.layers ? true : false);
var NAV_OK   = ( DOM || IE || NS4);
var NETSCAPE = (navigator.appName == "Netscape");
var Mouse_X;        // Position X en Cours de la Mouse
var Mouse_Y;        // Position Y en Cours de la Mouse
var TopIndex = 1;   // Z-Index interne
var Decal_X  = 8;   // Décalage X entre Pointeur Mouse et Bulle
var Decal_Y  = 8;   // Décalage Y entre Pointeur Mouse et Bulle
var bBulle= false;  // Flag Affichage de la Bulle
//---------------------
function GetObjet(div_){
  if( DOM) return document.getElementById(div_);
  if( IE)  return document.all[div_];
  if( NS4) return document.layers[div_];
}
//---------------------
function GetStyle(div_){
  return (NS4 ? GetObjet(div_) : GetObjet(div_).style);
}
//---------------------
function ObjHide( div_){
  var Obj = null;
  if( div_){
    Obj = GetStyle( div_);
    if( Obj){
      Obj.visibility= "hidden";
    }
  }
  return(true);
}
//-------------------------
function ObjShow( div_, z_){
  var Obj = null;
  if( div_){
    Obj = GetStyle( div_);
    if( Obj){
      Obj.visibility = "visible";
      if( arguments[1] != null)
        Obj.zIndex = z_;
      else
        Obj.zIndex = TopIndex++;
    }
  }
  return(true);
}
//-----------------------------
function ObjWrite( div_, html_){
  var Obj;
  Obj = GetObjet( div_);
  if( Obj) with( Obj){
    if( !NS4){
      innerHTML = html_;
    }
    else{
      document.open();
      document.write( html_);
      document.close();
    }
  }
}
//-------------------------------
function ObjMoveTo( div_, x_, y_){
  var Obj = null;
  var Arg = arguments;
  if( div_){
    Obj = GetStyle( div_);
    if( Obj){
      if( Arg[1] != null) Obj.left = x_ +"px";
      if( Arg[2] != null) Obj.top  = y_ +"px";
    }
  }
}
//------------------------------------
//  Mise à Jour  : 29.05.2006
//------------------------------------
function ObjShowAll( div_, x_, y_, z_){
  var Obj = GetObjet( div_);
  var DocRef;
  var MaxX, MaxY;
  var Top,  Left;
  var Haut, Larg;
  var SavY = y_;

  if( Obj){
    //-- Récup. dimension fenêtre et DIV
    if( NETSCAPE){
      with( window){
        Left = pageXOffset;
        Top  = pageYOffset;
        MaxX = innerWidth;
        MaxY = innerHeight;
        if( MaxX > document.width)  MaxX = document.width;
        if( MaxY > document.height) MaxY = document.height;
        MaxX += Left;
        MaxY += Top;
      }
      if( NS4){
        Larg = Obj.clip.width;
        Haut = Obj.clip.height;
      }
      else{
        Larg = Obj.offsetWidth;
        Haut = Obj.offsetHeight;
      }
    }
    else{
      if( document.documentElement && document.documentElement.clientWidth)
        DocRef = document.documentElement;
      else
        DocRef = document.body;

      with( DocRef){
        Left = scrollLeft;
        Top  = scrollTop;
        MaxX = Left + clientWidth;
        MaxY = Top  + clientHeight;
      }

      Larg = Obj.scrollWidth;
      Haut = Obj.scrollHeight;
    }
    //-- Réajuste dimension fenêtre
    MaxX -= Larg;
    MaxY -= Haut;

    //-- Application Bornage
    if( x_ > MaxX) x_ = MaxX;
    if( x_ < Left) x_ = Left;
    if( y_ > MaxY) y_ = MaxY;
    if( y_ < Top)  y_ = Top;

    //-- si en bas On réajuste
    //-- pour que la bulle ne prenne pas le focus
    if( y_== MaxY){
      var DeltaY = MaxY -SavY;
      y_ = MaxY - DeltaY -Haut -2*Decal_Y;
    }

    //-- On place la Bulle
    ObjMoveTo( div_, x_, y_);
    ObjShow( div_, z_);
  }
}
//------------------------
function BulleWrite( txt_){
 var Obj;
 var Html;
 Obj = GetObjet( 'Bulle');
 if( Obj){
    Html  = "<TABLE BORDER=0 CELLSPACING=0><TR><TD BGCOLOR='#333333'><TABLE BORDER=0 CELLSPACING=0 CELLPADDING=4 WIDTH='100%' BGCOLOR='#eeeeee'>";
    Html += "<TR><TD NOWRAP ALIGN='LEFT'>";
    Html += txt_;

    //-- Rajout pour la démo
    //Html += "<BR><HR>Position <B>onMouseOver</B><BR>Mouse : X= " +Mouse_X +" Y= " +Mouse_Y;

    Html += "</TD></TR></TABLE></TD></TR></TABLE>";
  ObjWrite  ('Bulle', Html);
  ObjShowAll('Bulle', Mouse_X +Decal_X, Mouse_Y +Decal_Y, 1000);
  bBulle= true;
  return( true);
 }
 return(false);
}
//------------------
function BulleHide(){
  ObjWrite ('Bulle', "&nbsp;");
  ObjHide  ('Bulle');
  ObjMoveTo('Bulle', 0, 0);
  bBulle= false;
  return(true);
}

//------------------------------------
//  Mise à Jour  : 29.05.2006
//------------------------------------
function WhereMouse(e){
  var DocRef;

  if( NETSCAPE){
    Mouse_X = e.pageX;
    Mouse_Y = e.pageY;
  }
  else{
    if( document.documentElement && document.documentElement.clientWidth)
      DocRef = document.documentElement;
    else
      DocRef = document.body;

    Mouse_X = event.clientX +DocRef.scrollLeft;
    Mouse_Y = event.clientY +DocRef.scrollTop;
  }
  //-- La bulle est affichée on la MOVE
  if( bBulle)
    ObjShowAll('Bulle', Mouse_X +Decal_X, Mouse_Y +Decal_Y, 1000);
}
//== INITIALISATION ==================================
//-- Capture Souris events ---------------------------
if( NETSCAPE)
  window.captureEvents( Event.MOUSEMOVE);
document.onmousemove = WhereMouse;

//-- Création STYLE Bulle et DIV----------------------
// Nota : pour NS4 le DIV doit faire parti du document
var Html;
  //-- On met du style pour la bulle
  Html  = '<STYLE TYPE="text/css">';
  Html += '.Bulle{color:#ddd;font-size:13px;font-family:Verdana;}';
  Html += '</STYLE>';
  document.write( Html);

  //-- Création du DIV Bulle
  if( !NS4){
    Html ='<div id="Bulle" style="position:absolute; left:auto; top:auto; width:auto; height:auto; z-index:0; visibility:hidden"></div>';
    document.write( Html);
  }
//-- EOF ------------------------------------------------------
*/