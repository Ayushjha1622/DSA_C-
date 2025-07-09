#include<iostream>
#include<vector>
using namespace std;

// Min-heapify function for 0-based index heap
void heapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if(right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    if(smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

// Build Min Heap from an unsorted array
vector<int> buildMinHeap(vector<int>& arr) {
    int n = arr.size();
    for(int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    return arr;
}

// Driver code
int main() {
    vector<int> arr = {50, 55, 53, 52, 54};

    vector<int> minHeap = buildMinHeap(arr);

    cout << "Min Heap: ";
    for(int i : minHeap) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
