#include "binary_tree.h"

// A node of a binary tree.
struct TreeNode {
	int elem;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int elem = 0, TreeNode *left = nullptr, TreeNode *right = nullptr) :
		elem(elem), left(left), right(right) {			
	}
};

int treeSize(const TreeNode *node) {
	// Get size of the tree recursively.
	if (!node) {
		return 0;
	}
	return 1 + treeSize(node->left) + treeSize(node->right);
}

void treeDelete(TreeNode *node) {
	// Delete the tree recursively.
	if (!node) {
		return;
	}
	treeDelete(node->left);
	treeDelete(node->right);
	delete node;
}

Set::Set() {    
}

Set::~Set() {    
	// Destroy the tree.
    treeDelete(root);
}

void Set::insert(int elem) {
   
	if (!this->root) {
		this->root = new TreeNode(elem);
		return;
	}
	auto node = new TreeNode(elem);
	TreeNode *parent = this->root;
	while(1)
	{
		if(parent->elem == elem) return;
		if (parent->elem < elem ) {
			if(parent->right)
			{
				parent = parent->right;
				continue;
			}
			parent->right = node;
			return;
		}
		else
		{
			if(parent->left)
			{
				parent = parent->left;
				continue;
			}
			parent->left = node;
			return;
		}
	}
}
// Return true if the element is in the set, false otherwise.
bool Set::find(int elem) const {
 
	if (!this->root) return false;
	TreeNode* parent = this->root;

	while (1)
	{
		if (parent->elem == elem) return true;
		if (parent->elem < elem) {
			if (parent->right)
			{
				parent = parent->right;
				continue;
			}
			return false;
		}
		else
		{
			if (parent->left)
			{
				parent = parent->left;
				continue;
			}
			return false;
		}
	}
}

int Set::size() const {
    return treeSize(root);    
}
