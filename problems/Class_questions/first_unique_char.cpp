#include<iostream>
#include<unordered_map>
using namespace std;


char unique(const string &str){
    unordered_map<char, int>freq;

    for(char ch: str){
        freq[ch]++;
    }

    for(char ch: str){
        if(freq[ch] == 1){
            return ch;
        }
    }

    return -1;
}

int main(){
string input = "swiss";
char result = unique(input);

if(result != -1){
    cout << result << endl;

} else{
    cout << "-1" << endl;
}

return 0;

}