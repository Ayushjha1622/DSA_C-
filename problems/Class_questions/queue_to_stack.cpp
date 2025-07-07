#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
    stack<int> pushStack;
    stack<int> popStack;

    // Helper to transfer elements from pushStack to popStack
    void transfer() {
        while (!pushStack.empty()) {
            popStack.push(pushStack.top());
            pushStack.pop();
        }
    }

public:
    // Enqueue: O(1)
    void enqueue(int x) {
        pushStack.push(x);
    }

    // Dequeue: O(n) worst-case
    void dequeue() {
        if (popStack.empty()) {
            transfer();
        }
        if (!popStack.empty()) {
            popStack.pop();
        } else {
            cout << "Queue is empty\n";
        }
    }

    // Peek: O(n) worst-case
    int peek() {
        if (popStack.empty()) {
            transfer();
        }
        if (!popStack.empty()) {
            return popStack.top();
        } else {
            cout << "Queue is empty\n";
            return -1;
        }
    }

    // Check if queue is empty
    bool isEmpty() {
        return pushStack.empty() && popStack.empty();
    }
};

int main() {
    QueueUsingStacks q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.peek() << endl; // 10
    q.dequeue();

    cout << "Front: " << q.peek() << endl; // 20
    q.dequeue();

    q.enqueue(40);
    cout << "Front: " << q.peek() << endl; // 30
    q.dequeue();
    q.dequeue(); // Removes 40

    q.dequeue(); // Should print "Queue is empty"

    return 0;
}
