function dataClicked() {
    let real = document.getElementById("real").value;
    let duree = document.getElementById("duree").value;
    let categorie = document.getElementById("categorie").value;
    console.log(real);
    let id_forms = [];
    let funcs = [];
    if (real) {
        console.log(real);
        id_forms.push(real);
        funcs.push("1");
    }
    if (duree) {
        id_forms.push(duree);
        funcs.push("2");
    }
    writeFile(id_forms, funcs);
    
    document.location.href = "search.html";
    
}

function firstClicked() {
    let id_form = ["trois"];
    let func = [3];
    writeFile(id_form, func);
}
function rankClicked() {
    let id_form = ["quatre"];
    let func = [4];
    writeFile(id_form, func);
}

function welcomeClicked() {

}

function closeClicked() {
    let id_form = ["cinq"];
    let func = [5];
    writeFile(id_form, func);
}
let dataButton = document.getElementById("data");
dataButton.addEventListener("click", dataClicked);

let premierButton = document.getElementById("premier");
premierButton.addEventListener("click", firstClicked);

let rankButton = document.getElementById("classement");
rankButton.addEventListener("click", rankClicked);

let accueilButton = document.getElementById("accueil");
accueilButton.addEventListener("click",welcomeClicked);

let closeButton = document.getElementById("close");
closeButton.addEventListener("click", closeClicked);
