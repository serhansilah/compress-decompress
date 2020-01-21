#ifndef Dec_Dic_h
#define Dec_Dic_h
#include <string.h>
#include <string>
#include <climits>

using namespace std;

class Dictionary
{
public:
    Dictionary();
    Dictionary(int a, string c);
    Dictionary(const Dictionary & rhs);
    int nums;
    string chars;
    void operator=( const Dictionary & rhs);
    bool operator == (const Dictionary & rhs) const;
    bool operator != (const Dictionary & rhs) const;
};

#endif /* Dec_Dic_h */
