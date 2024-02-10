#include "movie.h"
#include <cctype>

// constructor
Movie::Movie(const std::string category, const std::string name, double price, int qty,
	const std::string genre, const std::string rating) : Product(category, name, price, qty),
	genre_(genre), rating_(rating)
{
}

// destructor
Movie::~Movie()
{
}

std::set<std::string> Movie::keywords() const
{
	std::set<std::string> keywords;
	keywords.insert(convertToLowercase(this->genre_));
	keywords.insert(convertToLowercase(this->rating_));
	keywords.insert(convertToLowercase(this->name_));
	return keywords;
}

std::string Movie::displayString() const
{
	//std::string movieString;
	//return movieString = this->name_ + "\n" + "Genre: " +
	//	this->genre_ + " rating : " + this->rating_
	//	+ "\n" + std::to_string(this->price_) + " " +
	//	std::to_string(this->qty_) + " left.";

	std::ostringstream oss;
	oss << this->name_ << "\n"
		<< "Genre: " << this->genre_ << " Rating: " << this->rating_ << "\n"
		<< std::fixed << std::setprecision(2) << this->price_ << " " << this->qty_ << " left." << std::endl;

	return oss.str();
}

void Movie::dump(std::ostream& os) const
{
	/*outputs:
	product_category
	name
	price
	quantity
	category-specific-info*/
	//os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << std::endl;
	os << "movie" << std::endl;
	os << this->name_ << std::endl;
	os << this->price_ << std::endl;
	os << this->qty_ << std::endl;
	os << this->genre_ << std::endl;
	os << this->rating_ << std::endl;
}

/* choosing pass by copy + return instead of pass by reference so
   that we can preserve the case of the original author + title, etc.
*/
std::string Movie::convertToLowercase(std::string word) const
{
	std::string lowercaseWord = word;
	for (int i = 0; word[i] != '\0'; i++)
	{
		lowercaseWord[i] = tolower(word[i]);
	}

	return lowercaseWord;
}