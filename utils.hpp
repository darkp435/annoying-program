// Utilities, specifically for the Win32 API.

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <random>

#define WINDOW_PROCEDURE(func_name) \
    LRESULT CALLBACK func_name(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)

#define WINDOW_PROCEDURE_END return DefWindowProc(hwnd, umsg, wparam, lparam)

inline int randint(int high, int low) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(low, high);
    return dist(gen);
}