#ifndef CLOTHING_H
#define CLOTHING_H
#include "product.h"

class Clothing : public Product {
public:
    // constructor
    Clothing(const std::string category, const std::string name, double price, int qty,
        const std::string size, const std::string brand);

    // destructor
    ~Clothing();

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

private:
    std::string size_;
    std::string brand_;
};

#endif