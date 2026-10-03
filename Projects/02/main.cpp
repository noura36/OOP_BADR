// g++ -std=c++17 -Wall -Wextra -Werror -g main.cpp ReadingBuffer.cpp -o main


#include <iomanip>
#include <iostream>
#include "ReadingBuffer.h"

int main() {
    std::cout << std::fixed << std::setprecision(2) << std::boolalpha;
    int x;
    std::cin >> x;
    ReadingBuffer buf1(4);  // CTOR

    if (x == 1) {
        throw std::runtime_error("Error: x is 1");
    }


    std::cout << "init      : capacity=" << buf.capacity() << " size=" << buf.size() << "\n";

    std::cout << "push 21.5 : " << buf.push(21.5) << "\n";
    std::cout << "push 22.0 : " << buf.push(22.0) << "\n";
    std::cout << "push 23.5 : " << buf.push(23.5) << "\n";
    std::cout << "push 24.0 : " << buf.push(24.0) << "\n";
    std::cout << "push 99.9 : " << buf.push(99.9) << "  <- rejected, buffer is full\n";

    double out = -1.0;
    std::cout << "get(2)    : " << buf.get(2, out) << " value=" << out << "\n";
    std::cout << "get(9)    : " << buf.get(9, out) << " value=" << out << " <- unchanged\n";
    std::cout << "get(-1)   : " << buf.get(-1, out) << " value=" << out << " <- unchanged\n";

    std::cout << "average   : " << buf.average() << "\n";

    ReadingBuffer buf2 = buf1;
    return 0;
}
