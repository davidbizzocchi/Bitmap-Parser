/**
    windows_file_dialog.cpp
    Purpose: Allows user to select a bitmap image to parse

    @author David Bizzocchi
    @version 1.0
    @date 12/11/2018
*/

#include "windows_file_dialog.h"

#include <windows.h>
#include <iostream>

/**
    windows_file_dialog::selectBMP - allows user to select bitmap file from file explorer

    @param pointer for file that is to be selected.
    @return none.
*/
void windows_file_dialog::selectBMP(char* filePointer)
{
    OPENFILENAME ofn;       // common dialog box structure
    char szFile[260];       // buffer for file name
    HWND hwnd;              // owner window

// Initialize OPENFILENAME
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFile = szFile;
// Set lpstrFile[0] to '\0' so that GetOpenFileName does not
// use the contents of szFile to initialize itself.
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "BMP Files (*.bmp)\0*.bmp\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

// Display the Open dialog box.

    if (GetOpenFileName(&ofn)==TRUE)
    {
        std::cout << szFile << std::endl;
        strcpy(filePointer,szFile);
    }
}
