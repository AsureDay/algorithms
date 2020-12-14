#pragma once
#include <iostream>
#include <list>
using namespace std;
/**
* Set of integer numbers.
*/
// A node of a binary tree.
struct TreeNode {
    int elem;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode(int elem = 0, TreeNode* left = nullptr, TreeNode* right = nullptr) :
        elem(elem), left(left), right(right) {
    }
};
class Set {
public:
    Set();
    ~Set();

    ///printing tree left to right from
    void print();
    /// Insert the element into the set.
    void insert(int elem);

    /// Check if the element is in the set.
    bool find(int elem) const;

    /// Get size of the set.
    int size() const;
    /// return maximum height tree
    int get_max_height();
private:
    /// for printing tree 
    void print_list(const list<TreeNode*>& somelist);
    /// for get_max_height
    int get_max_height(TreeNode* root);
    /// for print
    list<TreeNode*>* get_list_childs(TreeNode* parent, int level);
   
    // Private members go here.
    struct TreeNode* root = nullptr;
};
