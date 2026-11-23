


Operating System Algorithms Simulator
A menu-driven C++ simulator for fundamental Operating System concepts. The project provides interactive implementations of CPU scheduling, page replacement, deadlock safety checking, memory allocation, and process synchronization algorithms.

Features
1. CPU Scheduling
Compare the following CPU scheduling algorithms:

First Come First Served (FCFS)
Shortest Job First (SJF) — non-preemptive
Round Robin (RR) — supports a user-defined time quantum
Shortest Job Remaining First (SJRF) — preemptive
Process details can be entered manually or generated randomly. The simulator displays each process's completion time, turnaround time, and waiting time, along with the average waiting and turnaround times.

2. Page Replacement
Simulate these page replacement algorithms:

FIFO (First In First Out)
LRU (Least Recently Used)
Optimal Page Replacement
Clock Page Replacement
Provide a page-reference string manually or generate one randomly. The frame contents are displayed after each page reference, along with the total number of page faults.

3. Deadlock Detection — Banker's Algorithm
Use Banker's Algorithm to check whether the system is in a safe state. The module accepts allocation, maximum-need, and available-resource data manually or generates sample values. It calculates the Need Matrix and displays a safe sequence when one exists.

4. Memory Management
Explore the following contiguous memory allocation strategies:

First Fit
Best Fit
Worst Fit
Enter memory-block and process sizes manually or generate them randomly. You can run one strategy or run all three separately on the same initial memory configuration to compare their allocations.

5. Process Synchronization
The synchronization module demonstrates two classic problems using C++ threads and synchronization primitives:

Producer–Consumer Problem — uses a bounded buffer, mutex, and condition variables.
Dining Philosophers Problem — uses mutex-protected forks to coordinate concurrent philosophers.
Both simulations run interactively and can be stopped by pressing Enter.

Technologies Used
C++ (compiled with GCC using GNU C++17 mode)
C++ Standard Library
Threads, mutexes, and condition variables
GCC / MinGW-w64 compiler
Project Structure
.
├── main.cpp
├── CPU_TEST.cpp
├── CPU_TEST.h
├── page_replacement.cpp
├── page_replacement.h
├── deadlock_detection.cpp
├── deadlock_detection.h
├── memory_management.cpp
├── memory_management.h
├── mutex.cpp
├── mutex.h
└── README.md
Getting Started
Prerequisites
Install a GCC compiler that supports GNU C++17 and the pthread library. On Windows, you can use a MinGW-w64 GCC environment; on Linux, install g++ through your distribution's package manager.

Compile
Run this command from the project root directory:

g++ -std=gnu++17 -pthread main.cpp CPU_TEST.cpp page_replacement.cpp deadlock_detection.cpp memory_management.cpp mutex.cpp -o os_simulator
Run
Windows (PowerShell or Command Prompt):

.\os_simulator.exe
Linux / macOS:

./os_simulator
Use the displayed menus to select a module, provide the required input, and view the simulation results.

Notes
Enter valid positive values for process counts, memory-block counts, frame counts, reference-string lengths, and the Round Robin time quantum.





