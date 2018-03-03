#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
using namespace std;
const int USERGUESSES = 6;
int main();
void playAgain();

string displayLines (string randomWord)
{
    string display;
    for (int i = 0; i < randomWord.length(); ++i)
    {
        display.append("-");
    }
    cout << display << endl;
    return display;
}
//wordSelector picks the word to be guessed at random.
string wordSelector( vector <string> array)
{
    srand((unsigned int) time(NULL)); //initializing seeded randon # srand uses unsigned int, time uses long by default which is bigger but not needed.
    int random = rand ()%10; //values between 0 and 9, assuming our file contains 10 words, one by line.
    return array[random];
}

//Makes the comparison between the user guess and the word to be guessed and displays an updated line.

void strCompare(char userGuess, string randomWord, string &display, int &maxGuesses)
{
    //cout << randomWord << endl;
    size_t found = randomWord.find_first_of(userGuess); //if the letter is found in our randomWord, returns first appearance of our guessed Letter
    if (found != string:: npos)
    {
        while (found != string:: npos) //while our userGuess is found throughout the string
        {
                display[found] = userGuess;
                found = randomWord.find_first_of(userGuess, found+1);
        }
    }
    else
    {
        cout << "That letter is not there, please try again." << endl;
        maxGuesses-=1;
        cout << "You have " << maxGuesses << " lives remaining." << endl;
    }
    cout << display << endl;
    if (randomWord == display)
    {
        cout << "Congratulations, you have won!" << endl;
        playAgain();
    }
}
//Stores the userGuess and makes sure it does not include any numbers in them, also will check for Capital letters and change them to lower case.
char userGuesses(string &guessedLetters)
{
    char userGuess;
    cout << "Please make a guess: ";
    cin >> userGuess;
    cin.ignore();
    userGuess = tolower(userGuess);
    cout << userGuess << endl;
        if (!isalpha(userGuess)) //if it's not a letter
        {
            cout << "That's not a letter! Please guess again" << endl;
            userGuesses(guessedLetters);
        }
        else
        {
            guessedLetters.push_back(userGuess);
            cout << "Letters you have guessed: " << guessedLetters << endl;
        }
    return userGuess;
}
//Opens the file and gives 3 tries to open it if the hardcoded path is not found, otherwise terminates the program.

void openFile(vector <string> &guessWords)
{
    int openFailed = 1;
    ifstream in_stream;//input file stream
    in_stream.open("/Users/Esteban/Desktop/Cplusplus/Hangman/GuessWords.txt");//opening the file
    while (!in_stream.is_open())
    {
        if (openFailed <= 3)
        {
            cout << "The file didn't open! :(" << endl;
            openFailed +=1;
            cout << "Please specify the location of your file: ";
            string filePath;
            cin >> filePath;
            in_stream.open(filePath);
        }
        else
        {
            cout <<"Opening the file failed, goodbye!" << endl;
            exit(0);
        }
    }
        string word;
        while (in_stream >> word)
        {
            guessWords.push_back(word);
        }
    in_stream.close();
}

void playAgain()
{
    int num = 0;
    cout << "Press 1 to play again, press 2 to exit: " << endl;
    while (!(cin >> num)) //This will only run if we get a bad input
    {
        cout << "Please enter a valid value!" << std::endl;
        cin.clear(); //clears a bad input flag in case you type something other than a number
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discards the input
    }
    if (num == 1)
    {
        main();
    }
    if (num == 2)
    {
        cout << "Goodbye!" << endl;
        exit(0);
    }
}

/*  Main function gives a welcome message and reads words to be guessed (hardcoded) from a file. 
    Calls on a function to start the game */
//argc and argv[] are argument count and argument vector, ways for a program to receive arguments.

int main()
{
    int maxGuesses = USERGUESSES;
    cout << "Welcome to hangman!" << endl << endl;
    vector <string> guessWords; //Where we will store our wordstobeguessed
    string guessedLetters = "";
    openFile(guessWords);
    string randomWord = wordSelector(guessWords);
    string display = displayLines(randomWord);
    while (maxGuesses != 0)
    {
        char guess = userGuesses(guessedLetters);
        strCompare(guess, randomWord, display, maxGuesses);
    }
    cout << "You ran out of letters, the word was " << randomWord<< "." << endl;
    playAgain();
    return 0;
}



