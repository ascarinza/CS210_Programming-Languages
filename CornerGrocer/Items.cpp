#include <iostream>
#include <fstream>
#include <vector>
#include "Items.h"

using namespace std;

// Default constructor for Items object
Items::Items() {
	name = "none";
	quantity = -1;
}

// Constructor for the Items object. When no quantity is passes it is set to 1 as it is likely going to be the first of its kind.
Items::Items(string name, int quantity = 1) {
	this->name = name;
	this->quantity = quantity;
}

// Gets the item name
string Items::GetName() const {
	return name;
}

// gets the item quantity
int Items::GetQuantity() const {
	return quantity;
}

// Method used to read the input from the selected file and create objects to store in the vector
void Items::ReadInputFile(vector<Items>& itemsList) {
	// set the file name and open the file
	string fileName = "CS210_Project_Three_Input_File.txt";
	ifstream inputFile(fileName);
	string itemName;

	// validates the file open succesfuly
	if (!inputFile.is_open()) {
		cout << "ERROR while opening file: " << fileName << endl;
	}

	// Loop that runs through while there is still input to be taken
	while (getline(inputFile, itemName)) {
		// Creates a new object for each item on the list
		Items newItem(itemName);

		// This fuction either adds the item to the list if it is the first of its kind, or adds +1 to quantity if it already exists
		AddOrUpdateQuantity(itemName, itemsList);

	}
	// Closes the file
	inputFile.close();

}

void Items::WriteToOutputFile(vector<Items> itemsList)  const {
	// Gets the name of the file to open, if the file doesnt exist it will create one
	string fileName = "frequency.dat";
	ofstream outputFile(fileName, ios::out);

	// prints error statement if the file cant be opened.
	if (!outputFile.is_open()) {
		cout << "ERROR while opening file: " << fileName << endl;
		return;
	}

	// Writes the name and the quantity of each item in the stored vector itemsList to the file
	for (int i = 0; i < itemsList.size(); i++) {
		outputFile << itemsList[i].GetName() << ": " << itemsList[i].GetQuantity() << endl;
	}

	// Closes the file
	outputFile.close();

}


// Adds the new item to the vector or updates the quantity
void Items::AddOrUpdateQuantity(string name, vector<Items>& itemsList) {
	// tracks if the item exists
	bool foundItem = false;

	// searches the itemsLists to see if the item read exists in the vector already
	for (int i = 0; i < itemsList.size(); i++) {
		// If the item exists the quantity is updated by one
		if (itemsList[i].GetName() == name) {
			itemsList[i].quantity++;
			// found item is now true as it is found and the loop is broken
			foundItem = true;
			break;
		}
	}

	// If the item cant be found in the list, then it is the first of its kind and it is added to the vector with an initial quantity of 1
	if (!foundItem) {
		Items newItem(name);
		itemsList.push_back(newItem);
	}
}


