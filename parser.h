#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <vector>
#include <unordered_set>
#include <stdio.h>
#include "pixel.h"
#include "hash.h"

class Parser
{
public:

    unsigned char* parseimage(char* filePointer);

    std::vector<Pixel> getPixelVector();

    std::unordered_set<Pixel, KeyHasher> getPixelSet();

    void clearPixelVector();

private:

    std::vector<Pixel> pixelVector;

    std::unordered_set<Pixel, KeyHasher> pixelSet;
};


#endif // PARSER_H_INCLUDED
