#include "pixel.h"
#include "hash.h"
#include <iostream>
#include <vector>

void Pixel::rewrite(int r, int g, int b)
{
    red = boundsCheck(r);
    green = boundsCheck(g);
    blue = boundsCheck(b);
}

void Pixel::print()
{
    std::cout << "R: " << red << "  G: " << green << "  B: " << blue << std::endl;
}

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

int Pixel::getRed() const
{
    return red;
}

int Pixel::getGreen() const
{
    return green;
}

int Pixel::getBlue() const
{
    return blue;
}

bool operator ==(const Pixel& p1, const Pixel& p2)
{
    if((p1.getRed() == p2.getRed()) && (p1.getGreen() == p2.getGreen()) && (p1.getBlue() == p2.getBlue()))
        return true;

    return false;
}
