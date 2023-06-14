// ------- READ FILE -------
function get_request_result(){

    let request_type = 0;
    let execution_time = 0;
    let realisators = [];
    let movies_number = [];
    let durations = [];
    let movies = [];
    let categories = [];

    let final_result = [];


        function readFileByName(fileName, callback){
            console.log("j'entre");
            let xhr = new XMLHttpRequest();
            xhr.onreadystatechange = function() {
                if (xhr.readyState == 4) {
            // The request is done; did it work?
                    if (xhr.status == 200) {
                // ***Yes, use `xhr.responseText` here***
                        callback(xhr.responseText);
                    } else {
                // ***No, tell the callback the call failed***
                        callback(null);
                    }
                }
            };
        xhr.open("GET", fileName);
        xhr.send();

        }

        function handleFileData(fileData) {
            if (!fileData) {
        // Show error
                return;
            }
            let lines = fileData.split('\n');
            console.log(lines);
            let line;
            
            request_type = parseInt(lines[0]);
            execution_time = parseFloat(lines[1]);

            final_result.push(execution_time);


            var real_infos = lines[2].split(";");

            switch(request_type){
                case 3:
                    realisators.push(real_infos[0]);
                    movies_number.push(real_infos[1]);
                    for(let i = 0; i< movies_number[0]; i++){
                        line = lines[3+i].split(";");
                        movies.push(line[0]);
                        durations.push(line[1]);
                        categories.push(line[2]);
                    }

                    final_result.push(realisators);
                    final_result.push(movies_number);
                    final_result.push(movies);
                    final_result.push(durations);
                    final_result.push(categories);

                    break;

                case 4:
                    for(i = 0; i<lines.length-2; i++){
                        line = lines[2+i].split(";");
                        console.log("une ligne", line);
                        realisators.push(line[0]);
                        movies_number.push(line[1]);
                    }


                    final_result.push(realisators);
                    final_result.push(movies_number);

                    break;

                default:
                    for(i = 0; i<lines.length-2; i++){
                        line = lines[2+i].split(";");
                        console.log("une ligne", line);
                        movies.push(line[0]);
                        durations.push(line[1]);
                        categories.push(line[2]);
                    }

                    final_result.push(movies);
                    final_result.push(durations);
                    final_result.push(categories);
                    break;

            }

        }


        function isReady(callback){
        
            var xhr = new XMLHttpRequest();
            xhr.open('HEAD', "ready.txt", false);
            xhr.send();

            if (xhr.status == "404") {
            console.log("File doesn't exist");
            return false;
            } else {
                console.log("File exists");
                return true;
        }

        }

    while(isReady() == false){};

    readFileByName("result.txt", handleFileData);

    return final_result;
}

console.log("result", get_request_result());
