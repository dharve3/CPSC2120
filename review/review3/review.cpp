#include "review.h"
#include <iostream>

void ReadStdIn2() {
    int count = 0;
    std::string line;

    while (std::getline(std::cin, line) && line != "q") {
        std::cout << line << std::endl;
        count++;
    }

    std::cout << count;
}