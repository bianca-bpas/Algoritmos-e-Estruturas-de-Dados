// Exercise 2
#include <iostream>
#include <string>
using namespace std;

int main(){
    string word;
    do {
        cout << "Enter a word to check if it's a palindrome (or 'exit' to quit): ";
        cin >> word;

        if (word == "exit") break;

        bool isPalindrome = true;
        for (size_t i = 0; i < word.length() / 2; ++i) {
            if (word[i] != word[word.length() - 1 - i]) {
                isPalindrome = false;
                break;
            }
        }

        if (isPalindrome) {
            cout << word << " is a palindrome.\n";
        } else {
            cout << word << " is not a palindrome.\n";
        }
    } while (true);

    return 0;
}