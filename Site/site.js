function donnees() {
    var real = document.getElementById("real").value;
    var duree = document.getElementById("duree").value;
    var categorie = document.getElementById("categorie").value;

    let id_forms = [];
    let funcs = [];
    if (real) {
        id_forms.push(real);
        funcs.push("1");
    }
    if (duree) {
        id_forms.push(duree);
        funcs.push("2");
    }
    writeFile(id_forms, funcs);
}

function top() {
    let id_form = "trois";
    let func = "3";
    writeFile(id_form, func);
}

function rank() {
    let id_form = "quatre";
    let func = "4";
    writeFile(id_form, func);
}