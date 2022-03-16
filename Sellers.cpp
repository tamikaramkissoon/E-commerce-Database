#include <iostream>
#include <fstream>
#include <cstring>
#include "Seller.h"
#include "BinarySearchTree.h"

using namespace std;

// Write code in readSellers and readSellerProducts which
// will be executed on startup.
// Reads the names of the sellers from 'filename' and stores them 
	// in the 'sellers' array. Returns the amount of sellers read.
int readSellers (Seller sellers[], char filename[100]) {
	string Name = "";
	int numSellers =0;
	ifstream input;
	SortedSet * sellerProducts = initSortedSet ();
	input.open(filename);
	
	for(int i =0; i < 1000; i++){
		sellers[i].name = "";
	
	}	
		// if statement to check whether the input file was successfully opened.
	if (!input.is_open())
	{
		cout << "There was an error opening the data file!  Operation aborting!!..." << endl;
		exit(1);
	}		
	
	input >> Name;
	while (Name != "END" && numSellers < 1000){
		sellers[numSellers].name = Name;

		sellers[numSellers].products = readSellerProducts(sellers[numSellers].name);

		numSellers++;
		input >> Name;
	}
	
	input.close();

	return numSellers;
	
}



// Reads the products that are sold by 'sellerName'. The products
	// are stored in a SortedSet as they are read from the file. The
	// function returns the SortedSet of products.
SortedSet * readSellerProducts ( string sellerName) {
	ifstream input;
	string filename = sellerName + ".txt";
	input.open(filename.c_str());
	SortedSet * insertProduct = initSortedSet ();
	int i =0;
		// if statement to check whether the input file was successfully opened.
	if (!input.is_open())
	{
		cout << "There was an error opening the data file!  Operation aborting!!..." << endl;
		exit(1);
	}		
	
	string product = "";
	input >> product;

	while (product != "END"){
		bool found =containsSS (insertProduct, product);
		if (found == false){
			insertSS (insertProduct, product);
			
		} 
		input >> product;
	}
	
	input.close();
	
	return insertProduct;
	
}


// Write code to search for a seller. This is required for most
// of the menu options.
	 
int searchSellers (Seller sellers[], int numSellers, string key) {
	int found = -1;
	for (int i=0; i < numSellers; i++){
		if (sellers[i].name == key){
			found = i; 	
		}	
	}
	return found;
}

	

// Write code here for Menu Option 8
//The user must specify the name of a product. The names of all the sellers who sell that product should be displayed on the monitor.
	
void listSellers (Seller sellers[], int numSellers, string productName) {
	
	int num =0;
	for (int i=0; i < numSellers; i++){
		bool found = containsSS (sellers[i].products, productName);
		if(found==true){
			num++;
			cout << sellers[i].name << "	";
		}
	}
	cout << endl;
	if(num==0){
		cout << "None of the sellers sells that product\n";
	}
	return;
}


// Write code here for Menu Option 2
//The user must specify the name of a seller and the name of a product to add to the seller’s set of products. 
//If the seller is found, the name of the product is added to that seller’s SortedSet of products. 
//If the seller is not found or the product is already sold by the seller, an appropriate message should be displayed.
void addProduct (Seller sellers[], int numSellers, string sellerName, string productName) {
	bool found = false;
	bool sellerFound= false;
	for (int i =0; i < numSellers; i++){
		if (sellers[i].name == sellerName){
			sellerFound = true;
			found = containsSS (sellers[i].products, productName);
			if (found == false){
				 insertSS (sellers[i].products, productName);
			}
		}
	}
	if (found == true)
		cout << "Product is already sold by the seller" << endl;
	if (sellerFound == false)
		cout << "Seller is not found" << endl;
	return;
}

	

// Write code here for Menu Option 3
//The user must specify the name of a seller and the name of a product to be deleted from the seller’s set of products. 
//If the seller is found, the name of the product is deleted from that seller’s SortedSet of products. 
//If the seller is not found or the product is not found in the seller’s SortedSet of products, an appropriate message should be displayed.
void deleteProduct (Seller sellers[], int numSellers, string sellerName, string productName) {
	bool found = false;
	bool sellerFound= false;
	for (int i =0; i < numSellers; i++){
		if (sellers[i].name == sellerName){
			sellerFound = true;
			found = containsSS (sellers[i].products, productName);
			if (found == true){
				deleteSS (sellers[i].products, productName);
			}
		}
	}
	if (found == false)
		cout << "Product is not sold by the seller" << endl;
	if (sellerFound == false)
		cout << "Seller is not found" << endl;
	return;
}
