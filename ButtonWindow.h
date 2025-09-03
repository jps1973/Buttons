// ButtonWindow.h

#pragma once

#include <windows.h>
#include <commctrl.h>

#define BUTTON_WINDOW_CLASS_NAME												WC_BUTTON

#define BUTTON_WINDOW_EXTENDED_STYLE											0
#define BUTTON_WINDOW_STYLE														( WS_CHILD | WS_VISIBLE | BS_ICON )
#define BUTTON_WINDOW_TEXT														NULL

#define BUTTON_WINDOW_ID														WM_USER

#define BUTTON_WINDOW_WIDTH														32
#define BUTTON_WINDOW_HEIGHT													32

BOOL ButtonWindowCreate( HWND hWndParent, HINSTANCE hInstance );
