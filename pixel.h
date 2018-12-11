/**
    pixel.h
    Purpose: Defines object for each pixel
             when parsing through bitmap file

    @author David Bizzocchi
    @version 1.0
    @date 12/11/2018
*/

#ifndef PIXEL_H_INCLUDED
#define PIXEL_H_INCLUDED

#include <iostream>

class Pixel
{
public:

    Pixel()
    {
        red = 0;
        green = 0;
        blue = 0;
    }

    void rewrite(int r, int g, int b);
    void print();
    int getRed() const;
    int getGreen() const;
    int getBlue() const;

    friend bool operator< (const Pixel& p1, const Pixel& p2);
    friend bool operator== (const Pixel& p1, const Pixel& p2);

private:
    int red;
    int green;
    int blue;
    int boundsCheck(int val);
};

#endif // PIXEL_H_INCLUDED
