#define _WINSOCKAPI_
#include "background_process_monitor.h"
#include <iostream>
#include <Windows.h>
#include <tlhelp32.h> 
#include <cstdlib>




ProcessMonitor::ProcessMonitor()
{
}

ProcessMonitor::~ProcessMonitor()
{
}

std::string ProcessMonitor::getActiveProcesses() {

    std::string processes = std::string("");


    HANDLE processSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (processSnapshot == INVALID_HANDLE_VALUE) {
        std::cerr << "Error creating process snapshot: " << GetLastError() << std::endl;
        return std::string("");
    }

    // Initialize PROCESSENTRY32 structure
    PROCESSENTRY32 processEntry;
    processEntry.dwSize = sizeof(processEntry);

    // Iterate through processes
    if (!Process32First(processSnapshot, &processEntry)) {
        std::cerr << "Error getting first process: " << GetLastError() << std::endl;
        CloseHandle(processSnapshot);
        return std::string("");
    }

    // Print process information
    do {

        if (true) { // here you can add checks on the process variable itself: pcPriClassBase, th32ParentProcessID, cntThreads  & PSEX_BACKGROUND_PROCESS
            std::cout << "Process ID: " << processEntry.th32ProcessID << std::endl;
            std::cout << "Process Name: " << processEntry.szExeFile << std::endl;
            std::cout << std::endl;
            processes = processes + "," + processEntry.szExeFile;
        }
    } while (Process32Next(processSnapshot, &processEntry));

    // Close the snapshot handle
    CloseHandle(processSnapshot);

    return processes;

}