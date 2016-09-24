//
//  tree.cpp
//  btreeTest
//
//  Created by Amir Jabbari on 9/22/16.
//  Copyright © 2016 Amir Jabbari. All rights reserved.
//

#include "tree.hpp"
#include <iostream>     // std::cout
#include <new>

template <class T>
Tree<T>::Tree():root(NULL){}

template <class T>
Tree<T>::~Tree()
{
    freeMemory(root);
}

template <class T>
void Tree<T>::freeMemory(Tree::TreeNode *node)
{
    if (node==NULL)
    return;
    if (node->left)
    freeMemory(node->left);
    if (root->right)
    freeMemory(node->right);
    delete node;
}

template <class T>
//make it return value?
void Tree<T>::insert(T val)
{
    TreeNode * treeNode = NULL;
    try
    {
        treeNode = new TreeNode(val); // handle exception necessary?
    } catch (std::bad_alloc &exception)
    {
        std::cerr << "bad_alloc caught: " << exception.what() << std::endl;
        EXIT_FAILURE;
    }
    TreeNode *temp=NULL;
    TreeNode *prev=NULL;
    
    temp = root;
    while(temp)
    {
        prev = temp;
        if (temp->data.wordCount < treeNode->data.wordCount)
        temp = temp->right;
        else
        temp = temp->left;
    }
    if (prev==NULL)
    root = treeNode;
    else
    {
        if (prev->data.wordCount <treeNode->data.wordCount)
        prev->right = treeNode;  // use setter function?
        else
        prev->left = treeNode;
    }
}

template <class T>
void Tree<T>::print(TreeNode *root)
{
    if (root==NULL)
    return ;
    print(root->left);
    std::cout << root->data << std::endl;
    print(root->right);
}

template <class T>
void Tree<T>::print()
{
    print(root);
}

template <class T>
T Tree<T>::search(TreeNode *root, T word)
{
    if (root==NULL)
    return word;
    search(root->left, word);
    if (root->data == word){
        return root->data;
    }
    search(root->right, word);
    return root->data;
}

template <class T>
T Tree<T>::search(T new_word)
{
   T word = search(root,new_word);
    return word;
}

