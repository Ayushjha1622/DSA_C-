// void reverse() {
//         Node* prev = NULL;
//         Node* curr = head;
//         Node* next = NULL;
//         tail = head;

//         while (curr != NULL) {
//             next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }

//         head = prev;
//     }