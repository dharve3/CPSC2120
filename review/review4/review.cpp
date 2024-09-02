#include "review.h"
#include <iostream>

void ReadWrite() {
    std::string s1, total = "";

    while (std::cin >> s1 && s1 != "q") {
        total = total + s1 + " ";
    }

    std::cout << total << std::endl;
}