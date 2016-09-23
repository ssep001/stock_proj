//
//  word.hpp
//  originalstructure
//
//  Created by Amir Jabbari on 9/12/16.
//  Copyright © 2016 Amir Jabbari. All rights reserved.
//

#ifndef word_hpp
#define word_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class word {
    
    public:
    word(string wordItself = "", string headlineDate = "", int wordCount = 0, double wordWeight = 0, double percentStockChange = 0);
    word& operator=(word);
    string wordItself;
    string headlineDate;
    int wordCount;
    double wordWeight;
    double percentStockChange; //percent change based on headline data
    
    friend istream& operator>>(istream&,word&);
    friend ostream& operator<<(ostream&,word&);
    friend bool operator==(word,word);
    
    
};

#endif //word_hpp
