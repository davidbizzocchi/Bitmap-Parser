#include "parser.h"
#include "pixel.h"
#include "html_builder.h"
#include "bmp_builder.h"
#include "hash.h"
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <Windows.h>

void Parser::parseimage(char* filePointer)
{
    Pixel pix;

    FILE* f = fopen(filePointer, "rb");

    if(f == NULL)
    {
        std::cout << "Could not open file: " << filePointer << std::endl;
        throw "Argument Exception";
    }

     // read the 54-byte header
    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f);

    // extract information from header
    long width = *(long*)&info[18];
    long height = *(long*)&info[22];
    BYTE* redBuf = new BYTE[ width * 3 * height ];
    BYTE* blueBuf = new BYTE[ width * 3 * height ];
    BYTE* greenBuf = new BYTE[ width * 3 * height ];
    long long c = 0;

    // display file information
    std::cout << std::endl;
    std::cout << "  Name: " << filePointer << std::endl;
    displayInformation(info);

    // allocate data for 3 bytes per pixel
    long row_padded = (width*3 + 3) & (~3);
    unsigned char* data = new unsigned char[row_padded];

    // iterate through each row
    for(auto i = 0; i < height; i++)
    {
        // read in row data
        fread(data, sizeof(unsigned char), row_padded, f);

        // iterate through each row, moving by 3 pixels
        for(auto j = 0; j < width*3; j += 3)
        {
            // store R,G,B data in Pixel object
            pix.rewrite((int)data[j], (int)data[j+1], (int)data[j+2]);

            // add item to set if unique
            pixelSet.insert(pix);

            // B, G, R
            redBuf[ c + 0 ] = (BYTE) 0;
            redBuf[ c + 1 ] = (BYTE) 0;
            redBuf[ c + 2 ] = (BYTE) pix.getRed();

            greenBuf[ c + 0 ] = (BYTE) 0;
            greenBuf[ c + 1 ] = (BYTE) pix.getGreen();
            greenBuf[ c + 2 ] = (BYTE) 0;

            blueBuf[ c + 0 ] = (BYTE) pix.getBlue();
            blueBuf[ c + 1 ] = (BYTE) 0;
            blueBuf[ c + 2 ] = (BYTE) 0;

            c += 3;
        }
    }

    /**

BYTE* buf = new BYTE[ width * 3 * height ];
    c = 0;

    for ( int i = 0; i < width; i++ )
    {
        for ( int j = 0; j < height; j++ )
        {
            buf[ c + 0 ] = (BYTE) 255;
            buf[ c + 1 ] = (BYTE) 0;
            buf[ c + 2 ] = (BYTE) 0;

            c += 3;
        }
    } **/

    bmp_builder::SaveBitmapToFile( (BYTE*) redBuf,
                    width,
                    height,
                    24,
                    0,
                    ".\\redchannel.bmp" );

    bmp_builder::SaveBitmapToFile( (BYTE*) greenBuf,
                    width,
                    height,
                    24,
                    0,
                    ".\\greenchannel.bmp" );

    bmp_builder::SaveBitmapToFile( (BYTE*) blueBuf,
                    width,
                    height,
                    24,
                    0,
                    ".\\bluechannel.bmp" );

    delete [] redBuf;
    delete [] blueBuf;
    delete [] greenBuf;

    // close file
    fclose(f);
}

std::unordered_set<Pixel, KeyHasher> Parser::getPixelSet()
{
    return pixelSet;
}

void Parser::clearPixelSet()
{
    pixelSet.clear();
}

void Parser::displayInformation(const unsigned char* info)
{
    std::cout << "  Size: " << *(long*)&info[2] << " Bytes" << std::endl;
    std::cout << " Width: " << *(long*)&info[18] << " Pixels" << std::endl;
    std::cout << "Height: " << *(long*)&info[22] << " Pixels" << std::endl;

    switch(*(int*)&info[28])
    {
        case 1: std::cout << "   BPP: Monochrome" << std::endl;
                break;
        case 4: std::cout << "   BPP: 4-Bit Palletized" << std::endl;
                break;
        case 8: std::cout << "   BPP: 8-Bit Palletized" << std::endl;
                break;
        case 16: std::cout << "   BPP: 16-Bit Palletized" << std::endl;
                break;
        case 24: std::cout << "   BPP: 24-Bit RGB" << std::endl;
                break;
        default: std::cout << "   Error reading Bits per pixel information! " << std::endl;
    }

    std::cout << " H Res: " << *(int*)&info[38] << " Pixels Per Meter" << std::endl;
    std::cout << " V Res: " << *(int*)&info[42] << " Pixels Per Meter" << std::endl;

    std::cout << std::endl;
}
