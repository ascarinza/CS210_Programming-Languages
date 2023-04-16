#ifndef ITEMS_H
#define ITEMS_H

#include <string>
#include <fstream>
#include <vector>

using namespace std;


class Items {
// public methods used to create, store, and update the items read and written to file
public:
	Items();
	Items(string name, int quantity);
	string GetName() const;
	int GetQuantity() const;
	void AddOrUpdateQuantity(string name, vector<Items>& itemsList);
	void ReadInputFile(vector<Items>& itemList);
	void WriteToOutputFile(vector<Items> itemsList) const;

private:
	// Private member variables
	string name;
	int quantity;

};

#endif // ITEMS_H

