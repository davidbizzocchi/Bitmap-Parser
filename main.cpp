#include <iostream>
#include "parser.h"
#include "html_builder.h"
#include "windows_file_dialog.h"

using namespace std;

int main()
{
    Parser p;
    char* filePointer = (char *)malloc(261);

    cout << "Select a file to parse" << endl;

    windows_file_dialog::selectBMP(filePointer);

    cout << "Parsing image..." << endl;

    p.parseimage(filePointer);

    cout << "Writing to HTML file..." << endl;

    //html_builder::create(p.getPixelVector());
    html_builder::create(p.getPixelSet());

    //p.clearPixelVector();

    return 0;
}
