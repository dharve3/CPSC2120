#include "review.h"

int Fibonacci(int a) {
    if (a <= 0)        // base case 0
        return 0;
    else if (a == 1)   // base case 1
        return 1;
    else
        return Fibonacci(a - 1) + Fibonacci(a - 2);
}