#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include "pixel.h"

struct KeyHasher
{
  std::size_t operator()(const Pixel& p) const
  {
    using std::size_t;
    using std::hash;

    return ((hash<int>()(p.getRed())
             ^ (hash<int>()(p.getGreen()) << 1)) >> 1)
             ^ (hash<int>()(p.getBlue()) << 1);
  }
};


#endif // HASH_H_INCLUDED
