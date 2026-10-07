// Utilities, specifically for the Win32 API.

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define WINDOW_PROCEDURE(func_name) \
    LRESULT CALLBACK func_name(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)

#define WINDOW_PROCEDURE_END return DefWindowProc(hwnd, umsg, wparam, lparam)