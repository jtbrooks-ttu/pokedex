#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
template <typename T>
class BinaryTree
{
private:
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

    TreeNode *root;

    void destroySubTree(TreeNode* nodePtr)
    {
            if (nodePtr->left)
                destroySubTree(nodePtr->left);
            if (nodePtr->right)
                destroySubTree(nodePtr->right);
            
            delete nodePtr;
    }

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
    BinaryTree()
    {
        TreeNode *root;
    }

    ~BinaryTree()
    {
        destroySubTree(root);
    }

    void insertNode(T val)
    {
        TreeNode *newNode;
        TreeNode *nodePtr;
        newNode = new TreeNode(val);
        nodePtr = root;
        Insert(newNode, nodePtr);
    }

    void displayInOrder()
    {
        displayInOrder(root);
    }

    TreeNode *getRoot()
    {
        return root;
    }

    bool searchNode(TreeNode *nidePtr, T val)
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