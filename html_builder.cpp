#include "html_builder.h"
#include "pixel.h"
#include <fstream>
#include <unordered_set>
#include <windows.h>

void html_builder::create(std::unordered_set<Pixel, KeyHasher> pixelSet)
{
    std::ofstream myfile (".\\report.html");
    myfile << "<!DOCTYPE html><html><head></head><body>"; //starting html

    //add some html content
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
