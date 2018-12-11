#ifndef BMP_BUILDER_H_INCLUDED
#define BMP_BUILDER_H_INCLUDED

#include <Windows.h>
#include <memory>

class bmp_builder
{
public:
    static void SaveBitmapToFile(BYTE* pBitmapBits,
                       LONG lWidth,
                       LONG lHeight,
                       WORD wBitsPerPixel,
                       const unsigned long& padding_size,
                       LPCTSTR lpszFileName);
};

#endif // BMP_BUILDER_H_INCLUDED
