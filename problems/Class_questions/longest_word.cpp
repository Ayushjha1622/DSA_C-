#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string findLargestWord(const string& sentence) {
    stringstream ss(sentence);
    string word, longestWord;
    int maxLength = 0;

    while (ss >> word) {
        if (word.length() > maxLength) {
            maxLength = word.length();
            longestWord = word;
        }
    }

    return longestWord;
}

int main() {
    string input = "I love competitive programming";
    string result = findLargestWord(input);
    cout << "Output: \"" << result << "\"" << endl;
    return 0;
}
