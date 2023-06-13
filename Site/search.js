let nbfilms=3;
let titre=["Titanic","Avatar","Indiana Jones"];
let realisator=["James Cameron","James Cameron","Steven Spielberg"];;
let duree=["120","180","90"];;

for (let i = 0; i < nbfilms; i++) {
    ajouterLigne(i,titre[i],realisator[i],duree[i]);
}


function ajouterLigne(index,titre,realisateur,duree)
{
	var tableau = document.getElementById("tableau");
	let row=document.tableau.createElement("tr");
    let col1=document.row.createElement("th");
    col1.innerhtml=index;
    let col2=document.row.createElement("th");
    col2.innerhtml=titre;
    let col3=document.row.createElement("th");
    col3.innerhtml=realisateur;
    let col4=document.row.createElement("th");
    col4.innerhtml=duree;
}