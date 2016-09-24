//
//  hash.hpp
//  btreeTest
//
//  Created by Amir Jabbari on 9/22/16.
//  Copyright © 2016 Amir Jabbari. All rights reserved.
//

#ifndef hash_hpp
#define hash_hpp
#define HTSIZE 40
#include <stdio.h>
#include "word.hpp"
#include "tree.hpp"
#include <string>

#define HISIZE 40

class wordDBHash{
    
    //friend ostream& operator <<(ostream&, word obj); 
    public:
    wordDBHash();
    void insert(word);
    int hashFunction(word);
    void print();
    private:
    Tree<word> HT[HTSIZE];
    //int currentHTsize;
};
#endif /* hash_hpp */
