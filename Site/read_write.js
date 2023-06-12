// ------- WRITE FILE -------
function writeFile(id_form,func) {
    var element = document.createElement('a');
    let i;
    let textToSave = 0;
    for(i = 0; i < id_form.length; i++){
    let text = id_form[i];
    let data = func[i];
    if(textToSave == 0){
        textToSave = data + ";" + text;
        }else{
        textToSave.push = data + ";" + text;    
        }
    }

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
