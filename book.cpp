#include "book.h"
#include <cctype>

// constructor
Book::Book(const std::string category, const std::string name, double price, int qty,
	const std::string author, const std::string ISBN) : Product(category, name, price, qty),
	author_(author), ISBN_(ISBN)
{
}

// destructor
Book::~Book()
{
}

std::set<std::string> Book::keywords() const
{
	std::set<std::string> keywords;
	keywords.insert(convertToLowercase(this->author_));
	keywords.insert(convertToLowercase(this->ISBN_));
	keywords.insert(convertToLowercase(this->name_));
	return keywords;
}

std::string Book::displayString() const
{
	/*
	displays:

	<name>
	Author: <author> ISBN : <isbn>
	<price> <quantity> left.

	*/

	//std::string bookString;
	//return bookString = this->name_ + "\n" +  "Author: " +
	//					this->author_ + " ISBN: " + this ->ISBN_
	//					+ "\n" + std::to_string(this->price_) + " " + 
	//					std::to_string(this->qty_) + " left.";

	std::ostringstream oss;
	oss << this->name_ << "\n"
		<< "Author: " << this->author_ << " ISBN: " << this->ISBN_ << "\n"
		<< std::fixed << std::setprecision(2) << this->price_ << " " << this->qty_ << " left." << std::endl;
	
	return oss.str();
}

void Book::dump(std::ostream& os) const
{
	/*outputs:
	product_category
	name
	price
	quantity
	category-specific-info*/
	//os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << std::endl;
	os << "book" << std::endl;
	os << this->name_ << std::endl;
	os << this->price_ << std::endl;
	os << this->qty_ << std::endl;
	os << this->author_ << std::endl;
	os << this->ISBN_ << std::endl;
}

/* choosing pass by copy + return instead of pass by reference so
   that we can preserve the case of the original author + title, etc.
*/
std::string Book::convertToLowercase(std::string word) const
{
	std::string lowercaseWord = word;
	for (int i = 0; word[i] != '\0'; i++)
	{
		lowercaseWord[i] = tolower(word[i]);
	}

	return lowercaseWord;
}