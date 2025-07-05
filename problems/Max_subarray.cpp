// #include<iostream>
// #include<vector>
// #include <climits>
// using namespace std;

// int main(){
//     int n = 5;
//     int arr[5] = {1,2,3,4,5};

//     int MaxSum = INT_MIN;

//     for(int st=0; st < n; st++){
//         int currSum =0;
//         for(int end = st; end<n; end++){
//             currSum += arr[end];
//             MaxSum = max(currSum, MaxSum);
//             cout<<" ";
//         }
//     }
//     cout<< "max subarray sum = " << MaxSum << endl;
// return 0;

// }



// KADANE ALGO

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// int maxSubArray(vector<int> &nums){
//     int currSum = 0; int maxSum = INT_MIN;

//     for(int val: nums){
//         currSum += val;
//         maxSum = max(currSum, maxSum);

//         if(currSum < 0){
//             currSum = 0;
//         }
//     }

//     return maxSum;
// }


int maxSubArray(vector<int> &nums){
    int currSum =0; int maxSum = INT_MIN;

    for(int val: nums){
        currSum += val;
        maxSum = max(currSum, maxSum);

        if(currSum < 0){
            currSum =0;
        }
    }

    return maxSum;
}

int main(){

    vector<int> nums = {-2,-3,4,-1,-2,1,5,-3};
    int result = maxSubArray(nums);
    cout << result << endl;



   

return 0;

}

