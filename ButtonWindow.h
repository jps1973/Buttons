// ButtonWindow.h

#pragma once

#include <windows.h>
#include <commctrl.h>
#include <shlobj.h>

#include "Common.h"

#include "LinkedListClass.h"

#define BUTTON_WINDOW_CLASS_NAME												WC_BUTTON

#define BUTTON_WINDOW_EXTENDED_STYLE											0
#define BUTTON_WINDOW_STYLE														( WS_CHILD | WS_VISIBLE | BS_ICON )
#define BUTTON_WINDOW_TEXT														NULL

#define BUTTON_WINDOW_FIRST_ID													WM_USER
#define BUTTON_WINDOW_FIRST_LEFT												0

#define BUTTON_WINDOW_WIDTH														32
#define BUTTON_WINDOW_HEIGHT													32

BOOL ButtonWindowCreate( HWND hWndParent, HINSTANCE hInstance, LPCTSTR lpszShortcutFileName );

int ButtonWindowCreate( HWND hWndParent, HINSTANCE hInstance );

BOOL ButtonWindowGetTargetPath( int nID, LPTSTR lpszTargetPath );

BOOL ButtonWindowIsValid( int nID );
