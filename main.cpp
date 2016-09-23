#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include "tree.cpp"
#include "word.hpp"
#include "hash.hpp"
int main()
{
    ifstream inputFile;
    inputFile.open("wordFile.txt");
    

    // Taking the first word and adding it to the first index of the vector
    
/*
    vector<word> vectorOfWords;
    vectorOfWords.push_back(tempWord);
    bool found = false;
    
    while(!inputFile.eof()){
        
        found = false;
        inputFile >> tempArray;
        // Comparing the new word from file to the existing words in vector
        for (int j = 0; j < vectorOfWords.size(); j++)
        {   // if the word exist -> increment the word_count
            if(tempArray.wordItself == vectorOfWords[j].wordItself)
            {
                vectorOfWords.at(j).wordCount++;
                found = true;
            }
        }
        if(!found)
        {
            // adding the new word if not in the vector
            vectorOfWords.push_back(tempArray);
            // incrementing the word count of the specific added word
            vectorOfWords.at(vectorOfWords.size()-1).wordCount++;
        }
    }
    // printing the words in the vector
    for(int i = 0 ; i < vectorOfWords.size();i++){
        cout << vectorOfWords[i];
    }
 
    inputFile.close();
    
*/
//    Tree<word> tree;
//    word tempWord2("Apple", "2016-08-31",1,0,0);
//    tree.insert(tempWord2);
//    tree.search(tempWord2,false);
//    //tree.print();
    
    
    // word obj ("word", "date", word_count, word_weight, percent_change )
    word tempWord;
    wordDBHash hash;
    while(!inputFile.eof()){
        inputFile >> tempWord;
        hash.insert(tempWord);
    }
    inputFile.close();
    //hash.print();
    
    
    
    
    
    
    return 0;
}
