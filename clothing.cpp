#include "clothing.h"
#include <cctype>

// constructor
Clothing::Clothing(const std::string category, const std::string name, double price, int qty,
	const std::string size, const std::string brand) : Product(category, name, price, qty),
	size_(size), brand_(brand)
{
}

// destructor
Clothing::~Clothing()
{
}

std::set<std::string> Clothing::keywords() const
{
	std::set<std::string> keywords;
	keywords.insert(convertToLowercase(this->size_));
	keywords.insert(convertToLowercase(this->brand_));
	keywords.insert(convertToLowercase(this->name_));
	return keywords;
}

std::string Clothing::displayString() const
{
	//std::string clothingString;
	//return clothingString = this->name_ + "\n" + "Size: " +
	//	this->size_ + " Brand: " + this->brand_
	//	+ "\n" + std::to_string(this->price_) + " " +
	//	std::to_string(this->qty_) + " left.";

	std::ostringstream oss;
	oss << this->name_ << "\n"
		<< "Size: " << this->size_ << " Brand: " << this->brand_ << "\n"
		<< std::fixed << std::setprecision(2) << this->price_ << " " << this->qty_ << " left." << std::endl;

	return oss.str();
}

void Clothing::dump(std::ostream& os) const
{
	/*outputs:
	product_category
	name
	price
	quantity
	category-specific-info*/
	//os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << std::endl;
	os << "clothing" << std::endl;
	os << this->name_ << std::endl;
	os << this->price_ << std::endl;
	os << this->qty_ << std::endl;
	os << this->size_ << std::endl;
	os << this->brand_ << std::endl;
}

/* choosing pass by copy + return instead of pass by reference so
   that we can preserve the case of the original author + title, etc.
*/
std::string Clothing::convertToLowercase(std::string word) const
{
	std::string lowercaseWord = word;
	for (int i = 0; word[i] != '\0'; i++)
	{
		lowercaseWord[i] = tolower(word[i]);
	}

	return lowercaseWord;
}