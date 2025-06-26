#include <iostream>
using namespace std;

// Definition for a Node
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = NULL;
        next = NULL;
        child = NULL;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) {
            return head;
        }

        Node* curr = head;

        while (curr != NULL) {
            if (curr->child != NULL) {
                // Save the next node
                Node* next = curr->next;

                // Flatten the child list
                Node* childHead = flatten(curr->child);

                // Attach child list
                curr->next = childHead;
                childHead->prev = curr;
                curr->child = NULL;

                // Move to the tail of the child list
                Node* tail = childHead;
                while (tail->next != NULL) {
                    tail = tail->next;
                }

                // Reconnect with the next node
                if (next != NULL) {
                    tail->next = next;
                    next->prev = tail;
                }

                // Move curr to the tail
                curr = tail;
            }

            curr = curr->next;
        }

        return head;
    }
};

// Helper function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Sample multilevel list:
// 1 - 2 - 3 - 4 - 5
//         |
//         6 - 7
int main() {
    // Main list
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;

    // Child list for node 3
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    n6->next = n7; n7->prev = n6;
    n3->child = n6;

    Solution sol;
    Node* flatHead = sol.flatten(n1);

    cout << "Flattened list: ";
    printList(flatHead);

    return 0;
}
