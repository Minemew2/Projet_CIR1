function donnees() {
    var real = document.getElementById("real").value;
    var duree = document.getElementById("duree").value;
    var categorie = document.getElementById("categorie").value;
    

    let id_form = [];
    let func = [];
    if (real) {
        id_form.push(real);
        func.push("1");
        console.log(func);
    }
    if (duree) {
        console.log(duree);
        id_form.push(duree);
        console.log(id_form);
        func.push("2");
    }
    /*if (categorie) {
        writeFile(categorie,3);
    }*/
    writeFile(id_form, func);
}
