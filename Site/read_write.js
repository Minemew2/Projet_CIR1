// ------- WRITE FILE -------
function writeFile(id_form,func) {
    var element = document.createElement('a');
    let i;
    let textToSave = 0;
    let text;
    let data;
    if(id_form.length >1){
        for(i = 0; i < (id_form.length); i++){
            text = id_form[i];
            data = func[i];
            switch(i){
                case 0 :
                    textToSave = data + ";" + text + "\n"; 
                    return;
                case id_form.length :
                    textToSave += data + ";" + text; 
                    return;
                default :
                    textToSave += data + ";" + text + "\n";
                    return;
            }
        }
    }else if(id_form.length == 1){
        text = id_form;
        data = func;
        textToSave = data + ";" + text;    
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



function category(text){
    switch(text[0]){
        case 0 :
            return 0;
        case 1 :
            return 1;
        case 2 :
            return 2;
        case 3 :
            return 3;
        case 4 :
            return 4;
        case 5 :
            return 5;
    }
}