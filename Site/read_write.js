// ------- WRITE FILE -------
function writeFile(id_form,func) {
    var element = document.createElement('a');
    let i;
    let textToSave = [];
    if(id_form.length >1){
        for(i = 0; i < (id_form.length -1); i++){
            let text = id_form[i];
            let data = func[i];
            textToSave += data + ";" + text + "\n";
        }
    }
    let text = id_form[id_form.length];
    let data = func[id_form.length];
    textToSave += data + ";" + text;    

    element.setAttribute('href', 'data:text/plain;charset=utf-8,' + encodeURIComponent(textToSave));
    element.setAttribute('download', 'request.txt');

    element.style.display = 'none';
    document.body.appendChild(element);
    element.click();
    document.body.removeChild(element);

   // text1.submit();
}
// -------------------------


// ------- READ FILE -------
function readFileByName(fileName){

    let xhr = new XMLHttpRequest();
    do {
        xhr.open("GET", fileName, false);
        xhr.send(null);

    }while(xhr.status === 404);

    // assumes status 200
    return xhr.responseText;
}

function zreadFile(){
    readFileByName("ready.txt");
    return readFileByName("results.txt");
}
// -------------------------
