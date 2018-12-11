#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "pixel.h"
#include "hash.h"
#include <unordered_set>
#include <stdio.h>

class Parser
{
public:

    void parseimage(char* filePointer);

    std::unordered_set<Pixel, KeyHasher> getPixelSet();

    void clearPixelSet();

private:

    void displayInformation(const unsigned char* info);

    std::unordered_set<Pixel, KeyHasher> pixelSet;
};


#endif // PARSER_H_INCLUDED
