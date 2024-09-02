#include "review.h"
#include <iostream>

void ReadWrite() {
    int count = 0;
    std::string s1, total = "";

    while (std::cin >> s1 && s1 != "q") {
        total = total + s1 + " ";
        count++;
    }

    std::cout << total << std::endl;
    std::cout << count;
}