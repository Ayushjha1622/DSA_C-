#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int kthLargest(vector<int> &arr, int k) {
        vector<int> sumStore;
        int n = arr.size();

        // Generate all subarray sums
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                sumStore.push_back(sum);
            }
        }

        // Sort all subarray sums
        sort(sumStore.begin(), sumStore.end());

        // Return the Kth largest
        return sumStore[sumStore.size() - k];
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3};
    int k = 2;

    cout << "Kth largest subarray sum is: " << sol.kthLargest(arr, k) << endl;
    return 0;
}
