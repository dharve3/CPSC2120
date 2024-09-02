#include "review.h"
#include <iostream>

void ReadStdIn2() {
    int count = 0;
    std::string s1;

    while (std::cin >> s1 && s1 != "q") {
        count++;
    }

    std::cout << count;
}