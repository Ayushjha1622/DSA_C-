#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){

    unordered_map<string, int> m;

    pair<string, int> p = make_pair("babbar",3);
    m.insert(p);

    pair<string, int> pair2("love", 2);
    m.insert(pair2);

    m["mera"] = 1;
    m["mera"] = 2;


    cout << m["mera"] << endl;
    cout << m.at("babbar") << endl;
    cout << m.at("unknown") << endl;
    cout << m["unknown"] << endl;

    m.erase("love");
    cout << m.size() << endl;

   unordered_map<string,int> :: iterator it = m.begin();
   while(it != m.end()){
    cout << it->first << " " << it->second << endl;
    it++;
   }
   
return 0;
 
}