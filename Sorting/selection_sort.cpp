// // it repeatedly finding the smallest(asc) or largest (desc) element from the unsorted part of array and swapping with first unsorted element till array is sorted.

// //  suitable for when minimum number of swap required 


// #include<iostream>
// #include <vector>
// using namespace std;

// void selectionSort(vector<int> &arr){
//     int n = arr.size();

//     for(int i=0; i< n-1; i++){
//         int minIndex = i;

//         for(int j=i+1; j<n; j++){
//             if(arr[j] < arr[minIndex]){
//                 minIndex = j;
//             }
//         }

//         swap(arr[i], arr[minIndex]);
//     }
// }

// int main(){

//     vector<int> arr = {29,10,14,37,13};
//     selectionSort(arr);

//     for(int val: arr){
//         cout<<val<<" ";
//     }

// return 0;

// }



#include<iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0; i< n-1; i++){
        int minIndex =i;

        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
            minIndex = j;
        }
    }

    swap(arr[i], arr[minIndex]);
    }
}

int main(){

    int n = 5;
    int arr[] = {4,8,2,3,6};
    selectionSort(arr, n);


    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
return 0;

}