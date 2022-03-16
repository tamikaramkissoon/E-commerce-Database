#include <iostream>
#include <cstdlib>
#include "NodeTypes.h"
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include "SortedSet.h"

using namespace std;

//Creates an empty SortedSet and returns the address of the SortedSet created.
SortedSet * initSortedSet () {
	SortedSet * set = new SortedSet;
	set->root = NULL;
	set->size = 0;	
	return set;
}


//Returns true if the SortedSet contains key and false, otherwise.
bool containsSS (SortedSet * s, string key) {
	
	SortedSet temp = *s;
	temp.root = containsBST(temp.root, key);
	if(temp.root != NULL)
		return true;
		
	return false;
}


//Inserts data in the SortedSet, maintaining the sorted order of the elements.
void insertSS (SortedSet * s, string data) {
	
	s->root = insertBST (s->root, data);
	s->size = s->size++;
	return;
}


//Deletes key from the SortedSet, maintaining the sorted order of the elements.
void deleteSS (SortedSet * s, string key) {
	s->root = deleteBST (s->root,  key);
	return;
}

//Returns a copy of the SortedSet passed as a parameter.
SortedSet * copySS (SortedSet * s){
	SortedSet * NewTree = initSortedSet ();
	NewTree->root =  copyBT (s->root);
	NewTree->size = s->size;
	return NewTree;
}

//Returns the union of the two SortedSets passed as parameters. There should be no
//duplicates present in the SortedSet returned by the function.
SortedSet * unionSS (SortedSet * s1, SortedSet * s2) {

	SortedSet * c1 = initSortedSet ();
   	SortedSet * c2 = initSortedSet ();
   	c1 = copySS (s1);
   	c2 = copySS (s2);
   	
   	int size1 = sizeSS(c1);
   	int size2=0;
   	while(size2 < size1){
   		if (containsSS(c2, c1->root->data)){
   			deleteSS(c1, c1->root->data);
		}
		else{
			insertSS(c2, c1->root->data);
			deleteSS(c1, c1->root->data);
		}
		size2++;
	   }
	return c2;
}


	
	
//Returns the intersection of the two SortedSets passed as parameters. There should be no
//duplicates present in the SortedSet returned by the function.	
SortedSet * intersectionSS (SortedSet * s1, SortedSet * s2) {

  	SortedSet * c1 = initSortedSet ();
   	SortedSet * c2 = initSortedSet ();
   	SortedSet * c3 = initSortedSet ();
   	c1 = copySS (s1);
   	c2 = copySS (s2);
   	
   	int size1 = sizeSS(c1);
   	int size2=0;
   	while(size2 < size1){
   		if (containsSS(c2, c1->root->data)){
   			insertSS(c3, c1->root->data);
   			
		}
		deleteSS(c1, c1->root->data);
		size2++;
	   }
	return c3;
}



//Returns true if the SortedSet has no elements and false, otherwise.
bool isEmptySS (SortedSet * s) {
	if (s->root == NULL)
		return true;
	
	return false;
}


//Returns the number of elements in the SortedSet.
int sizeSS (SortedSet * s) {
	int size= moment (s->root);
	
	return size;
}


//Displays the keys from the SortedSet on the monitor, in sorted order.
void displayElements (SortedSet * s) {
	inOrder (s->root);
	return;
}


//Returns the value from the SortedSet that comes immediately after key in sorted order.
//If key is not present, returns the next higher value if it exists.
string nextKey (SortedSet * s, string key) {
	
	BTNode * found = containsBST (s->root, key);
	if (found != NULL){
		BTNode * next = inOrderSuccessor (found);
		return next->data;	
	}else{
//	BTNode * temp = s->root;
//		while (temp!= NULL){
//			if (temp->data > key){
//				return temp->data;
//			}
//			temp = temp->right;
//		}
		insertSS (s, key);
		BTNode * found = containsBST (s->root, key);
		if (found != NULL){
			BTNode * next = inOrderSuccessor (found);
			deleteSS(s,key);
			if (next==NULL)
				return "";
			else
			return next->data;
			
		}
	}
	return"";
}



//Returns the value from the SortedSet that comes immediately before key in sorted order.
//If key is not present, return the next lower value if it exists.
string previousKey (SortedSet * s, string key) {
	
	BTNode * found = containsBST (s->root, key);
	if (found != NULL){
		BTNode * next = inOrderPredecessor (found);
		return next->data;	
	}else{
//		BTNode * temp = s->root;
//		string prev="";
//		while (temp!= NULL){
//			if (temp->data < key){
//				prev = temp->data;	
//			}
//			temp = temp->right;
//		}
//		return prev;
		insertSS (s, key);
		BTNode * found = containsBST (s->root, key);
		if (found != NULL){
			BTNode * next = inOrderPredecessor (found);
			deleteSS(s,key);
			return next->data;	
		}
	}
	return"";	
}









