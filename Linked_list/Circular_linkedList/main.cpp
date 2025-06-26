#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;


    Node(int val){
        data = val;
        next = NULL;

    }

};


class CircularList{
    Node* head;
    Node* tail;

public:
    CircularList(){ 
        head = tail = NULL;
}

    void insertAtHead(int val){
        Node* newNode = new Node(val);

        if(tail == NULL){
            
        }
    }
};

int main(){

return 0;

}