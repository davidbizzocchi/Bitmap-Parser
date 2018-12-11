/**
    pixel.cpp
    Purpose: Defines object for each pixel
             when parsing through bitmap file

    @author David Bizzocchi
    @version 1.0
    @date 12/11/2018
*/

#include "pixel.h"
#include "hash.h"
#include <iostream>
#include <vector>

/**
    Pixel::rewrite - overwrites RGB information

    @param red, blue, and green integer values to write in.
    @return none.
*/
void Pixel::rewrite(int r, int g, int b)
{
    red = boundsCheck(r);
    green = boundsCheck(g);
    blue = boundsCheck(b);
}

/**
    Pixel::print - prints all information about pixel object

    @param none.
    @return none.
*/
void Pixel::print()
{
    std::cout << "R: " << red << "  G: " << green << "  B: " << blue << std::endl;
}

/**
    Pixel::boundsCheck - ensures given value is within 0-255 range

    @param value to check.
    @return corrected value.
*/
int Pixel::boundsCheck(int val)
{
    if(val < 0)
    {
        return 0;
    }
    else if(val > 255)
    {
        return 255;
    }

    return val;
}

/**
    Pixel::getRed - returns pixel red value.

    @param none.
    @return pixel red value.
*/
int Pixel::getRed() const
{
    return red;
}

/**
    Pixel::getGreen - returns pixel green value.

    @param none.
    @return pixel green value.
*/
int Pixel::getGreen() const
{
    return green;
}

/**
    Pixel::getBlue - returns pixel blue value.

    @param none.
    @return pixel blue value.
*/
int Pixel::getBlue() const
{
    return blue;
}

/**
    Overloaded == operator

    @param Two pixel objects to compare.
    @return True if equal, false otherwise'
*/
bool operator ==(const Pixel& p1, const Pixel& p2)
{
    if((p1.getRed() == p2.getRed()) && (p1.getGreen() == p2.getGreen()) && (p1.getBlue() == p2.getBlue()))
        return true;

    return false;
}
