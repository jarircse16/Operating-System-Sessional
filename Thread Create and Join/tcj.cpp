#include <iostream>
#include <thread>

void threadFunction() {
    std::cout << "Thread is running." << std::endl;
}

int main() {
    std::thread t(threadFunction); // Create a thread
    t.join(); // Wait for the thread to finish
    std::cout << "Main thread is done." << std::endl;
    return 0;
}
