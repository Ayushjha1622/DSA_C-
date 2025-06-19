#include<iostream>
#include<vector>
using namespace std;


int findLargest(const vector<int> &arr){
    int max = arr[0];
    for(int i=1; i < arr.size(); i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}

int main(){

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << "elements:\n";
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    int max = findLargest(arr);
    cout<< "the largest number is: " << max << endl;

return 0;

}