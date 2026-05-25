#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Product {
	int design_ID;
	string design_name;
	double make_price;
	double sell_price;
	int total_units_sold;
	int total_make_cost;
};


int currentcount = 0;

void addprodDetails(Product arr[], int maxSize, int &count) {
	if (count >= maxSize) {
		cout << "\nNot enough space available to store more records!";
	}

	cout << "\nAdding a product\nEnter Details for Product " << count + 1;
	cout << "\nDesign ID: ";
	cin >> arr[count].design_ID;

	cout << "\nDesign Name: ";
	cin.ignore();
	getline(cin, arr[count].design_name);

	cout << "\nMake Price: $";
	cin >> arr[count].make_price;

	cout << "\nSell Price: $";
	cin >> arr[count].sell_price;

	cout << "\nTotal Units Sold: ";
	cin >> arr[count].total_units_sold;

	arr[count].total_make_cost = arr[count].make_price * arr[count].total_units_sold;
	count++;
}

void calcRevenue(Product arr[], int count) {
	int searchID;
	bool found = false;
	string demand;
	double makeCost, revenue, profitLoss;

	cout << "\nEnter ID to search to calculate cost: ";
	cin >> searchID;

	for (int i = 0; i < count; i++) {
		if (arr[i].design_ID == searchID) {
			found = true;
			makeCost = arr[i].make_price * arr[i].total_units_sold;
			revenue = arr[i].sell_price * arr[i].total_units_sold;
			profitLoss = revenue - makeCost;

			cout << "\n---Analysis Results---";
			cout << "\nTotal Cost: $" << makeCost;
			cout << "\nRevenue Made: $" << revenue;
			cout << "\nProfit/Loss: $" << profitLoss;

			if (profitLoss > 0 && arr[i].total_units_sold >= 20) {
				demand = "\nCategory: High Demand Design.";
			} else {
				demand = "\nCategory: Low Demand Design.";
			}
			cout << demand << endl;
			break;
		}
	}

	if (!found) {
		cout << "\nID not found!";
	}
}

void expensiveDesign(Product arr[], int count) {
	if (count == 0) {
		cout << "\nNo products stored." << endl;
		return;
	}

	int expensiveID = arr[0].design_ID;
	string expensiveName = arr[0].design_name;
	double maxProfit = -9999;

	for (int i = 0; i < count; i++) {
		double makeCost = arr[i].make_price * arr[i].total_units_sold;
		double revenue = arr[i].sell_price * arr[i].total_units_sold;
		double currentProfit = revenue - makeCost;

		if (currentProfit > maxProfit) {
			maxProfit = currentProfit;
			expensiveID = arr[i].design_ID;
			expensiveName = arr[i].design_name;
		}
	}
	cout << "\nThe most profitable product design is: ";
	cout << expensiveID << " | " << expensiveName << " (Profit: $" << maxProfit << ")\n";
}

void saveToFile(Product arr[], int maxSize, int &count) {
	ofstream myFile("productdetails.txt");
	if (myFile.is_open()) {
		myFile << count << endl;
		for (int i = 0; i < count; i++) {
			myFile << arr[i].design_ID << endl;
			myFile << arr[i].design_name << endl;
			myFile << arr[i].make_price << endl;
			myFile << arr[i].sell_price << endl;
			myFile << arr[i].total_units_sold << endl;
			myFile << arr[i].total_make_cost << endl;
		}
		myFile.close();
		cout << "\nData saved successfully!" << endl;
	}
	else {
		cout << "\nFailed to open file!";
	}
}

void LoadFromFile(Product arr[], int &count) {
	ifstream myFile("productdetails.txt");
	if (myFile.is_open()) {
		myFile >> count;
		for (int i = 0; i < count; i++) {
			myFile >> arr[i].design_ID;
			myFile.ignore();
			getline(myFile, arr[i].design_name);
			myFile >> arr[i].make_price;
			myFile >> arr[i].sell_price;
			myFile >> arr[i].total_units_sold;
			myFile >> arr[i].total_make_cost;
			myFile.ignore();
		}
		myFile.close();
		cout << "\nData loaded successfully!" << endl;
	}
	else {
		cout << "\nFailed to load from the file!";
	}
}

int main() {
	const int maxSize = 100;
	Product array[maxSize];
	int choice;

	do {
		cout << "\n=== Welcome to Shaheer's Fashion Designing Store ===";
		cout << "\n1. Add a fashion Product";
		cout << "\n2. Calculate Revenue for a Product (By Search ID)";
		cout << "\n3. Find Most Profitable Design";
		cout << "\n4. Save data into the text file";
		cout << "\n5. Load data from the text file";
		cout << "\n6. Exit";
		cout << "\nEnter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			addprodDetails(array, maxSize, currentcount);
			break;
		case 2:
			calcRevenue(array, currentcount);
			break;
		case 3:
			expensiveDesign(array, currentcount);
			break;
		case 4:
			saveToFile(array, maxSize, currentcount);
			break;
		case 5:
			LoadFromFile(array, currentcount);
			break;
		case 6:
			cout << "\nExiting the program!";
			break;
		default:
			cout << "\nInvalid Input. Please enter correct choice (1-6)";
		}
	} while (choice != 6);
	return 0;
}