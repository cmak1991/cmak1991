function average(numbers) {
    let n = numbers.length;
    for (n in array) {
        var sum = sum + numbers[n];
    }
    return sum / numbers.length;
}

var array = [1, 5, 2, 3, 7];
var mean = average(array);
console.log(mean);
