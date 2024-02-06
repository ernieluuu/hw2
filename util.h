#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
	// find() tests membership in log(n) time!

	set<T> intersection;
	
	for (set<T>::iterator it = s1.begin(); it != s1.end(); ++it)
	{
		T curr_item = *it;
		if (s2.find(curr_item) == s2.end())
		{
			continue;
		}
		else
		{
			intersection.insert(*it);
			// cout << *it << " ";
		}
	}

	return intersection;
}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
	// pushing back all of s1 + s2 should work cuz the set<> handles duplicates
	set<T> setUnion;

	for (set<T>::iterator it = s1.begin(); it != s1.end(); ++it)
	{
		setUnion.insert(*it);
	}

	for (set<T>::iterator it = s2.begin(); it != s2.end(); ++it)
	{
		setUnion.insert(*it);
	}

	return setUnion;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
