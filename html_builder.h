/**
    html_builder.h
    Purpose: Builds html file from given unique pixel set

    @author David Bizzocchi
    @version 1.0
    @date 12/11/2018
*/

#ifndef HTML_BUILDER_H_INCLUDED
#define HTML_BUILDER_H_INCLUDED

#include <unordered_set>
#include <vector>

#include "hash.h"

class html_builder
{
public:
    static void create(std::unordered_set<Pixel, KeyHasher> pixelSet);
    //static void create(std::vector<Pixel> vect);
};

#endif // HTML_BUILDER_H_INCLUDED
