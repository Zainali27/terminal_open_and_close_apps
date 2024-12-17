#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>

void listRunningProcesses() {
    std::cout << "Listing running applications...\n";
    // Updated command to filter out background processes
    std::string command = "tasklist /FI \"STATUS eq RUNNING\" /FI \"SESSION eq 1\""; // Only show foreground apps
    std::system(command.c_str());
}

void closeProcess(int pid) {
    // Using stringstream instead of to_string
    std::stringstream ss;
    ss << pid;
    std::string pidStr = ss.str();
    
    std::string command = "taskkill /PID " + pidStr + " /F"; // Added /F to force termination
    std::system(command.c_str());
    std::cout << "Process with PID " << pid << " terminated.\n";
}

int main() {
    int choice;
    
    do {
        std::cout << "\n1. List running applications\n";
        std::cout << "2. Close an application by PID\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose an option: ";
        
        std::cin >> choice;

        if (choice == 1) {
            listRunningProcesses();
        } else if (choice == 2) {
            int pid;
            std::cout << "Enter the PID of the process to close: ";
            std::cin >> pid;
            closeProcess(pid);
        } else if (choice != 3) {
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    std::cout << "Exiting program.\n";
    return 0;
}
