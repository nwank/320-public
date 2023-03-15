#include <iostream>
#include <fstream>
#include <string>
#include "d_hashf.h"
#include "d_hash.h"
#include "d_except.h"

void getWord(ifstream& fin, string& w);

int main()
{

    std::cout << " " << std::endl;


    int bucket = 1373; //a hash table with with 1373 buckets.

    myhash<string, hFstring>htable(bucket);

    //Open the file
    ifstream dict ("dict.dat");

    if(dict.is_open())
    {
        ///temp string to hold current word
        string words;
        
        //insert the word into the hash table 
        for(int i = 0; i < 25025; i++)
        {
            dict >> words;
            htable.insert(words);
        }
    }
    else
    {
        std::cout << "Error!!!" << std::endl;
    }

    dict.close();

    string nameOfDoc;

    std::cout << "Enter the document name: " << std::endl;
    std::cin >> nameOfDoc;

    //opens the file to be read
    ifstream myExample (nameOfDoc);

    string myExampleWord;
    if(myExample.is_open())
    {
        //until the file has reached the end
        while(!myExample.eof())
        {
            getWord(myExample, myExampleWord);

            if(htable.end() == htable.find(myExampleWord))
            {
                std::cout << myExampleWord << std::endl;
            }
        }
        myExample.close();
    }
    else
    {
        std::cout << "Error!" << std::endl;
    }


}

//Read the document, and separate it into a sequence of words converted to lowercase by calling the function getWord.
void getWord(ifstream& fin, string& w)
{
	char c;

	w = "";	// clear the string of characters

	while (fin.get(c) && !isalpha(c));	// do nothing. just ignore c

	// return on end-of-file
	if (fin.eof())
		return;

	// record first letter of the word
	w += tolower(c);

	// collect letters and digits
	while (fin.get(c) && (isalpha(c) || isdigit(c)))
		w += tolower(c);

}