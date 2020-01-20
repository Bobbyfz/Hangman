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

//constant that is defined as the max guesses before the game ends
const int MAX_GUESSES = 6;

using namespace std;

void hangman(void);
string pickWord(void);
int letterFilling(string guessedChar,string secretWord,string &unkownWord);
void guessWord(void);
void end(void);

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

    }while (choice != 'y'&&choice != 'Y');
    
    hangman();
    
    return 0;
}

void hangman(void)
{
    //character to keep track of the guessed letter
    string guessedWord;
    int numOfGuesses = 0;
    string secretWord = pickWord();
    //replaces the word with asterisks
    string unknownWord(secretWord.length(),'*');
    
    cout << "The mystery word is covered by asterisks\n";
    cout << "Guess one letter at a time\n";
    cout << "You'll have six tries to guess the word\n";
    cout << "The unknown word is " << unknownWord << "\n";
   //main loop of the game
    while (numOfGuesses < MAX_GUESSES)
    {
        cout << "guess a letter of the unknown word or guess the word: ";
        cin >> guessedWord;
    
        //did the user guess a character incorrect
        if (letterFilling(guessedWord, secretWord, unknownWord) == 0&&guessedWord.size() == 1)
        {
            cout << "That letter is not in the word!\n";
            numOfGuesses++;
        }else if (letterFilling(guessedWord, secretWord, unknownWord) != 0&&guessedWord.size() == 1)
        {
            cout << "That letter is in the word!\n";
            cout << "The unknown word is now "<<unknownWord<<"\n";
        }
        
        
        //checks to see if the user tries to guess the word
        if (guessedWord.size() > 1)
        {
            if (guessedWord == secretWord)
            {
                cout << "You guessed the word!\n";
                cout << "The word was " << secretWord << "\n";
                end();
            }else
            {
                cout << "That was not the correct word, 2 guesses have been used.\n";
                numOfGuesses += 2;
            }
        }
        
        if (unknownWord == secretWord)
        {
            cout << "You win!\n";
            cout << "The secret word was " << unknownWord << "\n";
            end();
        }
        cout << "You have " << MAX_GUESSES - numOfGuesses << " chance(s) left\n";
        
        //last if to see if the tries have run out and display the end word
        if (numOfGuesses == MAX_GUESSES)
        {
            cout << "You have been hanged!\nThe secret word was "<< secretWord <<"\n";
            end();
        }
    }
    
}

//function to randomly pick the word used for guessing
string pickWord(void)
{
    string words[] =
    {
        "mere",
        "laughable",
        "mother",
        "detail",
        "attempt",
        "chief",
        "annoying",
        "immense",
        "changeable",
        "train",
        "unnatural",
        "loutish",
        "government",
        "smell",
        "berserk",
    };
    
    srand(time(NULL));
    
    int randNum = rand() % 15;
    
    string mainWord = words[randNum];
    return mainWord;
}

int letterFilling(string guessedChar,string secretWord,string &unknownWord)
{
    int match = 0;
    
    for (int i = 0;i < secretWord.length();i++)
    {
        //checks to see if guessed before
        if (guessedChar[0] == unknownWord[i])
        {
            return 0;
        }
        //is the guessed character in the secret word
        if (guessedChar[0] == secretWord[i])
        {
            unknownWord[i] = guessedChar[0];
            match++;
        }
    }
    
    return match;
}

void end(void)
{
    char choice;
    
    do
    {
        cout << "Would you like to try again? (y/n)";
        cin >> choice;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while (choice != 'y'&&choice != 'Y'&&choice != 'n'&&choice != 'N');
    
    if (choice == 'n'||choice == 'N')
    {
        cout << "Thanks for playing!\n";
        exit(0);
    }
    if (choice == 'y'||choice == 'Y')
    {
        hangman();
    }
  
}
