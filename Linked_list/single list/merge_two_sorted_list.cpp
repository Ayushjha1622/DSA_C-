#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Recursive function to merge two sorted lists
ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
    if (head1 == NULL || head2 == NULL) {
        return head1 == NULL ? head2 : head1;
    }

    if (head1->val <= head2->val) {
        head1->next = mergeTwoLists(head1->next, head2);
        return head1;
    } else {
        head2->next = mergeTwoLists(head1, head2->next);
        return head2;
    }
}

// Helper function to insert node at end
void insertAtTail(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == NULL) {
        head = newNode;
        return;
    }

    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Helper function to print the list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // Creating first sorted list: 1 -> 3 -> 5
    ListNode* list1 = NULL;
    insertAtTail(list1, 1);
    insertAtTail(list1, 3);
    insertAtTail(list1, 5);

    // Creating second sorted list: 2 -> 4 -> 6
    ListNode* list2 = NULL;
    insertAtTail(list2, 2);
    insertAtTail(list2, 4);
    insertAtTail(list2, 6);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    // Merge and print result
    ListNode* merged = mergeTwoLists(list1, list2);
    cout << "Merged List: ";
    printList(merged);

    return 0;
}
