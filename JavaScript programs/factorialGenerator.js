// Program that generates factorial of a number

function factorial(n){
    //base case
    if(n == 0 || n == 1){
        return 1;
    //recursive case
    }else{
        return n * factorial(n-1);
    }
}
let n = 9;
answer = factorial(n)
console.log("Factorial of " + n + " is " + answer);
