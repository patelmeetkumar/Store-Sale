#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

void addSales(vector<string> &itemName, vector<double> &itemCost);
void viewSales(vector<string> &itemName, vector<double> &itemCost);
void editSale(vector<string> &itemName, vector<double> &itemCost);
void removeSale(vector<string> &itemName, vector<double> &itemCost);

int main() 
{
	vector<string> itemName;
	vector<double> itemCost;

	bool flag = true;
	bool ok = true;
	int number;
	int entry;

	while (flag)
	{
		cout << "Enter 0 to quit the program." << endl;
		cout << "Enter 1 to add a sale." << endl;
		cout << "Enter 2 to view a sale." << endl;
		cout << "Enter 3 to edit a sale" << endl;
		cout << "Enter 4 to remove a sale" << endl;
		cout << "Enter an entry according to instructions above: ";
		cin >> number;

		if (number >= 0 && number < 5) 
		{
			switch (number)
			{
				case 0: cout << endl << endl << endl << "End of Program!";
						flag = false;
					break;

				case 1: ok = true;
						while (ok) 
						{
							cout << endl;
							cout << "Enter 0 to quit adding sale(s)." << endl;
							cout << "Enter 1 to add a sale." << endl;
							cout << "Enter an entry according to instructions above: ";
							cin >> entry;
							cin.ignore();

							if (entry == 0)
							{
								ok = false;
							}
							else if (entry == 1)
							{
								addSales(itemName, itemCost);
							}
							else 
							{
								cout << endl;
								cout << "Invalid entry. Try again!" << endl;
								cout << endl;
							}
						}
						cout << endl;
						
					break;

				case 2: viewSales(itemName, itemCost);
					break;

				case 3: editSale(itemName, itemCost);
					break;

				case 4: removeSale(itemName, itemCost);
					break;
			}
		}
		else 
		{
			cout << "Invalid entry. Try again!" << endl;
		}

		cout << endl;
	}

	return 0;

}

void addSales(vector<string> &itemName, vector<double> &itemCost)
{
	string name;
	double cost;
	
	cout << endl;
	cout << "Enter the name of the item that is sold to add: ";
	getline (cin, name);
	itemName.push_back(name);

	cout << "Enter the price of the item that is sold to add: ";
	cin >> cost;
	itemCost.push_back(cost);

	cout << endl;

}

void viewSales(vector<string> &itemName, vector<double> &itemCost)
{
	cout << endl;

	if (itemName.empty()) 
	{
		cout << "There is zero sale. The list is empty!" << endl;
	}
	else 
	{
		cout << "Name:                    Cost:" << endl << endl;
		for (int i = 0; i < itemName.size(), i < itemCost.size(); i++)
		{
			cout << fixed << setprecision(2);
			cout << left << setw(25) << itemName[i] << left << "$" << itemCost[i] << endl;
		}
	}

	cout << endl;

}

// Note: The item number (index) begins at position one for the user.
void editSale(vector<string> &itemName, vector<double> &itemCost)
{
	int index;
	int price;

	cout << endl;

	if (itemName.empty())
	{
		cout << "There is zero sale. The list is empty!" << endl;
	}
	else 
	{
		cout << "What item number would you like to edit? ";
		cin >> index;
		index--;

		if (index < itemName.size())
		{
			cout << "What is the new price of " << itemName[index] << "? ";
			cin >> price;

			itemCost[index] = price;
		}
		else
		{
			cout << "Invalid entry. Try again!" << endl;
		}

	}

	cout << endl;
}

// Note: The item number (index) begins at position one for the user.
void removeSale(vector<string> &itemName, vector<double> &itemCost)
{
	int index;
	int verify;

	cout << endl;

	if (itemName.empty())
	{
		cout << "There is zero sale. The list is empty!" << endl;
	}
	else
	{
		cout << "What item number would you like to remove? ";
		cin >> index;
		index--;

		if (index < itemName.size())
		{
			cout << "Are you sure you want to delete " << itemName[index] << "?" << endl;
			cout << "Enter 1 for yes." << endl;
			cout << "Enter 2 for no." << endl;
			cout << "Enter an entry according to instructions above: ";
			cin >> verify;

			if (verify == 1)
			{
				itemName.erase(itemName.begin() + index);
				itemCost.erase(itemCost.begin() + index);
				cout << "Item " << index << " was removed successfully." << endl;
			}
			else
			{
				cout << "Item " << itemName[index] << " is not removed." << endl;
			}

		}
		else
		{
			cout << "Invalid entry. Try again!" << endl;
		}

	}

	cout << endl;
}