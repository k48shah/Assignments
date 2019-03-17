#include <iostream>
#include "binary_search_tree.hpp"

using namespace std;


BinarySearchTree::Node::Node( int new_val ) {
	val = new_val;
	
	left = NULL;
	right = NULL;
}

void deleteNode(BinarySearchTree::Node* n)
{
	if (!n) {
		return;
	}
	else 
	{
		deleteNode(n->left);
		deleteNode(n->right);
		delete n;
		n = NULL;
	}
}

BinarySearchTree::BinarySearchTree() {
	root_ = NULL;
	
	size_ = 0;
}

BinarySearchTree::~BinarySearchTree() {
	deleteNode(root_);
}


int BinarySearchTree::getNodeDepth( Node* n ) const {
	if (!n)
	{
		return -1;
	}
	int depthR = 0;
	int depthL = 0;
	depthR = 1 + getNodeDepth(n->right);
	depthL = 1 + getNodeDepth(n->left);
	if (depthL < depthR)
	{
		return depthR;
	}
	else
	{
		return depthL;
	}
}

unsigned int BinarySearchTree::size() const {
	return size_;
}

int BinarySearchTree::max() const {
	Node* temp = root_;
	while (temp->right != NULL)
	{
		temp = temp->right;
	}
	return temp->val;
}

int BinarySearchTree::min() const {
	Node* temp = root_;
	while (temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp->val;
}

unsigned int BinarySearchTree::depth() const {
	return getNodeDepth(root_); 
}
void BinarySearchTree::print() const {
}

bool BinarySearchTree::exists( int val ) const {
	Node* temp = root_;
	if(!temp)
	{
		return false;
	}
	while (temp->val != val)
	{
		if (val > temp->val)
		{
			if (temp->right)
			{
				temp = temp->right;
			}
			else
			{
				return false;
			}
		}
		else if (val < temp->val)
		{
			if (temp->left)
			{
				temp = temp->left;
			}
			else
			{
				return false;
			}
		}
	}
	if (val == temp->val)
	{
		return true;
	}
	return false;
}

BinarySearchTree::Node* BinarySearchTree::getRootNode() {
    return root_;
}

BinarySearchTree::Node** BinarySearchTree::getRootNodeAddress() {
    return &root_;
}

bool BinarySearchTree::insert( int val ) {
	if (exists(val))
	{
		return false;
	}
	if (root_ == NULL)
	{
		root_ = new Node(val);
		size_++;
		return true;
	}
	Node* temp = root_;
	while (temp)
	{
		if (val > temp->val)
		{
			if (temp->right == NULL)
			{
				temp->right = new Node(val);
				size_++;
				return true;
			}
			temp = temp->right;
		}
		else if (val < temp->val)
		{
			if (temp->left == NULL)
			{
				temp->left = new Node(val);
				size_++;
				return true;
			}
			temp = temp->left;
		}
	}
}

bool BinarySearchTree::remove( int val ) {
	if (exists(val) == false)
	{
		return false;
	}
	Node* temp = root_;
	Node* tempRoot = root_;
	while (temp->val != val)
	{
		tempRoot = temp;
		if (val > temp->val)
		{
			temp = temp->right;
		}
		else if (val < temp->val)
		{
			temp = temp->left;
		}
	}
	if (temp->right == NULL && temp->left == NULL)
	{
		temp->right = NULL;
		temp->left = NULL;
		delete temp;
		temp = NULL;
		size_--;
		return true;
	}
	else if (temp->right != NULL && temp->left != NULL)
	{
		Node* tempSwitch = temp->right;
		Node* nodeR = temp->right;
		Node* nodeL = temp->left;
		while (tempSwitch->left)
		{
			tempSwitch = tempSwitch->left;
		}
		Node* temp2 = temp;
		Node* tempMin = tempSwitch->right;
		temp = tempSwitch;
		temp->left = nodeL;
		if (tempSwitch != nodeR)
		{
			temp->right = nodeR;
			tempSwitch = tempMin;
		}
		delete temp;
		temp = NULL;
		size_--;
		return true;
	}
	else if (temp->right != NULL || temp->left != NULL)
	{
		Node* temp2 = temp;
		if (temp->right != NULL)
		{
			temp2 = temp->right;
		}
		else if (temp->left != NULL)
		{
			temp2 = temp->left;
		}
		if (tempRoot->val < temp2->val)
		{
			tempRoot->right = temp2;
		}
		if (tempRoot->val < temp2->val)
		{
			tempRoot->left = temp2;
		}
		temp = NULL;
		size_--;
		return true;
	}
	return false;
}
