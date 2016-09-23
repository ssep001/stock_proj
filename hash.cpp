//
//  hash.cpp
//  btreeTest
//
//  Created by Amir Jabbari on 9/22/16.
//  Copyright © 2016 Amir Jabbari. All rights reserved.
//

#include "hash.hpp"
#include "tree.cpp"

wordDBHash::wordDBHash(){
    
}

void wordDBHash::insert(word new_word){
    int index = hashFunction(new_word);
    if(HT[index].root != NULL && HT[index].root->data == new_word){
        HT[index].root->data.wordCount++;
    }
    else{
        new_word.wordCount++;
    HT[index].insert(new_word);
    }
    if (HT[index].search(new_word) == new_word){
        cout << "I found the same word" << endl;
    }
}

int wordDBHash::hashFunction(word new_word){
    int hash = 0;
    int index;
    
    for(int i = 0; i < new_word.wordItself.length(); i++)
    {
        hash = (hash + (int)new_word.wordItself[i]) * 8;
    }
    
    index = hash % HTSIZE;
    
    return index;
}

void wordDBHash::print(){
    for(int i = 0; i < HTSIZE; i++){
        HT[i].print();
    }
}
