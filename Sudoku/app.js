var board = [
    [0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0]
]

var seed = [1,2,3,4,5,6,7,8,9]
//randomizeSeed
//seed.sort(function(a, b){return 0.5 - Math.random()});

var easy = 41, medium = 52, hard = 60;
var mode = easy;
var selected= false;

function select(row, col)
{
    displayBoard();
    if (selected.row == row && selected.col == col) {
        selected = false
        return;
    }
    selected = {row, col}
    //highlight row and column
    for (var i = 0; i < 9; i++)
    {
        document.getElementById(row+'-'+i).setAttribute('class','highlight')
        document.getElementById(i+'-'+col).setAttribute('class','highlight')
    }
}

function checkBox(row, col, value, newboard)
{
    var row_i = Math.floor(row/3)*3;
    var col_i = Math.floor(col/3)*3;
    for (var i = row_i; i<row_i+3; i++)
    {
        for (var j = col_i; j < col_i+3;j++)
        {
            if (newboard[i][j] == value)
                return false;
        }
    }
    return true;
}

function checkRowCol(row, col, value, newboard)
{
    for (var i = 0; i < 9; i++)
    {
        if (newboard[row][i] == value ||
            newboard[i][col] == value)
            return false;
    }
    return true;
}

function isValid(row, col, value, newboard)
{
    return checkBox(row, col, value, newboard) && checkRowCol(row, col,value, newboard);
}

function displayBoard()
{
    var string="";
    for (var i = 0; i < 9 ; i++)
    {
        if (i == 3 || i == 6) string += "------+-------+------\n";
        for (var j = 0; j < 9; j++)
        {
            //console.log(i,j)
            if (j == 3 || j == 6) string += "| ";
                string += board[i][j] +" ";
            if (board[i][j] != 0)
                document.getElementById(i+'-'+j).innerHTML = board[i][j]
            document.getElementById(i+'-'+j).setAttribute('onclick', 'select('+i+','+j+')')
            document.getElementById(i+'-'+j).setAttribute('class', '')
        }
        string += "\n"

    }
}

function findVacant(newboard)
{
    for (var row = 0; row < 9; row++)
    {
        for (var col = 0; col < 9; col++)
        {
            if (newboard[row][col] == 0) return {row, col}
        }
    }
    return false;
}

function backtrack(newboard)
{
    var pos = findVacant(newboard);
    if (pos === false) {
        return true;
    }

    for (var i = 0; i<9;i++)
    {
        if (isValid(pos.row, pos.col, seed[i], newboard)){
            newboard[pos.row][pos.col] = seed[i];
            if (backtrack(newboard)) return newboard;
            newboard[pos.row][pos.col] = 0;
        }
    }
    return false;
}

function turn(value)
{
    if (selected == false) return
    if (board[selected.row][selected.col] != 0)
        alert('invalid move')
    board[selected.row][selected.col] = value;
    selected = false
    displayBoard()
}

function hide()
{
    var hidden = [];
    for (var i = 0; i < mode; i++)
    {
        do{
            var row = Math.floor(Math.random() * 9) ;
            var col = Math.floor(Math.random() * 9) ;
            var isExist = false;
            for (var j = 0; j < hidden.length; j++)
            {
                if (hidden[j][0] == row && hidden[j][1] == col) {
                    isExist = true;
                }
            }
            if (!isExist) {
                board[row][col] = 0;
                hidden.push([row, col]);
            }
        } while (isExist);
    }
}

board = backtrack(board)
hide();
displayBoard()