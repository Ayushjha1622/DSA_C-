//  it is a linera data structure where each element known as node
// node consist data i.e. integer, string etc and a pointer or reference variable to the next node


#include<iostream>
using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;

//     Node(int val) {
//         data = val;
//         next = NULL;
//     }
// };

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};


// class List {
//     Node* head;
//     Node* tail;

// public:
//     List() {
//         head = tail = NULL;
//     }


class List{
    Node* head;
    Node* tail;

    public:
    List(){
        head =tail= NULL;
    }


    // void push_front(int val) {
    //     Node* newNode = new Node(val);
    //     if (head == NULL) {
    //         head = tail = newNode;
    //     } else {
    //         newNode->next = head;
    //         head = newNode;
    //     }
    // }


    void push_front(int val){
        Node * newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
        } else {
            newNode -> next = head;
            head = newNode;
        }
    }

    // void push_back(int val) {
    //     Node* newNode = new Node(val);
    //     if (head == NULL) {
    //         head = tail = newNode;
    //     } else {
    //         tail->next = newNode;
    //         tail = newNode;
    //     }
    // }


    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        } else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    // void pop_front() {
    //     if (head == NULL) {
    //         cout << "LL is empty\n";
    //         return;
    //     }
    //     Node* temp = head;
    //     head = head->next;
    //     delete temp;

    //     if (head == NULL) {
    //         tail = NULL;
    //     }
    // }


    void pop_front(){
        if(head==NULL){
            cout << "LL is empty\n";
        } 
        Node* temp = head;
        head = head-> next;
        delete temp;

        if(head == NULL){
            tail = NULL;
        }
    }

    void pop_back() {
        if (head == NULL) {
            cout << "LL is empty\n";
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void printLL() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }


    void insert(int val, int pos){
        if(pos < 0){
            cout << "invalid pos/n";
            return;
        }

        if(pos ==0){
            push_front(val);
            return;
        }

        Node* temp = head;
        for(int i=0; i<pos-1; i++){
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp-> next;
        temp->next = newNode;


    }
};

int main() {
    List ll;
    ll.push_front(1);  // List: 1
    ll.push_front(2);  // List: 2 -> 1
    ll.push_front(3);  // List: 3 -> 2 -> 1

    ll.insert(4,0);

    ll.pop_front();    // Remove 3 -> List: 2 -> 1
    ll.pop_back();     // Remove 1 -> List: 2

    ll.push_back(4);   // List: 2 -> 4
    ll.printLL();      // Output: 2 -> 4 -> NULL

    return 0;
}
