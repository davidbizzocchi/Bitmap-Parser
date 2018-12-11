#include "html_builder.h"
#include "pixel.h"
#include <fstream>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <windows.h>

void html_builder::create(std::unordered_set<Pixel, KeyHasher> pixelSet)
{
    std::ofstream myfile (".\\report.html");
    myfile << "<!DOCTYPE html><html><head></head><body>"; //starting html

    //add some html content
    //as an example: if you have array of objects featuring the properties name & value, you can print out a new line for each property pairs like this:
    for (Pixel p : pixelSet)
    {
        //std::cout << p.getRed() << ", "<< p.getGreen() << ", " << p.getBlue() << std::endl;
        myfile << "<p style=\"background-color:rgb("<< p.getRed() <<", "<< p.getGreen() <<", "<<p.getBlue()<<");\">"
        << p.getRed() << ", " << p.getGreen() << ", " << p.getBlue() << "</p>";
    }

    /*for (Pixel p : pixelVector)
    {
        //std::cout << p.getRed()<<", "<<p.getGreen()<<", "<<p.getBlue() << std::endl;
        myfile << "<p style=\"background-color:rgb("<<p.getRed()<<", "<<p.getGreen()<<", "<<p.getBlue()<<");\">"
        << p.getRed()<<", "<<p.getGreen()<<", "<<p.getBlue() << "</p>";
    }*/

   //ending html
    myfile << "</body></html>";
    myfile.close();
}
