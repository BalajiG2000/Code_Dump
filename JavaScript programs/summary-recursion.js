function summary(num) {
    if(num === 1) {
        return num;
    }
    return summary(num-1)+num
}

console.log(summary(100))
