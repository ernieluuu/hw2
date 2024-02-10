#include "myDataStore.h"

// constructor

// destructor

/*consider also having a Product* vector for fn's like dump()*/
void MyDataStore::addProduct(Product* p)
{
	std::set<std::string> key_words = p->keywords();
	Products_.insert(make_pair(key_words, p));
}

void MyDataStore::addUser(User* u)
{
	userSet_.insert(u);
	// push onto the map
}

/**
 * Performs a search of products whose keywords match the given "terms"
 *  type 0 = AND search (intersection of results for each term) while
 *  type 1 = OR search (union of results for each term)
 */
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
	std::vector<Product*> searchResults;

	if (type == 0)
	{
		searchResults = /*todo*/;

		// for string in vector...
		// for string in vector, for product in vector
		// string, product->keywords
		// boolean to track if it is always true.

		// 0 1 is the difference between using setIntersect w/ the whole word
		// // + Products_ or using broken parts of the world + Products_.
		// setIntersection gets a set of words that and match
		// convert std::set to vector
		// --> has to index products, not just the terms in the set.
		// returns a set<T>
		// convert it to a vector<Product*>?
	}
}

void MyDataStore::dump(std::ostream& ofile)
{
	/*for item in items, ->dump() seems like the call, unless they want a different format.*/

	// iterate through all the Products
	// ofile << item->dump()

}

void MyDataStore::addToCart(std::string username, int hit_index, std::vector<Product*> hits)
{
/*Then,
just add to the Product* queue associated with the username
use the username as a key to find the product* queue (in Products_)
then go to that (-->second?) and push_back.*/

	Product* hit = hits[hit_index];
	std::map<std::string, std::queue<Product*>>::iterator it = this->usersCart_.find(username);
	
	if (it == usersCart_.end()) {
		std::cout << "Invalid username" << std::endl;
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

	int idx = 1;

	while (!items.empty())
	{
		(items.front())->displayString();
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
		}
	}
}
