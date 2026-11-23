#include <bits/stdc++.h> 
#include "CPU_TEST.h"   
#include "page_replacement.h" 
#include "deadlock_detection.h"
#include "memory_management.h" 
#include "mutex.h" 
using namespace std;

void runCPUScheduling();
void disk_scheduling();
void runPageReplacement();
void runBankersAlgorithm();
void simulateMemoryManagement();
void runSynchronizationSimulation() ;

void showMainMenu() {
    cout << "\n========== OS SIMULATOR ==========\n";
    cout << "1. CPU Scheduling Algorithms\n";
    cout << "2. Page Replacement Algorithms\n";
    cout << "3. Deadlock Detection (Banker's Algorithm)\n";
    cout << "4. Memory Management (Fit Strategies)\n";
    cout << "5. Mutex\n";
    cout << "0. Exit\n";
    cout << "==================================\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    while (true) {
        showMainMenu();
        cin >> choice;
        switch (choice) {
            case 1: runCPUScheduling(); break;
            //case 2: disk_scheduling(); break;
            case 2: runPageReplacement(); break;
            case 3: runBankersAlgorithm(); break;
            case 4: simulateMemoryManagement(); break;
            case 5: runSynchronizationSimulation(); break;
            case 6: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}