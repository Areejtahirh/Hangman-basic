// Hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to display the current progress of the guessed word
void displayWord(const string& guessedWord) {
    for (int i = 0; i < guessedWord.size(); i++) {
        cout << guessedWord[i] << " ";
    }
    cout << endl;
}

// Function to check if the word has been fully guessed
bool isWordGuessed(const string& guessedWord) {
    for (int i = 0; i < guessedWord.size(); i++) {
        if (guessedWord[i] == '_') {
            return false;
        }
    }
    return true;
}

// Function to check if a character exists in a vector
bool isInVector(const vector<char>& vec, char ch) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == ch) {
            return true;
        }
    }
    return false;
}

int main() {
    // List of words: months and weekdays
    vector<string> wordList = {
        "january", "february", "march", "april", "may", "june", "july",
        "august", "september", "october", "november", "december",
        "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"
    };

    cout << "Welcome to Hangman!\n";

    // Let the player choose the word index
    cout << "\nChoose a number between 0 and " << wordList.size() - 1 << ": ";
    int index;
    cin >> index;

    if (index < 0 || index >= static_cast<int>(wordList.size())) {
        cout << "Invalid choice! Exiting game.\n";
        return 0;
    }

    string secretWord = wordList[index]; // The chosen word
    string secretWord = wordList[index]; // The chosen word
    string guessedWord(secretWord.size(), '_'); // Initialize guessed word with underscores
    int remainingAttempts = 6; // Number of attempts
    vector<char> wrongGuesses; // To keep track of wrong guesses

    while (remainingAttempts > 0 && !isWordGuessed(guessedWord)) {
        cout << "\nCurrent word: ";
        displayWord(guessedWord);
        cout << "Wrong guesses: ";
        for (int j = 0; j < wrongGuesses.size(); j++) {
            cout << wrongGuesses[j] << " ";
        }
        cout << "\nRemaining attempts: " << remainingAttempts << endl;

        cout << "Enter a letter: ";
        char guess;
        cin >> guess;

        // Check if the guessed letter is in the word
        bool correctGuess = false;
        for (int i = 0; i < secretWord.size(); i++) {
            if (secretWord[i] == guess && guessedWord[i] == '_') {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }

        if (!correctGuess) {
            // Check manually if the letter was already guessed
            if (!isInVector(wrongGuesses, guess)) {
                wrongGuesses.push_back(guess);
                remainingAttempts--;
                cout << "Wrong guess!" << endl;
            }
            else {
                cout << "You already guessed that letter!\n";
            }
        }
        else {
            cout << "Correct guess!" << endl;
        }
    }

    if (isWordGuessed(guessedWord)) {
        cout << "\nCongratulations! You guessed the word: " << secretWord << endl;
    }
    else {
        cout << "\nYou ran out of attempts! The word was: " << secretWord << endl;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
