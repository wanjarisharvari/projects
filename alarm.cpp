#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

bool isAlarmSet = false;
int alarmHour = 0;
int alarmMinute = 0;

void setAlarm() {
    isAlarmSet = true;
    std::cout << "Enter the hour of the alarm (0-23): ";
    std::cin >> alarmHour;

    std::cout << "Enter the minute of the alarm (0-59): ";
    std::cin >> alarmMinute;

    std::cout << "Alarm set for " << alarmHour << ":" << alarmMinute << std::endl;
}

void displayCurrentTime() {
    while (true) {
        // Get the current time
        time_t currentTime = time(0);
        tm* localTime = localtime(&currentTime);

       std::cout << "\r";
        for (int i = 0; i < 10; i++) {
            std::cout << " ";  // Print spaces to clear the line
        }
        std::cout << "\r";

        // Display the current hour and minute
        std::cout << "Current time: " << localTime->tm_hour << ":" << localTime->tm_min << ":" << localTime->tm_sec;
        std::cout.flush();

        // Wait for 1 second before updating the time
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}



int main() {
    while (true) {
        // Get the current time
        time_t currentTime = time(0);
        tm *localTime = localtime(&currentTime);

        // Check if the alarm is set and ring if it's time
        if (isAlarmSet) {
            time_t currentTime = time(0);
            tm* localTime = localtime(&currentTime);

            if (localTime->tm_hour == alarmHour && localTime->tm_min == alarmMinute) {
                
                while(true){
                std::cout << "\a"; // Ring the alarm (output may vary based on the system
                std::cout << "\nALARM ALARM ALARM !!!";
                char choice ;
                std::cout << "\nDo you want to snooze or stop the alarm? Press (s/n): ";
                std::cin >> choice;

                if (choice == 's') {
                    //displayCurrentTime();
                    std::this_thread::sleep_for(std::chrono::seconds(20));
                    // Snooze for 5 minutes
                } else if (choice == 'n') {
                    isAlarmSet = false;
                    break ; // Stop the alarm
                    }
                }
            }
        }

        // Clear the previous output using '\r' and spaces
        std::cout << "\r";
        for (int i = 0; i < 10; i++) {
            std::cout << " ";  // Print spaces to clear the line
        }
        std::cout << "\r";

        // Display the current hour and minute
        std::cout << "Current time: " << localTime->tm_hour << ":" << localTime->tm_min << ":" << localTime->tm_sec;
        std::cout.flush();

        // Check if the user wants to set an alarm
        if (!isAlarmSet) {
            char choice;
            std::cout << "\nSet alarm? Press (y/n) : ";
            std::cin >> choice;

            if (choice == 'y') {
                setAlarm();
            } else if (choice == 'n') {
                displayCurrentTime();
                break; // Exit the program if '1' is pressed
            }
        }

        // Wait for 1 second
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}