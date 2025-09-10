// ButtonWindow.cpp

#include "ButtonWindow.h"

// Global variables
static LinkedList g_linkedList;
static int g_nNextID			= BUTTON_WINDOW_FIRST_ID;
static int g_nNextLeft			= BUTTON_WINDOW_FIRST_LEFT;
static int g_nNumberOfButtons	= 0;

BOOL ButtonWindowCreate( HWND hWndParent, HINSTANCE hInstance, LPCTSTR lpszShortcutFileName )
{
	BOOL bResult = FALSE;

	HWND hWndButton;

	// Create button window
	hWndButton = CreateWindowEx( BUTTON_WINDOW_EXTENDED_STYLE, BUTTON_WINDOW_CLASS_NAME, BUTTON_WINDOW_TEXT, BUTTON_WINDOW_STYLE, g_nNextLeft, 0, BUTTON_WINDOW_WIDTH, BUTTON_WINDOW_HEIGHT, hWndParent, ( HMENU )( INT_PTR )g_nNextID, hInstance, NULL );

	// Ensure that button window was created
	if( hWndButton )
	{
		// Successfully created button window
		HRESULT hResult;

		// Initialise com library
		hResult = CoInitialize( 0 );

		// Ensure that com library was initialised
		if( SUCCEEDED( hResult ) )
		{
			// Successfully initialised com library
			IShellLinkA *lpShellLink;

			// Create shell link
			hResult = CoCreateInstance( CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLink, ( LPVOID * )&lpShellLink );

			// Ensure that shell link was created
			if( SUCCEEDED( hResult ) )
			{
				// Successfully created shell link
				IPersistFile *lpPersistFile;

				// Get persist file
				hResult = lpShellLink->QueryInterface( IID_IPersistFile, ( LPVOID * )&lpPersistFile );

				// Ensure that persist file was got
				if( SUCCEEDED( hResult ) )
				{
					// Successfully got persist file
					WCHAR wszShortcutFileName[ STRING_LENGTH ];

					// Convert short-cut file name to wide format
					MultiByteToWideChar( CP_ACP, 0, lpszShortcutFileName, -1, wszShortcutFileName, STRING_LENGTH );

					// Load short-cut into persist file
					hResult = lpPersistFile->Load( wszShortcutFileName, STGM_READ );

					// Ensure that short-cut was loaded into persist file
					if( SUCCEEDED( hResult ) )
					{
						// Successfully loaded short-cut into persist file

						// Allocate string memory
						LPTSTR lpszTargetPath = new char[ STRING_LENGTH + sizeof( char ) ];

						// Get target path
						hResult = lpShellLink->GetPath( lpszTargetPath, STRING_LENGTH, NULL, ( SLGP_UNCPRIORITY | SLGP_RAWPATH ) );

						// Ensure that target path was got
						if( SUCCEEDED( hResult ) )
						{
							// Successfully got target path
							SHFILEINFO shFileInfo;

							// Get target file icon information
							if( SHGetFileInfo( lpszTargetPath, 0, &shFileInfo, sizeof( SHFILEINFO ), SHGFI_ICON ) )
							{
								// Successfully got target file icon information

								// Set target icon as button image
								SendMessage( hWndButton, BM_SETIMAGE, ( WPARAM )IMAGE_ICON, ( LPARAM )shFileInfo.hIcon );

								// Add button to linked list
								g_linkedList.AddNode( g_nNextID, hWndButton, lpszTargetPath );

								// Update number of buttons
								g_nNumberOfButtons ++;

								// Update global variables for next button
								g_nNextID ++;
								g_nNextLeft += BUTTON_WINDOW_WIDTH;

								// Update return value
								bResult = TRUE;

							} // End of successfully got target file icon information

						} // End of successfully got target path

						// Free string memory
						delete [] lpszTargetPath;

					} // End of successfully loaded short-cut into persist file

				} // End of successfully got persist file

			} // End of successfully created shell link

			// Un-initlalise com library
			CoUninitialize();

		} // End of successfully initialised com library

	} // End of successfully created button window

	return bResult;

} // End of function ButtonWindowCreate

BOOL ButtonWindowGetTargetPath( int nID, LPTSTR lpszTargetPath )
{
	// Get target path
	return g_linkedList.GetTargetPath( nID, lpszTargetPath );

} // End of function ButtonWindowGetTargetPath

BOOL ButtonWindowIsValid( int nID )
{
	BOOL bResult = FALSE;

	int nLastButtonID;

	// Calculate last button id
	nLastButtonID = ( BUTTON_WINDOW_FIRST_ID + g_nNumberOfButtons );

	// See if id is a button
	if( ( nID >= BUTTON_WINDOW_FIRST_ID ) && ( nID <= nLastButtonID ) )
	{
		// Id is a button

		// Update return value
		bResult = TRUE;

	} // End of id is a button

	return bResult;
}
