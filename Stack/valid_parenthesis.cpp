#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for(char c : s) {
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if(st.empty()) return false;

            char top = st.top();
            if((c == ')' && top == '(') || 
               (c == '}' && top == '{') || 
               (c == ']' && top == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    string s = "({[]})";
    if(isValid(s)) {
        cout << "Valid Parentheses";
    } else {
        cout << "Invalid Parentheses";
    }
    return 0;
}
