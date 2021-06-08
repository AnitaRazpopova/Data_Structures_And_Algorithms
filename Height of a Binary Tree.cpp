// Height of a Binary Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};
struct Node* createnode(int data)
{
	Node* newnode = new Node;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
int max(int a, int b)
{
	int res = (a > b) ? a : b;
	return res;
}
int height(Node* node)
{
	if (node == NULL)
		return 0;
	return (1 + max(height(node->left), height(node->right)));
}
int diameter(Node* node)
{
	if (node == NULL)
		return 0;
	int lheight = height(node->left);
	int rheight = height(node->right);
	int ldiameter = diameter(node->left);
	int rdiameter = diameter(node->right);
	return max((lheight + rheight), max(ldiameter, rdiameter));
}
int main()
{
	Node* root = createnode(1);
	root->left = createnode(2);
	root->right = createnode(3);
	root->left->left = createnode(4);
	root->left->right = createnode(5);
	root->left->right->left = createnode(7);
	root->left->right->right = createnode(8);
	root->right->right = createnode(6);
	root->right->right->right = createnode(9);
	root->right->right->right->left = createnode(11);
	root->right->right->right->right = createnode(10);
	root->right->right->right->left->left = createnode(12);
	root->right->right->right->left->right = createnode(13);
	cout << "Diameter of the given binary tree is " << height(root) << endl;
	
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
