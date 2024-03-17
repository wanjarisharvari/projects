#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>

void ledDisplay(const std::string& inputString, int delay_ms) {
    for (char c : inputString) {
        std::cout << c << "\r" << std::flush; // \r moves the cursor to the beginning of the line
        Sleep(delay_ms); // Sleep for the specified milliseconds    }
}
}

int main() {
    std::string userInput;
    int delay_ms = 100; // Adjust the delay to control the speed of the LED display

    std::cout << "Type a string: ";
    std::getline(std::cin, userInput);

    ledDisplay(userInput, delay_ms);

    return 0;
}

