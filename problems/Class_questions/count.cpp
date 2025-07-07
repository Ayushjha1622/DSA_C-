#include<iostream>
#include<string>
#include<cctype>
using namespace std;

void count(const string &str){
    int v =0;
    int c =0; 
    int d =0;
    int s = 0;

    for (char ch: str){
        if(isalpha(ch)){
            char lower = tolower(ch);
            if(lower== 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower =='u'){
                v++;
            } else{
                c++;
            }
        } else if(isdigit(ch)){
            d++;
        } else {
            s++;
        }
    } 

    cout << "v: " << v <<endl;
    cout << "c: " << c <<endl;
    cout << "d: " << d <<endl;
    cout << "s: " << s <<endl;


}

int main(){
    string input = "hello@123";
    count(input);
return 0;

}