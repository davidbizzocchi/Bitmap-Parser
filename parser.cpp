#include "parser.h"
#include "pixel.h"
#include "html_builder.h"
#include "hash.h"
#include <iostream>
#include <vector>
#include <algorithm>

#include <iostream>
#include <unordered_set>

unsigned char* Parser::parseimage(char* filePointer)
{
    Pixel pix;

    FILE* f = fopen(filePointer, "rb");

    //std::unordered_set<Pixel, KeyHasher> pixelSet;

    if(f == NULL)
    {
        std::cout << "Could not open file: " << filePointer << std::endl;
        throw "Argument Exception";
    }

    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];

    std::cout << std::endl;
    std::cout << "  Name: " << filePointer << std::endl;
    std::cout << " Width: " << width << std::endl;
    std::cout << "Height: " << height << std::endl;

    int row_padded = (width*3 + 3) & (~3);
    unsigned char* data = new unsigned char[row_padded];

    for(int i = 0; i < height; i++)
    {
        fread(data, sizeof(unsigned char), row_padded, f);
        for(int j = 0; j < width*3; j += 3)
        {
            // Comes in as (B, G, R) set to (R, G, B)
            pix.rewrite((int)data[j+2], (int)data[j+1], (int)data[j]);

            // determine if pixel has been found previously
            //if(std::find(pixelVector.begin(), pixelVector.end(), pix) == pixelVector.end())
            //if(binary_search(pixelVector.begin(), pixelVector.end(), pix))
            //{
                //pixelVector.push_back(pix);
                pixelSet.insert(pix);
                //pix.print();
                //std::cout << "size :" << (int)pixelVector.size() << "/" << (int)pixelVector.capacity() << std::endl;
            //}
        }
    }

    fclose(f);
    return data;
}

std::vector<Pixel> Parser::getPixelVector()
{
    return pixelVector;
}

std::unordered_set<Pixel, KeyHasher> Parser::getPixelSet()
{
    return pixelSet;
}

void Parser::clearPixelVector()
{
    pixelVector.clear();
}
