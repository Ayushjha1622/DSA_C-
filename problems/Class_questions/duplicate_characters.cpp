#include<iostream>
#include<string>
using namespace std;

void duplicate(const string &str){
    int f[256] ={0};

    for(char ch: str){
        if(ch != ' '){
            ch= tolower(ch);
            f[(int)ch]++;
        }
    }

    for(int i=0; i<256; i++){
        if(f[i] > 1){
            cout << (char)i << " : " << f[i] << endl;
        }
    }
}

int main(){
    string input = "Programming";
    duplicate(input);

return 0;

}