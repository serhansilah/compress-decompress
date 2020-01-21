//
//  Dictionary.cpp
//  compress-program
//
//  Created by Serhan Silahyürekli on 16.11.2019.
//  Copyright © 2019 Serhan Silahyürekli. All rights reserved.
//

#include "Dictionary.h"
#include <string.h>
#include <string>
#include <climits>



Dictionary::Dictionary()
{
   nums = UINT_MAX;//max number for unside integer
   chars = "";
}
Dictionary:: Dictionary(int a, string c)
{
    nums = a;
    chars = c;
}
Dictionary::Dictionary(const Dictionary & rhs)
{
    nums = rhs.nums;
    chars = rhs.chars;
}
void Dictionary::operator=( const Dictionary &rhs)
{
    nums = rhs.nums;
    chars = rhs.chars;
}
bool Dictionary:: operator ==(const Dictionary & rhs) const
{
    if(chars == rhs.chars)
    {
        return true;
    }
    return false;
}
bool Dictionary:: operator !=(const Dictionary & rhs) const
{
    if(chars != rhs.chars)
    {
        return true;
    }
    return false;
}

