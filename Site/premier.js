var realisator=["James Cameron"]
var title=["Titanic","Avatar"]
var time=["120","180"]
var category=["Drama","Science Fiction"]

var nombreDeLignes = title.length;
var tableauHTML = '<table>';

tableauHTML += '<tr>';
tableauHTML += '<th>Index</th>';
tableauHTML += '<th>Title</th>';
tableauHTML += '<th>Time</th>';
tableauHTML += '<th>Category</th>';
tableauHTML += '</tr>';

for (var i = 0; i < nombreDeLignes; i++) {
    tableauHTML += '<tr>';
    tableauHTML += '<td>' + i + '</td>'; 
    tableauHTML += '<td>' + title[i] + '</td>'; 
    tableauHTML += '<td>' + time[i] + '</td>'; 
    tableauHTML += '<td>' + category[i] + '</td>'; 
    tableauHTML += '</tr>';
}

tableauHTML += '</table>';

document.body.innerHTML += tableauHTML;