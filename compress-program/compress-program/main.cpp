#include <iostream>
#include "Header.h"
#include "Dictionary.h"
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <string>

void compress(HashTable<Dictionary> & temp,string text)
{
    int sized = 256;
    ofstream outfile;
    string outname = "compout.txt";
    outfile.open(outname.c_str());
    string asci;
    int stlength = 2;
    Dictionary w,notinside;
    for(int i = 0; i < 256 ;i++)
    {   asci = i;//1-256 ascii insert in our hash table
        temp.insert(Dictionary(i,asci));
    }
    for(int k = 0; stlength < text.length()+1;stlength++)
    {
            string str1 = text.substr(k,stlength);//we know first char will always in our table but longer one may be not
            w =Dictionary(sized,str1);
			if (notinside == temp.find(w))//notinside is empty dictionary if text which inside w dictionary is empty this statement runs
			{
				string str2 = text.substr(k, stlength - 1);
				if (sized < 4096)//after 4096 we do not need to insert
				{
					temp.insert(w);//insert that not finded text in hashtable
				}
				outfile << temp.find(Dictionary(sized, str2)).nums << " ";//longest finded string's position written to the outfile
				text = text.substr(str2.length(), text.length() - 1);//delete written string from our text
				stlength = 1;//for stlength become 2 after for loops 1 turn
				sized++;//increase size because we insert new element
			}
    }
    outfile << temp.find(Dictionary(sized,text)).nums <<" ";//for last string  because it is must be inside hash
    outfile.close();

}

int main()
{
    ifstream file;
    string filename = "compin.txt";
    file.open(filename.c_str());//open the file
    char ch;
    string text = "";
    Dictionary d;
    HashTable<Dictionary> dictionary(d,4096);
    if(file.fail())
    {
        cout << "File did not open.";
        return 0;
    }
    while(file>> ch)//read every chracter of file and add it to our string called text
    {
        text += ch;
    }
    compress(dictionary ,text);//compress function call
    file.close();
    
    return 0;
}
