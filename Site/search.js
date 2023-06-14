let tableautotal = get_request_result();

var title = tableautotal[1];
var time = tableautotal[2]
var category = tableautotal[3]
var tableauHTML = '<table>';

console.log(String(time));
console.log(String(category));

console.log("nombre ", tableautotal.length);


tableauHTML += '<tr>';
tableauHTML += '<th>Index</th>';
tableauHTML += '<th>Title</th>';
tableauHTML += '<th>Time</th>';
tableauHTML += '<th>Category</th>';
tableauHTML += '</tr>';

for (var i = 0; i < title.length; i++) {
    tableauHTML += '<tr>';
    tableauHTML += '<td>' + i + '</td>';
    tableauHTML += '<td>' + title[i] + '</td>';
    tableauHTML += '<td>' + time[i] + '</td>';
    tableauHTML += '<td>' + category[i] + '</td>';
    tableauHTML += '</tr>';
}

tableauHTML += '</table>';

document.body.innerHTML += tableauHTML;