#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

bool detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return true;  // Cycle detected
    }

    return false;  // No cycle
}

// Helper to create a cycle for testing
void createCycle(Node* head, int pos) {
    Node* temp = head;
    Node* startNode;

    int count = 1;
    while(temp->next != NULL) {
        if(count == pos) startNode = temp;
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    createCycle(head, 2); // Creates a cycle at node 2

    if(detectCycle(head))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";

    return 0;
}
