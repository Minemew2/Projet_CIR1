var tableautotal = get_request_result()

var realisator = tableautotal[1];
var nbFilms = tableautotal[2]

var nombreDeLignes = realisator.length;
var tableauHTML = '<table>';

tableauHTML += '<tr>';
tableauHTML += '<th>Index</th>';
tableauHTML += '<th>Realisator</th>';
tableauHTML += '<th>Nombre de Films</th>';
tableauHTML += '</tr>';

for (var i = 0; i < nombreDeLignes; i++) {
    tableauHTML += '<tr>';
    tableauHTML += '<td>' + i + '</td>';
    tableauHTML += '<td>' + realisator[i] + '</td>';
    tableauHTML += '<td>' + nbFilms[i] + '</td>';
    tableauHTML += '</tr>';
}

tableauHTML += '</table>';

document.body.innerHTML += tableauHTML;

