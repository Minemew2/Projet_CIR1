var tableautotal=get_request_result()
var realisator=tableautotal[1];
var title=tableautotal[3]
var time=tableautotal[4]
var category=tableautotal[5]

var nombreDeLignes = title.length;
var tableauHTML = '<table>';

tableauHTML += '<tr>';
tableauHTML += '<th>Index</th>';
tableauHTML += '<th>Realisator</th>';
tableauHTML += '<th>Title</th>';
tableauHTML += '<th>Time</th>';
tableauHTML += '<th>Category</th>';
tableauHTML += '</tr>';

for (var i = 0; i < nombreDeLignes; i++) {
    tableauHTML += '<tr>';
    tableauHTML += '<td>' + i + '</td>'; 
    tableauHTML += '<td>' + realisator[i] + '</td>'; 
    tableauHTML += '<td>' + title[i] + '</td>'; 
    tableauHTML += '<td>' + time[i] + '</td>'; 
    tableauHTML += '<td>' + category[i] + '</td>'; 
    tableauHTML += '</tr>';
}

tableauHTML += '</table>';

document.body.innerHTML += tableauHTML;