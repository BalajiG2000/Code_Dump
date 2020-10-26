// Program that checks if all numbers of an array (given as argument) are prime numbers.
function allPrime(nums) {
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === 1) {
            console.log('false (1)');
            return false;
        }
        for (let j = 2; j < nums[i]; j++) {

            if (nums[i] % j  === 0) {
                console.log('There is at least one number on this array that is not prime.');
                return false;
            } 
        }
    }
    console.log('All numbers on this array are primes!');
    return true;
}

allPrime([1,5,3]);
