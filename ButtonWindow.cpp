// ButtonWindow.cpp

#include "ButtonWindow.h"

// Global variables
static HWND g_hWndButton;

BOOL ButtonWindowCreate( HWND hWndParent, HINSTANCE hInstance )
{
	BOOL bResult = FALSE;

	// Create button window
	g_hWndButton = CreateWindowEx( BUTTON_WINDOW_EXTENDED_STYLE, BUTTON_WINDOW_CLASS_NAME, BUTTON_WINDOW_TEXT, BUTTON_WINDOW_STYLE, 0, 0, BUTTON_WINDOW_WIDTH, BUTTON_WINDOW_HEIGHT, hWndParent, ( HMENU )BUTTON_WINDOW_ID, hInstance, NULL );

	// Ensure that button window was created
	if( g_hWndButton )
	{
		// Successfully created button window

		// Update return value
		bResult = FALSE;

	} // End of successfully created button window

	return bResult;

} // End of function ButtonWindowCreate
