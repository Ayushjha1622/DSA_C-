#include <iostream>
#include <unordered_map>
using namespace std;

// Node definition
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;

        unordered_map<Node*, Node*> m;

        // Step 1: Clone all nodes and build mapping
        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;
        m[head] = newHead;

        while (oldTemp != NULL) {
            Node* copyNode = new Node(oldTemp->val);
            m[oldTemp] = copyNode;
            newTemp->next = copyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Step 2: Assign random pointers using the map
        oldTemp = head;
        newTemp = newHead;
        while (oldTemp != NULL) {
            newTemp->random = m[oldTemp->random];  // handles NULL automatically
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};

// Helper function to print list with randoms
void printList(Node* head) {
    while (head != NULL) {
        cout << "Val: " << head->val << ", Random: ";
        if (head->random)
            cout << head->random->val;
        else
            cout << "NULL";
        cout << endl;
        head = head->next;
    }
}

int main() {
    // Create nodes
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);

    // Setup next pointers
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Setup random pointers
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    Solution sol;
    Node* copied = sol.copyRandomList(n1);

    cout << "Original List:\n";
    printList(n1);

    cout << "\nCopied List:\n";
    printList(copied);

    return 0;
}
