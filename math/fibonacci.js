function fibonacci(n) {
  if (n <= 2) {
    return 1;
  }
  else {
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

OR

const fibonacci = n => 2 < n ? fibonacci(n-1) + fibonacci(n-2) : 1;
