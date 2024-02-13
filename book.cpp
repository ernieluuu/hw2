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

	std::string name = convertToLowercase(this->name_);
	std::set<std::string> name_words = parseStringToWords(name);
	// for word in name, push back word -- can call setUnion
	keywords = setUnion(keywords, name_words);

	std::string author = convertToLowercase(this->author_);
	std::set<std::string> author_words = parseStringToWords(author);

	keywords = setUnion(keywords, author_words);

	std::string ISBN = convertToLowercase(this->ISBN_);
	std::set<std::string> ISBN_words = parseStringToWords(ISBN);

	keywords = setUnion(keywords, ISBN_words);

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
	os << "book" << "\n";
	os << this->name_ << "\n";
	//os << std::fixed << std::setprecision(2) << this->price_ << "\n";
	os << this->price_ << "\n";
	os << this->qty_ << "\n";
	os << this->ISBN_ << "\n";
	os << this->author_ << "\n";
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