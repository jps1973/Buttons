// ButtonWindow.cpp

#include "ButtonWindow.h"

// Global variables
static HWND g_hWndButton[ BUTTON_WINDOW_NUMBER_OF_BUTTONS ];

BOOL ButtonWindowCreate( HWND hWndParent, HINSTANCE hInstance, HFONT hFont )
{
	BOOL bResult = FALSE;

	int nWhichButton;

	LPCTSTR lpszButtonWindowTitles [] = BUTTON_WINDOW_TITLES;

	// Loop through buttons
	for( nWhichButton = 0; nWhichButton < BUTTON_WINDOW_NUMBER_OF_BUTTONS; nWhichButton ++ )
	{
		// Create button window
		g_hWndButton[ nWhichButton ] = CreateWindowEx( BUTTON_WINDOW_EXTENDED_STYLE, BUTTON_WINDOW_CLASS_NAME, lpszButtonWindowTitles[ nWhichButton ], BUTTON_WINDOW_STYLE, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWndParent, ( HMENU )INT_PTR( BUTTON_WINDOW_FIRST_BUTTON_ID + nWhichButton ), hInstance, NULL );

		// Ensure that button window was created
		if( g_hWndButton[ nWhichButton ] )
		{
			// Successfully created button window

			// Set button window font
			SendMessage( g_hWndButton[ nWhichButton ], WM_SETFONT, ( WPARAM )hFont, ( LPARAM )TRUE );

			// Update return value
			bResult = TRUE;

		} // End of successfully created button window
		else
		{
			// Unable to create button window

			// Update return value
			bResult = FALSE;

			// Force exit from loop
			nWhichButton = BUTTON_WINDOW_NUMBER_OF_BUTTONS;

		} // End of unable to create button window

	} // End of loop through buttons

	return bResult;

} // End of function ButtonWindowCreate

BOOL ButtonWindowMove( int nTop, int nBorderSize )
{
	BOOL bResult = FALSE;

	int nWhichButton;

	int nLeft = nBorderSize;

	// Loop through buttons
	for( nWhichButton = 0; nWhichButton < BUTTON_WINDOW_NUMBER_OF_BUTTONS; nWhichButton ++ )
	{
		// Move button window
		if( MoveWindow( g_hWndButton[ nWhichButton ], nLeft, nTop, BUTTON_WINDOW_WIDTH, BUTTON_WINDOW_HEIGHT, TRUE ) )
		{
			// Successfully moved button window

			// Update left position
			nLeft += ( BUTTON_WINDOW_WIDTH + nBorderSize );

			// Update return value
				bResult = TRUE;

		} // End of successfully moved button window
		else
		{
			// Unable to move button window

			// Update return value
			bResult = FALSE;

			// Force exit from loop
			nWhichButton = BUTTON_WINDOW_NUMBER_OF_BUTTONS;

		} // End of unable to move button window

	} // End of loop through buttons

	return bResult;

} // End of function ButtonWindowMove