#include "Dec_Dic.h"
#include <string.h>
#include <string>
#include <climits>

Dictionary::Dictionary()
{
    nums = UINT_MAX;
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

