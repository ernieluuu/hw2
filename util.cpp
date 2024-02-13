#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"
#include <functional> // for not1 to compile

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
/*For the product name, book author, and clothing brand we define a 
keyword to be any string of 2 or more characters. 
If such a word has punctuation it should be split at each punctuation character 
and the resulting substrings (of 2 or more characters) should be used as keywords
"we'll" --> "we" + "ll"
"men's" --> "men"
*/
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

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
