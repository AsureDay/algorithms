#include "binary_tree.h"



int treeSize(const TreeNode* node) {
	// Get size of the tree recursively.
	if (!node) {
		return 0;
	}
	return 1 + treeSize(node->left) + treeSize(node->right);
}

void treeDelete(TreeNode* node) {
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

void Set::print_list(const list<TreeNode*>& somelist)
{
	for (auto i : somelist)
	{
		cout << i->elem << '\t';
	}
}

void Set::insert(int elem) {

	if (!this->root) {
		this->root = new TreeNode(elem);
		return;
	}
	auto node = new TreeNode(elem);
	TreeNode* parent = this->root;
	while (1)
	{
		if (parent->elem == elem) return;
		if (parent->elem < elem) {
			if (parent->right)
			{
				parent = parent->right;
				continue;
			}
			parent->right = node;
			return;
		}
		else
		{
			if (parent->left)
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

int Set::get_max_height()
{
	return get_max_height(this->root);
}
int Set::get_max_height(TreeNode* root)
{
	if (!root) return 1;
	else
	{
		return 1 + fmax(get_max_height(root->right), get_max_height(root->left));
	}
}


list<TreeNode*>* Set::get_list_childs(TreeNode* parent,int level)
{
	if (!parent) return new list<TreeNode*>;
	
	if(level == 0)
	{
		list<TreeNode*>* result = new list<TreeNode*>;
		result->push_back(parent);
		return result;
	}
	else
	{
		auto l1 = get_list_childs(parent->left, level - 1);
		auto l2 = get_list_childs(parent->right, level - 1);
		l1->splice(l1->end(), *l2);
		return l1;
	}
}


void Set::print() {
	int maxheight = this->get_max_height();
	for(int i =0;i < maxheight;i++)
	{
		auto k = get_list_childs(this->root, i);
		print_list(*k);
		cout << endl;
	}
}