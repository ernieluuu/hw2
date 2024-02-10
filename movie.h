#ifndef MOVIE_H
#define MOVIE_H
#include "product.h"

class Movie : public Product {
public:
    // constructor
    Movie(const std::string category, const std::string name, double price, int qty,
        const std::string genre, const std::string rating);

    // destructor
    ~Movie();

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
    std::string getGenre() const { return genre_; }
    std::string getRating() const { return rating_; }

private:
    std::string genre_;
    std::string rating_;
};

#endif