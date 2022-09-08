#include <stdio.h>
#include <stdlib.h>

// Because the SendInput function is only supported in
// Windows 2000 and later, WINVER needs to be set as
// follows so that SendInput gets defined when windows.h
// is included below.
#define WINVER 0x0500
#include <windows.h>
#include <iostream>

void main()
{

    std::cout << "~~~ quasi's lazy engineer sprinkler ~~~" << std::endl;
    std::cout << "Software worth $1 million! (TM)" << std::endl;
    std::cout << std::endl;
    std::cout << "This script presses '1' and 'tab' in under one second intervals. It assumes you have not modified those keys in Guild Wars 2's settings." << std::endl;
    std::cout << "To exit, simply close this window." << std::endl;
    std::cout << std::endl;
    std::cout << "Beginning lazy sprinkler in 5 seconds ..." << std::endl;

    Sleep(5000);

    std::cout << "Program running. Watch watch windows are active!" << std::endl;

    INPUT input;
    unsigned int delay = 500;

    while (true) {
        // Key codes
        // 0x09 - tab
        // 0x31 - '1' on the row

        // Set up keyboard event
        input.type = INPUT_KEYBOARD;
        input.ki.wScan = 0;
        input.ki.time = 0;
        input.ki.dwExtraInfo = 0;

        // Press the '1' key
        input.ki.wVk = 0x31;
        input.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &input, sizeof(INPUT));

        // Release the '1' key
        input.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(INPUT));


        Sleep(delay);

        // Set up keyboard event
        input.type = INPUT_KEYBOARD;
        input.ki.wScan = 0;
        input.ki.time = 0;
        input.ki.dwExtraInfo = 0;

        // Press the '1' key
        input.ki.wVk = 0x31;
        input.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &input, sizeof(INPUT));

        // Release the '1' key
        input.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(INPUT));


        Sleep(delay);

    }
}
