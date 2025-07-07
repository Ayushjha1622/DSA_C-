#include <iostream>
#include <string>
using namespace std;

bool repeatedSubstringPattern(string s) {
    int n = s.length();

    // Try all possible substring lengths from 1 to n/2
    for (int len = 1; len <= n / 2; len++) {
        if (n % len == 0) {  // substring must evenly divide the string
            string sub = s.substr(0, len);
            string repeated = "";
            
            // Repeat the substring enough times
            for (int i = 0; i < n / len; i++) {
                repeated += sub;
            }

            if (repeated == s) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    cout << boolalpha;
    cout << repeatedSubstringPattern("abab") << endl;        // true
    cout << repeatedSubstringPattern("aba") << endl;         // false
    cout << repeatedSubstringPattern("abcabcabcabc") << endl;// true
    return 0;
}

