#include "mydatastore.h"

// constructor
MyDataStore::MyDataStore() :
	userSet_(std::set<User*>()),
	Users_(std::map<std::string, User*>()),
	productSet_(std::set<Product*>()),
	Products_(std::map<std::set<std::string>, Product*>()),
	usersCart_(std::map<std::string, std::queue<Product*>>())
{

}

// destructor
MyDataStore::~MyDataStore() {
	for (User* u : userSet_) {
		delete u;
	}
	for (Product* p : productSet_) {
		delete p;
	}
}	

void MyDataStore::addProduct(Product* p)
{
	std::set<std::string> key_words = p->keywords();
	Products_.insert(make_pair(key_words, p));
	productSet_.insert(p);
	/*for debugging:*/
	prodVec_.push_back(p);
}

void MyDataStore::addUser(User* u)
{
	userSet_.insert(u);
	// TODO: push onto the map!!
	/*std::map<std::string, User*> Users_;*/
	Users_.insert(make_pair(u->getName(), u));
	// initialize usersCart_!!!
	std::queue<Product*> newQueue;
	usersCart_.insert(make_pair(u->getName(), newQueue));
}

/**
 * Performs a search of products whose keywords match the given "terms"
 *  type 0 = AND search (intersection of results for each term) while
 *  type 1 = OR search (union of results for each term)
 */
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
	/*
	declaration:
	std::map<std::set<std::string>, Product*> Products_;
	*/
	std::set<Product*> results;
	std::map<std::set<std::string>, Product*>::iterator it; // iterates through products
	std::vector<std::string>::iterator terms_it; // terms iterator

	if (type == 0)
	{
		/*search results, initialized to the set of all products*/
		//std::set<Product*> results = productSet_;
		results = productSet_;
		/*for every term
			can find it in curr_product?
				if yes, then push the product (it->second) into my vector
					then (if it is not the first term) do a set intersection with my results.*/

		for (terms_it = terms.begin(); terms_it != terms.end(); ++terms_it) {
			std::set<Product*> currMatches; // push back current matches here
			// iterate through the products, and call find to see if can find term in keywords
			for (it = Products_.begin(); it != Products_.end(); ++it)
			{
				std::set<std::string> kw = it->first; // key words
				//if you can find it in the keywords, push back the product
				if (kw.find(*terms_it) != kw.end())
				{
					currMatches.insert(it->second);
				}
			}
			// update results vector
			results = setIntersection(results, currMatches);
		}
	}

	else if (type == 1)
	{
		for (terms_it = terms.begin(); terms_it != terms.end(); ++terms_it) {
			std::set<Product*> currMatches; // push back current matches here
			// iterate through the products, and call find to see if can find term in keywords
			for (it = Products_.begin(); it != Products_.end(); ++it)
			{
				std::set<std::string> kw = it->first; // key words
				//if you can find it in the keywords, push back the product
				if (kw.find(*terms_it) != kw.end())
				{
					currMatches.insert(it->second);
				}
			}
			// update results vector
			results = setUnion(results, currMatches);
		}
	}

	/* convert results from a set to a vector*/

	std::set<Product*>::iterator res_it;
	std::vector<Product*> searchResults;

	for (res_it = results.begin(); res_it != results.end(); ++res_it)
	{
		searchResults.push_back(*res_it);
	}

	return searchResults;
}

void MyDataStore::dump(std::ostream& ofile)
{
	std::set<Product*>::iterator it;
	std::set<User*>::iterator it2;

	ofile << "<products>" << "\n";

	// just call dump from objects -- note, dump is different from displaystring.

	for (it = productSet_.begin(); it != productSet_.end(); ++it)
	{
		(*it)->dump(ofile);
	}

	ofile << "</products>" << "\n";

	ofile << "<users>" << "\n";

	for (it2 = userSet_.begin(); it2 != userSet_.end(); ++it2)
	{
		ofile << (*it2)->getName() << " " << std::fixed << std::setprecision(2)
			<< (*it2)->getBalance() << " " << (*it2)->getType() << "\n";
	}

	ofile << "</users>";

	ofile << "\n";

	return;

}

void MyDataStore::addToCart(std::string username, int hit_index, std::vector<Product*> hits)
{
/*Then,
just add to the Product* queue associated with the username
use the username as a key to find the product* queue (in Products_)
then go to that (-->second?) and push_back.*/

	Product* hit = hits[hit_index-1];
	std::map<std::string, std::queue<Product*>>::iterator it = this->usersCart_.find(username);
	
	if (it == usersCart_.end()) {
		std::cout << "Invalid request\n"; // FIXME: 'username' change to 'request'
		return;
	}

	(it->second).push(hit);
	
	return;
}

void MyDataStore::viewCart(std::string username)
{
	/*You should support the VIEWCART username command which should print the 
	products in username's cart (case insensitive) at the current time. 
	The items should be printed with some ascending index number so it is easy 
	to tell how many items are in the cart. If the username provided is invalid, 
	print Invalid username to the screen and do not process the command.*/
	
	std::map<std::string, std::queue<Product*>>::iterator it = this->usersCart_.find(username);

	/*FIXME: may have to call case insensitive in dislayString()*/

	if (it == usersCart_.end()) {
		std::cout << "Invalid username" << std::endl;
		return;
	}

	std::queue<Product*> items = it->second;

	/* if the above queue is a copy, then the following implementation is okay
	   make sure not to delete the stuff in the queue*/

	int item_count = 1;
	while (!items.empty())
	{
		std::cout << "Item " << item_count++ << "\n";
		std::string cart = (items.front())->displayString();
		std::cout << cart << std::endl;
		items.pop();
	}

	return;
}

void MyDataStore::buyCart(std::string username)
{
	/*You should support the BUYCART username command which should cause 
	the program to iterate through the items in username's cart (case insensitive). 
	If the item is in stock AND the user has enough money it should be removed from 
	the cart, the in stock quantity reduced by 1, and the product price should be debited
	from the user’s available credit. If an item is not in stock or the user does not 
	have enough credit, simply leave it in the cart and go on to the next product. 
	Note: Your cart implementation must iterate through the products in the order 
	they were added. If the username provided is invalid, 
	print Invalid username to the screen and do not process the command.*/

	/*FIXME: do we have to store the user's purchased items? or is it we just subtract the funds, etc.*/

	/*this portion finds the cart of 'username'*/
	std::map<std::string, std::queue<Product*>>::iterator it = this->usersCart_.find(username);

	if (it == usersCart_.end()) {
		std::cout << "Invalid username" << std::endl;
		return;
	}

	/*finds user with the username*/
	std::map<std::string, User*>::iterator it2 = this->Users_.find(username);
	User* currUser = it2->second;
	/* makes a shallow copy of the cart so that we can iterate through it
	   changes nothing so long as we don't dereference the Product* */
	std::queue<Product*> items = it->second;

	while (!items.empty())
	{
		/*if out of stock or insufficient funds, then continue the loop on the next item*/
		if ((items.front())->getQty() == 0 
			|| currUser->getBalance() < (items.front())->getPrice())
		{
			items.pop();
			continue;
		}
		else
		{
			currUser->deductAmount(items.front()->getPrice());
			items.front()->subtractQty(1);
			items.pop();
			(it->second).pop(); // removes from user's cart
		}
	}
}
