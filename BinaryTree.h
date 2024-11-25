/*
    File: BinaryTree.h
    Author: J.T. Brooks
    Date: 11/14/24
    Purpose: Header file containing templated Binary Tree class.
*/
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
template <typename T>
class BinaryTree
{
private:
    //TreeNode structure acts as node for tree
    struct TreeNode
    {

        T value;
        TreeNode *left;
        TreeNode *right;

        TreeNode()
        {
            left = NULL;
            right = NULL;
        }

        TreeNode(T val)
        {
            value = val;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
        }
    };

    TreeNode *root; //root ptr

    //can be use to destroy parts of tree... also called in destructor
    void destroySubTree(TreeNode *nodePtr)
    {
        if (nodePtr->left)
            destroySubTree(nodePtr->left);
        if (nodePtr->right)
            destroySubTree(nodePtr->right);

        delete nodePtr;
    }

    //recursively searches tree for appropriate spot for the new node
    void Insert(TreeNode *newNode, TreeNode *nodePtr)
    {
        if (!root)
        {
            root = newNode;
        }
        else
        {
            if (nodePtr != NULL)
            {
                if (newNode->value < nodePtr->value)
                {
                    if (nodePtr->left)
                        Insert(newNode, nodePtr->left);
                    else
                        nodePtr->left = newNode;
                }
                else if (nodePtr->value < newNode->value)
                {
                    if (nodePtr->right)
                        Insert(newNode, nodePtr->right);
                    else
                        nodePtr->right = newNode;
                }
                else
                    cout << "Value already in tree." << endl;
            }
            else
                nodePtr = newNode;
        }
    }

    //prints tree from least to most
    void displayInOrder(TreeNode *nodePtr) const
    {
        if (nodePtr)
        {
            displayInOrder(nodePtr->left);
            cout << nodePtr->value;
            displayInOrder(nodePtr->right);
        }
    }

public:
    //constructor
    BinaryTree()
    {
        TreeNode *root;
    }

    //destructor
    ~BinaryTree()
    {
        destroySubTree(root);
    }

    //creates the new node and sends it to Insert with the root
    void insertNode(T val)
    {
        TreeNode *newNode;
        TreeNode *nodePtr;
        newNode = new TreeNode(val);
        nodePtr = root;
        Insert(newNode, nodePtr);
    }
    
    //sends root to display function
    void displayInOrder()
    {
        displayInOrder(root);
    }

    //getter
    TreeNode *getRoot()
    {
        return root;
    }

    //searches for chosen node and returns true if found
    bool searchNode(T val)
    {
        TreeNode *nodePtr = root;

        while (nodePtr)
        {
            if (nodePtr->value == val)
                return true;
            else if (val < nodePtr->value)
                nodePtr = nodePtr->left;
            else
                nodePtr = nodePtr->right;
        }
        return false;
    }
};
#endif