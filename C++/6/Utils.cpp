using namespace std;

#include "Utils.h"

#include <iostream>
#include <iomanip>

void Utils::shortestWord(string text) {
    string tmpWord = "";
    // The upper bound of answer is text
    string minWord = text;

    for (int i = 0; i < (int) text.length(); i++) {
        /// If founded space, rewrite word
        if (text[i] != ' ') {
            tmpWord += text[i];
        } else {
            // We got a new word, try to update answer
            if (tmpWord.length() < minWord.length())
                minWord = tmpWord;
            tmpWord = "";
        }

    }
    // Check the last word
    if (tmpWord != "") {
        if (tmpWord.length() < minWord.length())
            minWord = tmpWord;
    }
    cout << "Shortest Word: " << minWord << endl;
    cout << "Word Length: " << minWord.length() << endl;
}
