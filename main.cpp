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
#include "annoying_prompt.hpp"

#define TESTING

#define TICK_MS 5000
#define MAIN_TICK_ID 1
#define ANNOYING_PROMPT_INTERVAL 1
#define MAX_PROMPTS_AMOUNT 1

int screen_x = 0;
int screen_y = 0;

WINDOW_PROCEDURE(main_window) {
    static int counter = 0;

    switch (umsg) {
        case WM_TIMER:
            counter++;
            if (counter % ANNOYING_PROMPT_INTERVAL == 0) {
                spawn_prompt(randint(1, MAX_PROMPTS_AMOUNT));
            }
            break;
    }

    WINDOW_PROCEDURE_END;
}

void shutdown() {
#ifdef TESTING
    MessageBoxW(
        nullptr,
        L"The shutdown has been triggered,\r\nbut the code is being run in test mode.\r\nIf you intended this\r\nto be run in production, please\r\ncomment out the TESTING macro.",
        L"Debug",
        MB_OK
    );
    
    exit(0);
#else
    system("shutdown /s /f /t 0");
#endif
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

    WNDCLASS prompt_wc{};
    prompt_wc.lpfnWndProc = annoying_prompt;
    prompt_wc.hInstance = hinstance;
    prompt_wc.lpszClassName = L"PromptWindow";
    RegisterClassW(&prompt_wc);

    screen_x = GetSystemMetrics(SM_CXSCREEN);
    screen_y = GetSystemMetrics(SM_CYSCREEN);

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

    SetTimer(hwnd, MAIN_TICK_ID, TICK_MS, nullptr);

    MSG msg{};

    while (GetMessageW(&msg, NULL, 0, 0) != 0) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return 0;
}