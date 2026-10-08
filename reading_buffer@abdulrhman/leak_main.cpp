#include <iostream>
#include "ReadingBuffer.hpp"

int main() {
    std::cout << "Simulating 200000 sensor connections...\n";

    for (int i = 0; i < 200000; ++i) {
        ReadingBuffer buf;
        buf.init(1000);         // 1000 doubles = 8 KB per device
        buf.push(21.5);
        // We "forgot" buf.release(). The ReadingBuffer object dies with the
        // loop iteration, but the 8 KB on the heap does not.
    }

    std::cout << "Done. Check your memory usage before pressing Enter.\n";
    std::cin.get();
    return 0;
}