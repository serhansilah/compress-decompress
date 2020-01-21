#include <iostream>
#include "Dec_Dic.h"
#include "Dec_Hash.h"
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

bool first = true;
int sized = 256;

string decompress(HashTable<Dictionary> & temp,string ch, string arr[4096],string & prev,string & curr)
{
    
    string newst;
    Dictionary notinside;
  
    string asci;
    int index = stoi(ch);
    if(first)//for first number because we do not need to insert new string into hash table just for this case
    {
        prev = arr[index];//previous string
        curr = arr[index];//current string
        first = false;
		return temp.find(Dictionary(sized, prev)).chars;//return that number's string in hash table
    }
	else
	{
		if (arr[index].length() < 1 )//if array's that index empty
		{
			arr[index] = prev + curr[0];//create new string with previuos and currents first char
			prev = arr[index];//previous changed
			if (sized < 4096)
			{
				temp.insert(Dictionary(index, prev));//insert new string into hash table
			}
			sized++;//size incremented
			return temp.find(Dictionary(sized, prev)).chars;//return that number's string in hash table

		}
		else
		{
			curr = arr[index];//current changed
			newst = prev + curr[0];//create new string with previuos and currents first char
			arr[sized] = newst;//insert new string into array
			prev = curr;//previous changed
			if (sized < 4096)
			{
				temp.insert(Dictionary(index, newst));//insert new string into hash table
			}
			sized++;
			return  temp.find(Dictionary(sized, curr)).chars;//return that number's string in hash table
		}
	}
	return "";//never comes here
}

int main()
{
    ifstream file;
	ofstream outfile;
    string filename = "compout.txt";
	string outname = "decompout.txt";
	outfile.open(outname.c_str());
    file.open(filename.c_str());
    string ch,asci;
	string prev, curr;//for array
    string text = "";
    Dictionary d;
    string arr[4096];
	HashTable<Dictionary> dictionary(d, 4096);
    for(int i = 0; i < 256 ;i++)//1-256 ascii insert in our array
    {   asci = i;
        arr[i] = asci;
    }
	for (int i = 0; i < 256; i++)//1-256 ascii insert in our hash table
	{
		asci = i;
		dictionary.insert(Dictionary(i, asci));
	}
    if(file.fail())
    {
        cout << "File did not open.";
        return 0;
    }
    while(file >> ch)//read every number
    {
 
        outfile << decompress(dictionary ,ch ,arr,prev,curr);//decompress file and written into outfile 
    }
    file.close();
	outfile.close();
	
    

    return 0;
}
