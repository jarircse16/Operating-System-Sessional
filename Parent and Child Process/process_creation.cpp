#include <windows.h>
#include <iostream>

int main() {
    STARTUPINFO si1, si2;
    PROCESS_INFORMATION pi1, pi2;

    // Initialize the STARTUPINFO structures
    ZeroMemory(&si1, sizeof(STARTUPINFO));
    ZeroMemory(&si2, sizeof(STARTUPINFO));
    si1.cb = sizeof(STARTUPINFO);
    si2.cb = sizeof(STARTUPINFO);

    // Create child process 1
    if (CreateProcess(
            "child1.exe", // Replace with the path to your child1.exe
            NULL,
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL,
            &si1,
            &pi1)) {
        std::cout << "I am parent" << std::endl;
        WaitForSingleObject(pi1.hProcess, INFINITE); // Wait for child process to finish
        CloseHandle(pi1.hProcess);
        CloseHandle(pi1.hThread);
    } else {
        std::cerr << "CreateProcess failed (" << GetLastError() << ")" << std::endl;
        return 1;
    }

    // Create child process 2
    if (CreateProcess(
            "child2.exe", // Replace with the path to your child2.exe
            NULL,
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL,
            &si2,
            &pi2)) {
        std::cout << "I am parent" << std::endl;
        WaitForSingleObject(pi2.hProcess, INFINITE); // Wait for child process to finish
        CloseHandle(pi2.hProcess);
        CloseHandle(pi2.hThread);
    } else {
        std::cerr << "CreateProcess failed (" << GetLastError() << ")" << std::endl;
        return 1;
    }

    return 0;
}
