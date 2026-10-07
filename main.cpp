// Main entry point of the annoying program.
// GitHub repository at https://github.com/darkp435/annoying-program
// Quote of this file:
// "hear me out on the crucifix it has moonlight inside"
//  - some random guy in one of probablypikit's stream chat
//
// NOTES:
// 1. This program does not function on MacOS or Linux
// 2. Always use the wide string version of Win32 functions

// Contains windows.h so we do not need to include it
#include "utils.hpp"

WINDOW_PROCEDURE(main_window) {
    switch (umsg) {
            
    }

    WINDOW_PROCEDURE_END;
}

int WINAPI wWinMain(HINSTANCE hinstance, HINSTANCE, PWSTR cmdline, int cmdshow) {
    int result = MessageBoxW(
        nullptr, 
        L"This is a very annoying program.\r\n\r\nContinue?", 
        L"Confirmation", 
        MB_YESNO | MB_ICONINFORMATION
    );

    if (result == IDNO) return 0;

    WNDCLASS wc{};
    wc.lpfnWndProc = main_window;
    wc.hInstance = hinstance;
    wc.lpszClassName = L"MainWindow";
    RegisterClassW(&wc);

    HWND hwnd = CreateWindowExW(
        0,
        L"MainWindow",
        nullptr,
        0, 0, 0, 0, 0,
        HWND_MESSAGE,
        nullptr,
        hinstance,
        nullptr
    );

    return 0;
}