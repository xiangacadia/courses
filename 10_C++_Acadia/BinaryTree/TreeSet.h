//
//  TreeSet.h
//  BinaryTree
//
//  Created by Xiang Jiang on 2014-10-21.
//  Copyright (c) 2014 Xiang Jiang. All rights reserved.
//

#ifndef __BinaryTree__TreeSet__
#define __BinaryTree__TreeSet__

#include <iostream>

using namespace std;

class TreeSet
{
private:
    class TreeNode;
    TreeNode* m_rootNode;
    int m_nodeNum;
    
public:
    
    // Empty constructor
    TreeSet();
    
    // Constructor takes an array of string and its size
    TreeSet(string str[], int size);
    
    // Copy constructor
    TreeSet(const TreeSet& tree);
 
    // Assignment operator
    TreeSet& operator=(const TreeSet& tree);
    
    // destructor
    ~TreeSet();
    
    // Add s to the set, if it's not already there;
    // return true if the set changed, false otherwise.
    bool add(const string& str);
    
    // Remove all elements from the set
    void clear();
    
    // Test whether s is in the set
    bool contains(const string& s);
    
    // Test whether the set is empty
    bool isEmpty() const;
    
    // Remove s from the set, if it was there;
    // return true if the set changed, false otherwise
    bool remove(const string& s);
    
    // Return the number of strings in the set
    int size() const;
    
    // put the elements of the set into the array sa; assume that sa has sufficient room
    int toArray(string sa[]) const;
    
private:
    // Recursive function to add nodes
    bool insert(TreeNode*& root, string str);

    // Recursive pre-order traverse the binary tree
    void preOrderTraverse(TreeNode* root, string array[], int* counter) const;

    // Recursive find a node
    bool find(TreeNode*& root, string str, TreeSet::TreeNode*& node, TreeSet::TreeNode*& parent, bool& isLeft);
};








#endif /* defined(__BinaryTree__TreeSet__) */
