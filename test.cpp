// file for testing various components of amazon.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "util.h"
using namespace std;

std::set<std::string> parseStringToWords(string rawWords)
{
    set<string> parsedString;
    string temp;
    char currentChar;

    // Iterate character by character until the null character is encountered
    for (int i = 0; rawWords[i] != '\0'; i++) {
        currentChar = rawWords[i];
        if (currentChar == '\'' || currentChar == ' ') {
            if (temp.size() > 1) {
                parsedString.insert(temp);
            }
            temp.clear();
        }
        else {
            temp.push_back(currentChar);
        }
    }

    if (temp.size() > 1)
    {
        parsedString.insert(temp);
    }

    return parsedString;
}

int main(int argc, char* argv[])
{
	set<string> testParser;
	string test;

	test = "He'llo World How's it Going";
	testParser = parseStringToWords(test);

    std::cout << "Elements of the set: ";
    for (const auto& element : testParser) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
