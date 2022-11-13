#include "equal-paths.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

// You may add any prototypes of helper functions here
int height(Node* root)
{
	//if the AVL tree is emoty 
	if(root == nullptr)
	{
		return 0;
	}
	//iterate through the right and left tree 
	//and calculate the height, return the max 
	int subLeftTreeHeight = height(root->left);
	int subRightTreeHeight = height(root->right);
	return max(subLeftTreeHeight,subRightTreeHeight) + 1;
}

bool equalPaths(Node* root)
{
	//if the avl tree is empty/the node is empty 
	if(root == nullptr)
	{
		return true;
	}
	//if both children are empty then the tree is balanced 
  if(root->right == nullptr && root->left==nullptr)
	{
		return true;
	}
	//only the left child is present , check and see if it is balanced 
	if(root->left != nullptr && root->right == nullptr) {
			return equalPaths(root->left);
		}
	//only the right child is presnt, check and see if it is balanced 
	if(root->left == nullptr && root->right != nullptr) {
			return equalPaths(root->right);
		}
	//If the height between the two subtrees are equal
	//return balanced value 
	if(height(root->right) == height(root->left))
	{
		return true;
	}
	//if the height of the tree don't equal one another 
	else
	{
		return false;
	}
}
