//
//  tree.hpp
//  btreeTest
//
//  Created by Amir Jabbari on 9/22/16.
//  Copyright © 2016 Amir Jabbari. All rights reserved.
//

#ifndef tree_hpp
#define tree_hpp
#include <stdio.h>
#include "word.hpp"

template <class T>
class Tree
{
    // Internal class which stores only Node related information.
    struct TreeNode : public word{
        T data;
        TreeNode * left;
        TreeNode * right;
        
        TreeNode(T val):data(val),left(NULL),right(NULL)
        {
        }
    };
    public:
    TreeNode * root;
    T search(TreeNode *root, T word);
    void print(TreeNode*);
    void freeMemory(TreeNode*);
    
    
    
    Tree();
    ~Tree();
    void insert(T);
    void print();
    T search(T);
};

#endif /* tree_hpp */
