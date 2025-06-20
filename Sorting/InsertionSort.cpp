// it builds the sorted array by single element at a time

// it takes new element and insert it into correct position in the already sorted part of array

#include<iostream>
using namespace std;


void InsertionSort(int arr[], int n){
    for(int i=0; i<n;i++){
        int curr = arr[i];
        int prev = i-1;

        while(prev >=0 && arr[prev] > curr){
            arr[prev+1] = arr[prev];
            prev--;
        }

        arr[prev+1] = curr;
    }
}
int main(){

    int n =5;
    int arr[] = {2,3,9,7,8};
    InsertionSort(arr, n);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

return 0;

}