var realisator=["James Cameron", "Steven Spielberg","James Cameron"]
var title=["Titanic", "Indiana Jones","Avatar"]
var time=["120", "90","180"]

var nombreDeLignes = realisator.length;
var tableauHTML = '<table>';

tableauHTML += '<tr>';
tableauHTML += '<th>Index</th>';
tableauHTML += '<th>Title</th>';
tableauHTML += '<th>Realisator</th>';
tableauHTML += '<th>Time</th>';
tableauHTML += '</tr>';

for (var i = 0; i < nombreDeLignes; i++) {
    tableauHTML += '<tr>';
    tableauHTML += '<td>' + i + '</td>'; 
    tableauHTML += '<td>' + title[i] + '</td>'; 
    tableauHTML += '<td>' + realisator[i] + '</td>'; 
    tableauHTML += '<td>' + time[i] + '</td>'; 
    tableauHTML += '</tr>';
}

tableauHTML += '</table>';

document.body.innerHTML += tableauHTML;