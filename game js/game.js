// create secret number
var secretNumber = 4;
 
//as user for guess
var guess =Number(prompt("guess a number"));

// check if guess is right
if(guess === secretNumber){
  alert("you got it right");
}
//otherwise, check if higher or lower
else if(guess> secretNumber){
  alert("Too High Guess again");
}
 else
 {
  alert("Too low Guess again");
}