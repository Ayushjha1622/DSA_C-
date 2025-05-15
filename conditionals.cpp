#include<iostream>
using namespace std;

int main(){
    // int n;
    // cout<<"value of n is: "<<endl;
    // cin>>n;
    // if (n>5){
    //     cout<<"greater";

    // }
    // else{
    //     cout<<"smaller";
    // }





    char ch;
    cout<<"Enter a character: ";
    cin>> ch;

    if (ch >= 'a' && ch <= 'z'){
        cout<<"This is lowercase"<<endl;
    }
    
    else if (ch >= 'A' && ch <= 'Z'){
        cout<<"This is uppercase"<<endl;
    }

    else if (ch >= '0' && ch <= '9'){
        cout<<"This is numeric";
    }

    else{

        cout<<"special character";
    }

    return 0;

}