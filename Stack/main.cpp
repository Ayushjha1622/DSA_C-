#include<iostream>
#include<vector>
#include <list>
#include<stack>

using namespace std;

// class Stack{
//     // vector<int> v;
//     list<int> ll;

// public:
//     void push(int val){
//         ll.push_front(val);
//     }



//   void pop(){
//         ll.pop_front();
//     }

//     int top(){
//         return ll.front();

//     }

//     bool empty(){
//         return ll.size() == 0;
//     }
// };

int main(){

    // Stack s;
    // s.push(1);
    // s.push(2);
    // s.push(3);

    // while(!s.empty()) {
    //     cout << s.top() << " ";
    //     s.pop();
    // }

    // cout << endl;

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

return 0;
}

