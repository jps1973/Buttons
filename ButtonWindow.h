// ButtonWindow.h

#pragma once

#include <windows.h>
#include <commctrl.h>

#include "Ascii.h"
#include "Common.h"

#define BUTTON_WINDOW_CLASS_NAME												WC_BUTTON

#define BUTTON_WINDOW_EXTENDED_STYLE											0
#define BUTTON_WINDOW_STYLE														( WS_CHILD | WS_VISIBLE | BS_FLAT | BS_VCENTER )
#define BUTTON_WINDOW_TEXT														"Go"

#define BUTTON_WINDOW_WIDTH														60
#define BUTTON_WINDOW_HEIGHT													25

#define BUTTON_WINDOW_TITLES													{ "Browse...", "Filter...", "Copy...", "Move...", "Delete...", "Rename", "About" }

#define BUTTON_WINDOW_FIRST_BUTTON_ID											WM_USER

typedef enum ButtonWindowButtons
{
	BUTTON_WINDOW_BROWSE_BUTTON = 0,
	BUTTON_WINDOW_FILTER_BUTTON,
	BUTTON_WINDOW_COPY_BUTTON,
	BUTTON_WINDOW_MOVE_BUTTON,
	BUTTON_WINDOW_DELETE_BUTTON,
	BUTTON_WINDOW_RENAME_BUTTON,
	BUTTON_WINDOW_ABOUT_BUTTON,

	BUTTON_WINDOW_NUMBER_OF_BUTTONS

} BUTTON_WINDOW_BUTTONS;

BOOL ButtonWindowCreate( HWND hWndParent, HINSTANCE hInstance, HFONT hFont );

BOOL ButtonWindowMove( int nTop, int nBorderSize );
