// repeatedly swapping the adjecent elements if they are in wrong order
#include<iostream>
using namespace std;

void BubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    int n=5;
    int arr[] = {4,1,5,2,3};
    BubbleSort(arr, n);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

return 0;

}