#ifndef BOOK_H
#define BOOK_H
#include "product.h"

class Book : public Product {
public:
	// constructor
    Book(const std::string category, const std::string name, double price, int qty,
         const std::string author, const std::string ISBN);

	// destructor
    ~Book();

    /**
     * Returns the appropriate keywords that this product should be associated with
     */
    std::set<std::string> keywords() const;

    /**
     * Allows for a more detailed search beyond simple keywords
     */
    //to be implemented in a future assignment
    //bool isMatch(std::vector<std::string>& searchTerms) const;

    /**
     * Returns a string to display the product info for hits of the search
     */
    std::string displayString() const;

    /**
     * Outputs the product info in the database format
     */
    void dump(std::ostream& os) const;

    /*helper function that allows us to have a common case (lowercase) throughout the program*/
    std::string convertToLowercase(std::string word) const;

    // getter functions
    std::string getAuthor() const { return author_; }
    std::string getISBN() const { return ISBN_; }

private:
    std::string author_;
    std::string ISBN_;
};

#endif