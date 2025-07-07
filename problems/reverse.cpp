#include<iostream>
using namespace std;

class Node{
    public:
    string song;
    Node* next;

    Node(string name){
        song = name;
        next = nullptr;
    }
};

Node* reversePlaylist(Node* head){
    Node* prev = nullptr;
    Node* curr = head;

        while(curr != nullptr){
            Node* nextNode = curr->next; 
            curr->next = prev;           
            prev = curr;                 
            curr = nextNode;    
        }

          return prev;      
    }

void printPlaylist(Node* head) {
    while (head != nullptr) {
        cout << head->song << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

   


int main(){

    Node* head = new Node("A");
    head->next = new Node("B");
    head->next->next = new Node("C");
    head->next->next->next = new Node("D");

    cout << "Original Playlist:\n";
    printPlaylist(head);

    head = reversePlaylist(head);

    cout << "\nReversed Playlist:\n";
    printPlaylist(head);

    return 0;
return 0;

}