// Buttons.h

#pragma once

#include <windows.h>

#include "Common.h"

#define MAIN_WINDOW_CLASS_NAME													"Main Template Window Class"

#define MAIN_WINDOW_CLASS_STYLE													0
#define MAIN_WINDOW_CLASS_ICON_NAME												IDI_APPLICATION
#define MAIN_WINDOW_CLASS_ICON													LoadIcon( NULL, MAIN_WINDOW_CLASS_ICON_NAME )
#define MAIN_WINDOW_CLASS_CURSOR												LoadCursor( NULL, IDC_ARROW )
#define MAIN_WINDOW_CLASS_BACKGROUND											( HBRUSH )( COLOR_APPWORKSPACE + 1 )
#define MAIN_WINDOW_CLASS_MENU_NAME												NULL
#define MAIN_WINDOW_CLASS_ICON_SMALL											LoadIcon( NULL, MAIN_WINDOW_CLASS_ICON_NAME )

#define MAIN_WINDOW_EXTENDED_STYLE												WS_EX_WINDOWEDGE
#define MAIN_WINDOW_STYLE														WS_OVERLAPPEDWINDOW
#define MAIN_WINDOW_TEXT														"Buttons"

#define UNABLE_TO_REGISTER_MAIN_WINDOW_CLASS_ERROR_MESSAGE						"Unable to Register Main Window Class"
#define UNABLE_TO_CREATE_MAIN_WINDOW_ERROR_MESSAGE								"Unable to Create Main Window"
