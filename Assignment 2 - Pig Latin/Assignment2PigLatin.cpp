// Assignment2PigLatin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>


using namespace std;

int translateToPigLatin(char str[50]);

int main()
{
	bool again = 1;
	char input[50];

	do
	{
		//get input
		cout << "\nEnter a word to convert into Pig Latin (enter 0 to quit): ";
		gets_s(input);

		if(input[0]=='0')
		{
			again = 0;
			break;
		}
		else
		{
			//pass input into function
			translateToPigLatin(input);	
			continue;
		}
		
	} while (again == 1);
	
    return 0;
}

int translateToPigLatin(char str[50])
{
	char *pstr = str;	//create pointer for array
	int i = 0;			//set default return value (0 success, -1 not successful)
	int j = 0;
	char strArray[8][4] = {"the","a","an","and","but","for","nor","yet"};
	int row;
	string vowels = "aeiou";

	//word is too long
	if (strlen(str) > 47)
	{
		cout << "\n\t\t\tERROR: word must be less than 48 characters";
		i = -1;
		return i;
	}

	//word starts with a number
	if (isdigit(str[0])) 
	{
		cout << "\n\t\t\tERROR: The first letter cannot be a number. Try again." << endl;
		i = -1;
		return i;
	}

	//word is only two characters
	if (strlen(str) == 2)
	{
		cout << "\n\t\t\tWord has two characters." << endl;
		cout << "\n\t\t\tPig Latin Conversion: \t\t" << str << endl;
		return i;
	}

	//word is an article or conjunction
	for (row = 0; row <= 8; row++)
	{
		if (strcmp(str, strArray[row])==0)
		{
			cout << "\n\t\t\tWord is an article or conjunction." << endl;
			cout << "\n\t\t\tPig Latin Conversion: \t\t" << str << endl;
			return i;
		}
	}

	//word starts with a vowel
	for (j = 0; j < vowels.length(); j++)
	{
		if (tolower(str[0]) == vowels[j])
		{
			strcat(str, "ay");
			cout << "\n\t\t\tWord starts with a vowel." << endl;
			cout << "\n\t\t\tPig Latin Conversion: \t\t" << str << endl;
			return i;
		}
	}

	//word starts with a consonant
	pstr++;
	cout << "\n\t\t\tWord starts with a consonant." << endl;
	cout << "\n\t\t\tPig Latin Conversion: \t\t" << pstr << str[0] << "ay" << endl;
	return i;
}