#include <iostream>
#include <fstream>
#include <cstring>
#include "SortedSet.h"
#include "Seller.h"
	using namespace std;


// insert your additional function prototypes here (if needed) 

// write the code for your additional functions here (if needed)

void menu (){
	cout <<"\n\n\n";
	cout << "\t1. Display all the products sold by a seller (in sorted order)\n";
	cout << "\t2. Add a new product to the set of products sold by a seller\n";
	cout << "\t3. Delete a product from the set of products sold by a seller\n";
	cout << "\t4. Which product sold by a seller comes after (in order)?\n";
	cout << "\t5. Which product sold by a seller comes before (in order)?\n";
	cout << "\t6. Display all the products sold by two sellers\n";
	cout << "\t7. Display the common products sold by two sellers\n";
	cout << "\t8. Find all the sellers who sell a certain product\n";
	cout << "\t9. Quit\n";
	cout << "\n\nPlease enter your menu option ";
}
//exit
void option9 (){
	system("cls");
	cout << "MENU QUIT\n";
	cout << "\n\n\n\t\tEND OF COMP2611 ASSIGNMENT 2";
}
//The user must specify the name of the seller. If the seller is found, an ordered list of the products sold by that seller must be displayed on the monitor. 
//If the seller is not found, an appropriate message should be displayed. Linear search or binary search can be used to find the seller.
void option1 (Seller sellers[], int numSellers){
	string sellerName ="";
	cout << "\nPlease enter the name of the seller ";
	cin >> sellerName;
	int sellerLoc = searchSellers (sellers, numSellers, sellerName);
	if (sellerLoc == -1){
		cout << "Seller not found\n";
	}else{
		displayElements (sellers[sellerLoc].products);
	}
	cout << endl;
	system("pause");
	system("cls");
}
//The user must specify the name of a seller and the name of a product to add to the seller’s set of products. 
//If the seller is found, the name of the product is added to that seller’s SortedSet of products. 
//If the seller is not found or the product is already sold by the seller, an appropriate message should be displayed.
void option2 (Seller sellers[], int numSellers){
	string sellerName ="";
	string productName = "";
	cout << "\nPlease enter the name of the seller ";
	cin >> sellerName;
	cout << "\nPlease enter the product name ";
	cin >> productName;
	addProduct (sellers, numSellers, sellerName, productName);
	system("pause");
	system("cls");
}
//The user must specify the name of a seller and the name of a product to be deleted from the seller’s set of products. 
//If the seller is found, the name of the product is deleted from that seller’s SortedSet of products. 
//If the seller is not found or the product is not found in the seller’s SortedSet of products, an appropriate message should be displayed.
void option3 (Seller sellers[], int numSellers){
	string sellerName ="";
	string productName = "";
	cout << "\nPlease enter the name of the seller ";
	cin >> sellerName;
	cout << "\nPlease enter the product name ";
	cin >> productName;
	deleteProduct (sellers, numSellers, sellerName, productName);
	system("pause");
	system("cls");
}
//The user must specify the name of a seller and the name of a product, p. 
//If the seller is found, the seller’s SortedSet of products is searched for p. 
//Regardless of whether p is sold by the seller, the product that comes after p in the set of products sold by the seller (in sorted order) is displayed. 
//If the seller is not found or no such product exists, an appropriate message should be displayed.
void option4 (Seller sellers[], int numSellers){
	string sellerName ="";
	string p = "";
	cout << "\nPlease enter the name of the seller ";
	cin >> sellerName;
	cout << "\nPlease enter the product name ";
	cin >> p;
	int sellerLoc =	searchSellers (sellers, numSellers, sellerName);
	if (sellerLoc == -1){
		cout << "Seller not found\n";
	}else{
		bool empty = isEmptySS (sellers[sellerLoc].products);
		if (empty == true){
			cout << "No products found" <<endl;
		}else{
			string next = nextKey (sellers[sellerLoc].products, p);
			if(next==""){
				cout << "There is no successor in the data set for " << p << endl;
			}
			else{
				cout << "The Successor is " << next << endl;	
			}
		}
	}
	system("pause");
	system("cls");
}
//The user must specify the name of a seller and the name of a product, p. If the seller is found, the seller’s SortedSet of products is searched for p. 
//Regardless of whether p is sold by the seller, the product that comes before p in the set of products sold by the seller (in sorted order) is displayed. 
//If the seller is not found or no such product exists, an appropriate message should be displayed.
void option5 (Seller sellers[], int numSellers){
	string sellerName ="";
	string p = "";
	cout << "\nPlease enter the name of the seller ";
	cin >> sellerName;
	cout << "\nPlease enter the product name ";
	cin >> p;
	int sellerLoc =	searchSellers (sellers, numSellers, sellerName);
	if (sellerLoc == -1){
		cout << "Seller not found\n";
	}else{
		bool empty = isEmptySS (sellers[sellerLoc].products);
		if (empty == true){
			cout << "No products found" <<endl;
		}else{
			string prev = previousKey (sellers[sellerLoc].products, p);
			if(prev==""){
				cout << "There is no predecessor in the data set for " << p << endl;
			}
			else{
				cout << "The Predecessor is " << prev << endl;	
			}
		}
	}
	system("pause");
	system("cls");
}
//The user must specify the names of two sellers. An ordered list of the products sold by both sellers
//combined should be displayed on the monitor. There should be no duplicates present
void option6 (Seller sellers[], int numSellers){
	string seller1 ="";
	string seller2 = "";
	cout << "\nPlease enter the name of the 1st seller ";
	cin >> seller1;
	cout << "\nPlease enter the name of the 2nd seller ";
	cin >> seller2;
	int seller1Loc = searchSellers (sellers, numSellers, seller1);
	int seller2Loc = searchSellers (sellers, numSellers, seller2);
	if (seller2Loc != -1 && seller1Loc != -1){
		SortedSet * Union = unionSS (sellers[seller1Loc].products, sellers[seller2Loc].products);
		cout << "The union is: ";
		displayElements (Union);
		cout << endl;
	}else{
		if (seller1Loc == -1){
			cout << seller1 << " is not a valid seller" <<endl;
		}
		if(seller2Loc == -1 ){
			cout << seller2 << " is not a valid seller" <<endl;
		}
	}
	system("pause");
	system("cls");
}
//The user must specify the names of two sellers. An ordered list of the products sold in common by
//both sellers should be displayed on the monitor. There should be no duplicates present.
void option7(Seller sellers[], int numSellers){
	string seller1 ="";
	string seller2 = "";
	cout << "\nPlease enter the name of the 1st seller ";
	cin >> seller1;
	cout << "\nPlease enter the name of the 2nd seller ";
	cin >> seller2;
	int seller1Loc = searchSellers (sellers, numSellers, seller1);
	int seller2Loc = searchSellers (sellers, numSellers, seller2);
	if (seller2Loc != -1 && seller1Loc != -1){
		SortedSet * intersect = intersectionSS (sellers[seller1Loc].products, sellers[seller2Loc].products);
		cout << "The Intersection is: ";
		displayElements (intersect);
		cout << endl;
	}else{
		if (seller1Loc == -1){
			cout << seller1 << " is not a valid seller" <<endl;
		}
		if(seller2Loc == -1 ){
			cout << seller2 << " is not a valid seller" <<endl;
		}
	}
	system("pause");
	system("cls");
}
////The user must specify the name of a product. The names of all the sellers who sell that product should be displayed on the monitor.
void option8 (Seller sellers[], int numSellers){
	string productName = "";
	cout << "\nPlease enter the product name ";
	cin >> productName;
	listSellers (sellers, numSellers, productName);
	system("pause");
	system("cls");
}

int main() {
	
	Seller sellers[1000];
	int numSellers;
	char filename [100] = "Sellers.txt";
  	int i;
 
 	// write code to display menu and process options selected by user
 	system("cls");
	
	string choice = "1";
	
	cout << "\n\n\n\n\t\tCOMP2611: Assignment 2\n";
	cout << "\t\tTamika Ramkissoon\n";
	cout << "\t\t816010368\n";
	cout << "\t\ttamika.ramkissoon@my.uwi.edu\n\n";
	
	system("pause");
	system("cls");
	
	cout << "\tSTART OF ASSIGNMENT\n\n";
	numSellers = readSellers (sellers, filename);
	
	while (choice != "9"){
		menu();
		cin	>> choice;
		// OPTION 1
		if(choice == "1"){
		//function call
			option1 (sellers, numSellers);
		//OPTION 2
		} else if (choice == "2"){
		//function call
			option2(sellers, numSellers);
		//OPTION 3	
		}else if(choice == "3"){
		//function call
		option3(sellers, numSellers);
		//OPTION 4		
		}else if (choice == "4"){
		//function call
			option4(sellers, numSellers);
		//OPTION 5	
		}else if (choice == "5"){
		//function call
			option5(sellers, numSellers);
		//OPTION 6	
		}else if (choice == "6"){
			//function call
			option6(sellers, numSellers);
		//OPTION 7
		} else if (choice == "7"){
			//function call
			option7(sellers, numSellers);
			//OPTION8
		} else if (choice == "8"){
			//function call
			option8(sellers, numSellers);
		} 
	}
	if (choice == "9"){
		option9();
	}		

	return 0;
}

