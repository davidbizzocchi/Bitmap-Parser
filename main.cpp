/**
    main.cpp
    Purpose: Runs the program

    @author David Bizzocchi
    @version 1.0
    @date 12/11/2018
*/

#include <iostream>
#include "parser.h"
#include "html_builder.h"
#include "windows_file_dialog.h"

int main()
{
    Parser p;
    char* filePointer = (char *)malloc(261);

    std::cout << "Select a file to parse" << std::endl;

    windows_file_dialog::selectBMP(filePointer);

    std::cout << "Parsing image..." << std::endl;

    p.parseimage(filePointer);

    std::cout << "Writing to HTML file..." << std::endl;

    html_builder::create(p.getPixelSet());

    delete[] filePointer;

    return 0;
}
