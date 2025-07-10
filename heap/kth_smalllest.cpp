#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<int>& arr, int k) {
        // Max heap
        priority_queue<int> pq;

        // Push first k elements
        for (int i = 0; i < k; i++) {
            pq.push(arr[i]);
        }

        // Process remaining elements
        for (int i = k; i < arr.size(); i++) {
            if (arr[i] < pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        // Top of max heap is the kth smallest
        return pq.top();
    }
};

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    Solution sol;
    int result = sol.kthSmallest(arr, k);

    cout << k << "rd smallest element is: " << result << endl;

    return 0;
}
