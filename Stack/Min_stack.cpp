#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
public:
    stack<long long int> s;
    long long int minVal;

    MinStack() {
        minVal = LLONG_MAX;
    }

    void push(int val) {
        if (s.empty()) {
            s.push(val);
            minVal = val;
        } else {
            if (val < minVal) {
                s.push(2LL * val - minVal);
                minVal = val;
            } else {
                s.push(val);
            }
        }
    }

    void pop() {
        if (s.empty()) return;

        if (s.top() < minVal) {
            minVal = 2 * minVal - s.top();
        }
        s.pop();
    }

    int top() {
        if (s.empty()) return -1;

        if (s.top() < minVal) {
            return minVal;
        }
        return s.top();
    }

    int getMin() {
        return s.empty() ? -1 : minVal;
    }
};

int main() {
    MinStack minStack;

    minStack.push(5);
    cout << "Pushed 5 -> Min: " << minStack.getMin() << endl;

    minStack.push(3);
    cout << "Pushed 3 -> Min: " << minStack.getMin() << endl;

    minStack.push(7);
    cout << "Pushed 7 -> Min: " << minStack.getMin() << endl;

    cout << "Top: " << minStack.top() << endl;

    minStack.pop();
    cout << "After pop -> Min: " << minStack.getMin() << endl;

    minStack.pop();
    cout << "After pop -> Min: " << minStack.getMin() << endl;

    cout << "Top: " << minStack.top() << endl;

    return 0;
}
