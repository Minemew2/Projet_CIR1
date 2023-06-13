

let _box = document.createElement("div");
var tab = new Array();
tab[0] = 'Index';
tab[1] = 'Réalisateur';
tab[2] = 'Titre';
tab[3] = 'Catégorie';


let responseText = zreadFile();
console.log(responseText);
var pointVirgule = ';';
if(category(responseText) == 0){
    document.location.href="site.html"
}