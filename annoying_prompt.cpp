#include "utils.hpp"

WINDOW_PROCEDURE(annoying_prompt) {
    WINDOW_PROCEDURE_END;
}

void spawn_prompt(int amount) {
    for (int _ = 0; _ < amount; _++) {
        HWND hwnd = CreateWindowExW(
            WS_EX_TOPMOST | WS_EX_TOOLWINDOW,
            L"PromptWindow",
            L"ATTENTION",
            WS_OVERLAPPEDWINDOW,
            0, 0,
            screen_x / 10, screen_y / 10,
            nullptr, nullptr, GetModuleHandleW(nullptr), nullptr
        );

        ShowWindow(hwnd, SW_SHOW);
    }
}

#ifdef STANDALONE
int main() {
    screen_x = GetSystemMetrics(SM_CXSCREEN);
    screen_y = GetSystemMetrics(SM_CYSCREEN);
    WNDCLASS wc{};
    wc.hInstance = GetModuleHandleW(nullptr);
    wc.lpfnWndProc = annoying_prompt;
    wc.lpszClassName = L"PromptWindow";
    RegisterClassW(&wc);
    spawn_prompt(1);
    return 0;
}
#endif