#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include "datastore.h"
#include "util.h"
#include <map>
#include <set>
#include <queue>

/*Implement a derived DataStore class called MyDataStore in mydatastore.h and 
mydatastore.cpp. It is here that you will implement the core functionality of 
your program: searching, adding products and users, saving the database, etc. 
(For search you can use the setIntersection and setUnion) functions in util.h. 
This class is likely where you should store products and users in some fashion. 
Again we recommend compiling this file separately as well after you write the core
functionality. You may need to add to it or modify it later as you work through other
design aspects but make sure it can compile now even just using empty “dummy” function
implementations. This derived class may define non-virtual functions to do other 
specific commands that the menu supports. It might be a good idea to have one member 
function in this class that corresponds to and performs each command from the 
menu options. You should not modify datastore.h.*/

class MyDataStore : public DataStore {

    // constructor FIXME: INITIALIZE it
    MyDataStore() { }

    ~MyDataStore() { }

    /**
     * Adds a product to the data store
     */
    void addProduct(Product* p);

    /**
     * Adds a user to the data store
     */
    void addUser(User* u);

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    /**
     * Reproduce the database file from the current Products and User values
     */
    void dump(std::ostream& ofile);

    /*my added functions:*/

    void addToCart(std::string username, int hit_index, std::vector<Product*> hits);

    /*print usernames cart (case insensitive) with ascending index #*/
    void viewCart(std::string username);

    void buyCart(std::string username);

private:
/*make getter functions to get these if needed*/

/*the set of users*/
std::set<User*> userSet_;
/*maps username onto the user*/
std::map<std::string, User*> Users_;
/*pure product set*/
std::set<Product*> productSet_;
/*product map accessible by keywords*/
std::map<std::set<std::string>, Product*> Products_;
/*where string is the username and there is a queue of Products.*/
std::map<std::string, std::queue<Product*>> usersCart_;

};


#endif