// Utilities, specifically for the Win32 API.

#pragma once

#define UNICODE
#define _UNICODE
#define WIN32_LEAN_AND_MEAN
#define NOGDI
#include <windows.h>
#include <random>

extern int screen_x;
extern int screen_y;

struct Vec2 {
    int x;
    int y;
};

#define WINDOW_PROCEDURE(func_name) \
    LRESULT CALLBACK func_name(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)

#define WINDOW_PROCEDURE_END return DefWindowProc(hwnd, umsg, wparam, lparam)

inline int randint(int high, int low) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(low, high);
    return dist(gen);
}

inline Vec2 randomize_screen_coord() {
    Vec2 res(randint(screen_x, 0), randint(screen_y, 0));

    return res;
}