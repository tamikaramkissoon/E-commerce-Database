#include <iostream>
#include <cstdlib>
#include "BinaryTree.h"

using namespace std;


BTNode * createBTNode (string data) {
	BTNode * newNode; 
   
	newNode = new BTNode;
   
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
   
	return newNode;
}

// Write code here for the copyBT function

BTNode * copyBT (BTNode * root) {
	if (root == NULL )
	 return root; 
 
   BTNode *temp = createBTNode(root->data);    
   temp->parent = root->parent;
   temp->left = copyBT(root->left);    
   temp->right = copyBT(root->right);  
   return temp;
}



void preOrder (BTNode * root) {
	
	if (root == NULL)
		return;
		
	cout << root->data << " ";

	preOrder (root->left);
	preOrder (root->right);
}



void inOrder (BTNode * root) {
	
	if (root == NULL)
		return;

	inOrder (root->left);
	
	cout << root->data << " ";
	
	inOrder (root->right);
}



void postOrder (BTNode * root) {
	
	if (root == NULL)
		return;

	postOrder (root->left);
	postOrder (root->right);
	
	cout << root->data << " ";
}



int moment (BTNode * root) {

	if (root == NULL)
		return 0;
		
	return (1 + moment (root->left) + moment (root->right));
}



int numOneChild (BTNode * root) {

	if (root == NULL)
		return 0;
		
	if (root->left == NULL && root->right == NULL)
		return 0;

	if (root->left == NULL)
		return 1 + numOneChild (root->right);
	else
	if (root->right == NULL)
		return 1 + numOneChild (root->left);
	else
		return (numOneChild (root->left) + numOneChild (root->right));
}



int numNonTerminal (BTNode * root) {

	if (root == NULL)
		return 0;
		
	if (root->left == NULL && root->right == NULL)
		return 0;
		
	return (1 + numNonTerminal (root->left) + numNonTerminal (root->right));
}
