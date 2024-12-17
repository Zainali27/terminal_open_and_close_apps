#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
using namespace std;

void listRunningProcesses() {
    cout << "Listing running applications...\n";
    // Updated command to filter out background processes
    string command = "tasklist /FI \"STATUS eq RUNNING\" /FI \"SESSION eq 1\""; // Only show foreground apps
    system(command.c_str());
}

void closeProcess(int pid) {
    // Using stringstream instead of to_string
    stringstream ss;
    ss << pid;
    string pidStr = ss.str();
    
    string command = "taskkill /PID " + pidStr + " /F"; // Added /F to force termination
    system(command.c_str());
    cout << "Process with PID " << pid << " terminated.\n";
}

int main() {
    int choice;
    
    do {
        cout << "\n1. List running applications\n";
        cout << "2. Close an application by PID\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        
        cin >> choice;

        if (choice == 1) {
            listRunningProcesses();
        } else if (choice == 2) {
            int pid;
            cout << "Enter the PID of the process to close: ";
            cin >> pid;
            closeProcess(pid);
        } else if (choice != 3) {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    cout << "Exiting program.\n";
    return 0;
}