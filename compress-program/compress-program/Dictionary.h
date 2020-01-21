//
//  Dictionary.h
//  compress-program
//
//  Created by Serhan Silahyürekli on 16.11.2019.
//  Copyright © 2019 Serhan Silahyürekli. All rights reserved.
//

#ifndef Dictionary_h
#define Dictionary_h
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


#endif /* Dictionary_h */
