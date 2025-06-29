// #include<iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;

//     Node(int val) {
//         data = val;
//         next = NULL;
//     }
// };

// class Queue {
//     Node* head;
//     Node* tail;

// public:
//     Queue() {
//         head = tail = NULL;
//     }

//     void push(int data) {
//         Node* newNode = new Node(data);

//         if (empty()) {
//             head = tail = newNode;  //  Correct initialization when queue is empty
//         } else {
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }

//     void pop() {
//         if (empty()) {
//             cout << "LL is EMPTY\n";
//             return;
//         }

//         Node* temp = head;
//         head = head->next;
//         delete temp;

//         if (head == NULL) tail = NULL;  //  Reset tail if the queue is now empty
//     }

//     int front() {
//         if (empty()) {
//             cout << "LL is EMPTY\n";
//             return -1;
//         }

//         return head->data;
//     }

//     bool empty() {
//         return head == NULL;  //  Corrected comparison
//     }
// };

// int main() {
//     Queue q;
//     q.push(1);
//     q.push(2);
//     q.push(3);

//     while (!q.empty()) {
//         cout << q.front() << " ";
//         q.pop();
//     }

//     cout << endl;
//     return 0;
// }


// #include<iostream>
// #include<queue>
// using namespace std;

// int main(){
//     queue<int> q;

//     q.push(1);
//     q.push(2);
//     q.push(3);

//     while (!q.empty()) {
//         cout << q.front() << " ";
//         q.pop();
//     }

//     cout << endl;
//     return 0;

// return 0;

// }


#include<iostream>
#include<deque>
using namespace std;

int main(){

    deque<int> dq;

    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);

    dq.push_front(4);
    
    cout << dq.front() << " " << dq.back() << endl;

    dq.pop_back(); 

    cout << dq.front() << " " << dq.back() << endl;

return 0;

}
