/**
    html_builder.cpp
    Purpose: Builds html file from given unique pixel set

    @author David Bizzocchi
    @version 1.0
    @date 12/11/2018
*/

#include "html_builder.h"
#include "pixel.h"
#include <fstream>
#include <unordered_set>
#include <windows.h>

/**
    html_builder::create - creates html file of unique pixel data

    @param Set of pixels to write to html file.
    @return none.
*/
void html_builder::create(std::unordered_set<Pixel, KeyHasher> pixelSet)
{
    //create html
    std::ofstream myfile (".\\report.html");
    //starting html
    myfile << "<!DOCTYPE html><html><head></head><body>";

    //add html content
    for (Pixel p : pixelSet)
    {
        //std::cout << p.getRed() << ", "<< p.getGreen() << ", " << p.getBlue() << std::endl;
        myfile << "<p style=\"background-color:rgb("<< p.getRed() <<", "<< p.getGreen() <<", "<<p.getBlue()<<");\">"
        << p.getRed() << ", " << p.getGreen() << ", " << p.getBlue() << "</p>";
    }

   //ending html
    myfile << "</body></html>";
    myfile.close();
}
