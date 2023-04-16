#include <iostream>
#include <string>
#include <vector>
#include "Items.h"

using namespace std;

// Prints all the menu choices
void PrintMenu() {
	cout << "Enter your selection 1-4" << endl;
	cout << "1: Search for an items frequency" << endl;
	cout << "2: Print item list with frequencies" << endl;
	cout << "3: Print item histrogram for frequencies" << endl;
	cout << "4: EXIT" << endl;
}

// Completes the menu option one process
void MenuOptionOne(vector<Items>& itemsList) {
	// create a bool that will turn true if the item is found in the system
	bool itemFound = false;
	string userItem;

	// Get the item the user is searching for
	cout << "Enter item: ";
	cin >> userItem;

	// All items are lowercase so this will uppercase the item if the user enters lowercase as there are no lowercase items
	userItem[0] = toupper(userItem[0]);

	// For loop that runs though all the items using the GetName() method until the item is found
	for (int i = 0; i < itemsList.size(); i++) {
		// if the item is found in the list
		if (itemsList[i].GetName() == userItem) {
			// Prints out the item name along with the frequency or quantity of the item
			cout << userItem << ": " << itemsList[i].GetQuantity() << endl;
			// Updated the foundItem bool to true becuase the item was found and breaks out of the loop
			itemFound = true;
			break;
		}
	}

	// If the item is not found the the bool remains false then a print statement shows the user the item they are looking for doesnt exist
	if (!itemFound) {
		cout << "Item not found." << endl;
	}

	cout << endl;

}

// Completes the menu option two process
void MenuOptionTwo(vector<Items>& itemsList) {
	cout << endl;
	
	// For loop to print each name and quantity for all the items in the itemsList vector
	for (int i = 0; i < itemsList.size(); i++) {
		cout << itemsList[i].GetName() << ": " << itemsList[i].GetQuantity() << endl;
	}

	cout << endl;
}

// Completes the menu option three process
void MenuOptionThree(vector<Items>& itemsList) {
	// temp varible to store number of * needed
	int bars;
	cout << endl;

	// For loop that runs though each item on the list
	for (int i = 0; i < itemsList.size(); i++) {
		// Prints the item name 
		cout << itemsList[i].GetName() << " ";
		// Sets bars to the quanity of the item
		bars = itemsList[i].GetQuantity();
		// Inner for loop that loop until the number of * printed matched the quantity of that item
		for (int j = 0; j < bars; j++) {
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;
}

// Collects the menu choice from the user and validates it is a valid option
int GetMenuChoice() {
	// varibles
	int userChoice;
	bool valid = false;

	// Do loop makes the input cycle run at least once
	do {
		cout << "Enter selection: " << endl;
		// Try will throw exceptions for invalid inputs
		try {
			cin >> userChoice;
			// If the input in a non int
			if (cin.fail()) {
				throw "Invalid option! Non integer";
			}
			// If the input is not a valid menu option
			else if ((userChoice != 1) && (userChoice != 2) && (userChoice != 3) && (userChoice != 4)) {
				throw "Invalid option! Not an option";
			}
			// when a valid menu option is selected bool = true and do while exists
			else {
				valid = true;
			}
		}
		// catches throws 
		catch (const char* error) {
			// prints the erro messages attached to each throw
			cout << error << endl;
			//clears the input
			cin.clear();

			// Wouldn't work correctly until I googled the issue and found this line as a result
			//I had the ignore but needed the inside () to clear the whole buffer
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

	// exits once a valid selection is made
	} while (!valid); {}

	// returns the valid choice
	return userChoice;
}

// method used to call the desired menu fuction for the selection made
void MenuSelection(int choice, vector<Items>& itemsList) {
	// switch that calls each menu choice based on the users selection
	switch (choice) {

	case 1:
		MenuOptionOne(itemsList);
		break;

	case 2:
		MenuOptionTwo(itemsList);
		break;

	case 3:
		MenuOptionThree(itemsList);
		break;

	// Input is validated somewhere else so this should never print but here just in case something were to sneak by I know where the error is
	defualt:
		cout << "ERROR INVALID SELECTION IN CASE" << endl;
		break;

	}
}

// Main
int main() {
	// varibles
	int choice = 0;
	vector<Items> itemsList;
	Items item;

	// read file and create list
	item.ReadInputFile(itemsList);


	//write file and store backup
	item.WriteToOutputFile(itemsList);


	// while the runs until the user choses to exit using menu # 4
	while (choice != 4) {
		// prints the meny and gets the users choice
		PrintMenu();
		choice = GetMenuChoice();

		// If the users selection is 4 its breaks and then exists
		if (choice == 4) {
			break;
		}

		// passes users choice and the itemsList to the method that calls the correct fucntion for the selection
		MenuSelection(choice, itemsList);
	}

	return 0;
}




