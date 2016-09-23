//
//  word.cpp
//  originalstructure
//
//  Created by Amir Jabbari on 9/12/16.
//  Copyright © 2016 Amir Jabbari. All rights reserved.
//

#include "word.hpp"

word::word(string word, string date, int count, double weight, double percentChange){
    wordItself = word;
    headlineDate = date;
    wordCount = count;
    wordWeight = weight;
    percentStockChange = percentChange;
}

word& word::operator=(word thisWord){
    swap( wordItself, thisWord.wordItself ) ;
    swap( headlineDate, thisWord.headlineDate ) ;
    swap( wordCount, thisWord.wordCount ) ;
    swap( wordWeight, thisWord.wordWeight ) ;
    swap( percentStockChange, thisWord.percentStockChange ) ;
    return *this;
}

istream& operator>>(istream& is,word& newWord){
    is >> newWord.wordItself >> newWord.headlineDate >> newWord.percentStockChange;
    return is;
}

ostream& operator<<(ostream& os,word& newWord){
    os << "Word: " << newWord.wordItself <<endl;
    os << "Headline Date: "<< newWord.headlineDate << endl;
    os << "Word Count: " << newWord.wordCount << endl;
    os << "Word Weight: " << newWord.wordWeight << endl;
    os << "Percent Stock Change: " << newWord.percentStockChange << endl;
    os << "*************************************" << endl;
    return os;
}

bool operator==(word word1, word word2){
    if(word1.wordItself == word2.wordItself)
    return true;
    else
    return false;

}
