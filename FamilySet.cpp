
#include "FamilySet.h"
#include <iostream>
#include <fstream>
using namespace std;

FamilySet::FamilySet()
{
	// Your code here
}

FamilySet::FamilySet(string file)
{
    /*
	ifstream myFile(file);
	if(!myFile)
    {
        cout << "Could not find file!\n";
        exit(0);
    }
    else
    {
        string word;
        while(!myFile.eof())
        {
            myFile >> word;
            masterList.push_back(word);
        }
    }
    cout << masterList.size() << " words were found.\n";
    myFile.close();
    */

	// Your code here

	//myFile.close();
}

FamilySet::FamilySet(string file, int len)
{
	ifstream myFile(file);

	//myFile.open();
	if(!myFile)
    {
        cout << "Error reading the file!\n";
        exit(0);
    }
    else
    {

        while(!myFile.eof())
        {
            string word;
            myFile >> word;
            if(word.size() == len)
                masterList.push_back(word);
        }
    }
    cout << masterList.size() << " words found.\n";
    myFile.close();
}

FamilySet::~FamilySet()
{
	// Optional for this assignment
}

void FamilySet::filterFamilies(string letter, string guessPattern)
{
	// The first step is to clear dictionaries to prepare
	// for the new filter based on the letter and pattern

	// For each word in the master list, you need to classify
	// what family is part of based on the letter and pattern.
	// If you can find letter in the word, then we need to
	// create the new family.
	// Otherwise, if the letter does not exist in the word, then
	// the family is simply the guessPattern.
	// Example 1:Suppose letter is "a", word is "ally", and
	//           guessPattern is ***y.
	//           In this case, the family is a**y. Once this
	//           is determined, then "ally" can be added to
	//           the "a**y" dictionary.
	// Example 2:Suppose letter is "a", word is "cool", and
	//           guessPattern is ***y.
	//           In this case, the family is ***y and "cool"
	//           would be added to the ***y dictionary.



    dictionaries.clear();
    string word;
    for(auto it = masterList.begin(); it!= masterList.end(); it++)
    {
        string pattern = guessPattern; // 
        word = *it;
        for(int i = 0; i < word.size(); i++)
        {
            if(letter[0] == word[i])
            {
                pattern[i] = letter[0];
            }
           

            if(dictionaries.find(pattern) == dictionaries.end())
            {
                dictionaries.insert(pair<string,vector<string> >(pattern, vector<string>()));
            }
        }
        dictionaries[pattern].push_back(word);
      


    }


    for(auto it:dictionaries)
    {
        cout << it.first << " " << it.second.size() << endl;
    }

}

void FamilySet::setFamily(string &family)
{
	// Function finds largest family and updates the family 

	// Your code here

    masterList.clear();
    
	int number = 0;
	string largestFam;

	for (auto it : dictionaries)
    {
		// inside if is the number of words in the largest family (currently) 
		//and the associated name 
        if(it.second.size() > number)  
        {
            number = it.second.size();
            largestFam = it.first;
        }
    }

	// copying that family into empty master list 
    for(int i=0; i<dictionaries[largestFam].size(); i++)
    {
        masterList.push_back(dictionaries[largestFam].at(i));
      
    }

    family = largestFam;
    dictionaries.clear();
}

/*
vector<string> FamilySet::getFamily(string family)
{
	// Returns the dictionary associated with family.

	// Your code here
	
}
*/

string FamilySet::getRandomWord()
{
	// Returns random word from master list
	int randInt = rand() % masterList.size();
	string word = masterList[randInt];
	return word;

	//return string();
}

int FamilySet::numWords()
{
	// This should return the number of words in the master list
	return masterList.size();
}

int FamilySet::numFamilies()
{
	// This should return how many families are in dictionaries
	// (Note FAMILIES, not words)
	return 0;
}

void FamilySet::resetFamilyIter()
{
	// The iterator should return each family from
	// dictionaries (Note, it should returns the family,
	// not the words).
	// The resetFamilyIter function should be starting
	// iterator for dictionaries.
	// Your code here
}

bool FamilySet::hasNext() {
	// Returns true as long as there is another family to return
	return true;
}

string FamilySet::getNextFamily()
{
	// Returns the next family using the unordered_map iterator.

	// Your code here

	return "";
}

int FamilySet::familySize(string family)
{
	// Returns the size of the dictionary of family.

	return 0;
}
