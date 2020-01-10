//
//  main.cpp
//  Hangman
//
//  Created by robert feliz on 1/8/20.
//  Copyright © 2020 robert feliz. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void hangman(void);
string pickWord(void);

int main(int argc, const char * argv[])
{
    
    string userName;
    char choice;
    
    //loop to select the name
    do
    {
    cout << "Welcome to Hangman, what is your name?\n";
    getline(cin,userName);
    
    cout << "Your name is: "<<userName<<"\n";
    cout<<"Is that correct?(y/n)\n";
    
    cin>>choice;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }while (choice != 'y'&&choice != 'Y'&&choice != 'n'&&choice != 'N');
    
    hangman();
    
    return 0;
}

void hangman(void)
{
    string word = pickWord();
    string unknownWord(word.length(),'*');
    
    cout << unknownWord;
}

//function to randomly pick the word used for guessing
string pickWord(void)
{
    string words[] =
    {
        "mere"
        "laughable"
        "mother"
        "detail"
        "attempt"
        "chief"
        "annoying"
        "immense"
        "changeable"
        "train"
        "unnatural"
        "loutish"
        "government"
        "smell"
        "berserk"
    };
    
    srand(time(NULL));
    
    int randNum = rand() % 15 + 1;
    
    string mainWord = words[randNum];
    return mainWord;
}
