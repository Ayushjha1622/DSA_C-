#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Heapify function to maintain Max Heap property
    void heapify(vector<int> &arr, int n, int i) {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right <= n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    // Merge two max heaps and return a new max heap
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
        ans.push_back(-1); // dummy 0th index for 1-based indexing

        // Add both heaps to ans
        for (int val : a) ans.push_back(val);
        for (int val : b) ans.push_back(val);

        int totalSize = ans.size() - 1;

        // Build heap from bottom up
        for (int i = totalSize / 2; i >= 1; i--) {
            heapify(ans, totalSize, i);
        }

        // Return heap skipping dummy index
        return vector<int>(ans.begin() + 1, ans.end());
    }
};

// Helper to print heap
void printHeap(const vector<int>& heap) {
    for (int val : heap)
        cout << val << " ";
    cout << endl;
}

int main() {
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};

    Solution sol;
    vector<int> mergedHeap = sol.mergeHeaps(a, b, a.size(), b.size());

    cout << "Merged Max Heap: ";
    printHeap(mergedHeap);

    return 0;
}
