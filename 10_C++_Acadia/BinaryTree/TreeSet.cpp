//
//  TreeSet.cpp
//  BinaryTree
//
//  Created by Xiang Jiang on 2014-10-21.
//  Copyright (c) 2014 Xiang Jiang. All rights reserved.
//

#include "TreeSet.h"

#include <iostream>
#include <string>

using namespace std;

// Definition of inner class

class TreeSet::TreeNode
{
private:
    string value;
    TreeNode* left;
    TreeNode* right;
    
public:
    TreeNode() : left(0), right(0) {}
    TreeNode(string str) : value(str), left(0), right(0) {}
    
    
    ~TreeNode()
    {
        if (left)
            delete left;
        
        if (right)
            delete right;
    }
    
    string getValue() const
    {
        return value;
    }
    
    void setValue(string newValue)
    {
        value = newValue;
    }
    
    TreeNode*& getLeft()
    {
        return left;
    }
    
    TreeNode*& getRight()
    {
        return right;
    }
    
    // Get children number
    int getChildrenNum()
    {
        if (left && right)
        {
            return 2;
        }
        else
        {
            if (left || right)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    
    TreeNode*& getSingleChild()
    {
        if (left)
            return left;
        else
            return right;
    }
    
    void setLeft(TreeNode* node)
    {
        left = node;
    }
    
    void setRight(TreeNode* node)
    {
        right = node;
    }
    
};

// Definition of class TreeSet

// Empty constructor
TreeSet::TreeSet() : m_nodeNum(0), m_rootNode(0)
{ }


// constructor takes an array of string and its size
TreeSet::TreeSet(string str[], int size)
{
    for (int i = 0; i < size; i++) {
        add(str[i]);
    }
}


// copy constructor
TreeSet::TreeSet(const TreeSet& tree)
{
    int count = tree.size();
    string *temp = new string[count];
    tree.toArray(temp);
    
    for (int i = 0; i < count; i++) {
        add(temp[i]);
    }
    
    delete[] temp;
    
}

// destructor
TreeSet::~TreeSet()
{
    if (m_rootNode != NULL)
        delete m_rootNode;
}

// Assignment operator
TreeSet& TreeSet::operator=(const TreeSet& tree)
{
    clear();
    int count = tree.size();
    string *temp = new string[count];
    tree.toArray(temp);
    
    for (int i = 0; i < count; i++) {
        add(temp[i]);
    }
    
    delete[] temp;
    return *this;
}

// Add s to the set, if it's not already there;
// return true if the set changed, false otherwise.
bool TreeSet::add(const string& s)
{
    return insert(m_rootNode, s);
}

bool TreeSet::insert(TreeNode*& root, string str)
{
    if (!root)
    {
        root = new TreeNode(str);
        m_nodeNum++;
        
        return false;
    }
    else
    {
        int cmp = str.compare(root->getValue());
        
        if (!cmp)
        {
            return true;
        }
        else
        {
            if (cmp < 0)
            {
                if (!root->getLeft())
                {
                    root->setLeft(new TreeNode(str));
                    m_nodeNum++;
                    return false;
                }
                else
                {
                    insert(root->getLeft(), str);
                }
            }
            else
            {
                if (!root->getRight())
                {
                    root->setRight(new TreeNode(str));
                    m_nodeNum++;
                    return false;
                }
                else
                {
                    insert(root->getRight(), str);
                }
            }
            
        }
    }
    
    return true;
}

// put the elements of the set into the array sa; assume that sa has sufficient room
int TreeSet::toArray(string sa[]) const
{
    int counter = 0;
    preOrderTraverse(m_rootNode, sa, &counter);
    return m_nodeNum;
}

void TreeSet::preOrderTraverse(TreeNode* root, string array[], int* counter) const
{
    if (!root)
    {
        return;
    }
    else
    {
        array[(*counter)++] = root->getValue();
        preOrderTraverse(root->getLeft(), array, counter);
        preOrderTraverse(root->getRight(), array, counter);
    }
}

// Recursive find a node
bool TreeSet::find(TreeNode*& root, string str, TreeSet::TreeNode*& node, TreeSet::TreeNode*& parent, bool& isLeft)
{
    if (m_rootNode && m_rootNode->getValue()==str) {
        node = m_rootNode;
        return true;
    }
    
    if (!root)
    {
        return false;
    }
    else
    {
        if(root->getLeft() && root->getLeft()->getValue() == str)
        {
            node = root->getLeft();
            parent = root;
            isLeft = true;
            return true;
        }
        
        if(root->getRight() && root->getRight()->getValue() == str)
        {
            node = root->getRight();
            parent = root;
            isLeft = false;
            return true;
        }
        
        if (find(root->getLeft(), str, node, parent, isLeft))
            return true;
        
        if (find(root->getRight(), str, node, parent, isLeft))
            return true;
    }
    return false;
}

// Return the number of strings in the set
int TreeSet::size() const
{
    return m_nodeNum;
}

// Remove all elements from the set
void TreeSet::clear()
{
    m_nodeNum = 0;
    if (m_rootNode != NULL)
        delete m_rootNode;
    m_rootNode = NULL;
}

// Remove s from the set, if it was there;
// return true if the set changed, false otherwise
bool TreeSet::remove(const string& str)
{
    TreeNode* node = NULL;
    TreeNode* parent = NULL;
    bool isLeft;
    if(find(m_rootNode, str, node, parent, isLeft) == false)
        return false;
    else
    {
        m_nodeNum--;
        
        int childrenNum = node->getChildrenNum();
        
        // leaf
        if (!childrenNum) {
            if (!isLeft)
                parent->setRight(NULL);
            else
                parent->setLeft(NULL);
            delete node;
            return true;
        }
        
        // only one child
        if (childrenNum == 1) {
            if (!isLeft)
                parent->setRight(node->getSingleChild());
            else
                parent->setLeft(node->getSingleChild());
            if (node->getLeft() && node->getLeft()->getValue() == str)
                node->setLeft(NULL);
            else
                node->setRight(NULL);
            delete node;
            return true;
        }
        
        // more than one child, find the right most node in the left subtree
        if (childrenNum == 2)
        {
            TreeNode* upper = node;
            TreeNode* temp = node->getLeft();
            while (temp->getRight()) {
                upper = temp;
                temp = temp->getRight();
            }
            if (upper->getLeft() && upper->getLeft()->getValue() == temp->getValue())
                upper->setLeft(NULL);
            else
                upper->setRight(NULL);
            
            node->setValue(temp->getValue());
            temp->setLeft(NULL);
            temp->setRight(NULL);
            delete temp;
        }
    }
    return false;
}

// Test whether s is in the set
bool TreeSet::contains(const string& str)
{
    TreeNode* node = NULL;
    TreeNode* parent = NULL;
    bool isLeft;
    bool b = find(m_rootNode, str, node, parent, isLeft);
    return b;
}

// Test whether the set is empty
bool TreeSet::isEmpty() const
{
    if (m_nodeNum == 0)
        return true;
    else
        return false;
}