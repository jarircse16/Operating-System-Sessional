#include <iostream>
#include <thread>
#include <vector>

void printNumbers(int start, int end) {
    for (int i = start; i <= end; ++i) {
        std::cout << i << " ";
    }
}

int main() {
    std::vector<std::thread> threads;

    // Create four threads to print numbers in parallel
    for (int i = 1; i <= 4; ++i) {
        threads.push_back(std::thread(printNumbers, (i - 1) * 25 + 1, i * 25));
    }

    // Wait for all threads to finish
    for (std::thread& t : threads) {
        t.join();
    }

    std::cout << "\nAll threads have finished.\n";

    return 0;
}
