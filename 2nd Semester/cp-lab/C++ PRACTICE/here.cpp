#include <iostream>
#include <string>
using namespace std;

int main() {
    string word, longestWord = "";
    
    cout << "Enter a sequence of words: " << endl;
    
    while (cin >> word) {
        if (word.length() > longestWord.length()) {
            longestWord = word;
        }
    }
    
    cout << "The longest word in the sequence is: " << longestWord << endl;
    
    return 0;
}

