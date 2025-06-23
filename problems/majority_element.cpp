#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int majorityElement(vector<int> &nums){
    int n = nums.size();
//     // sort

//     sort(nums.begin(), nums.end());


//     //  freq count
//     int freq = 1, ans = nums[0];
//     for(int i=1; i<n; i++){
//         if(nums[i] == nums[i-1]){
//             freq++;
//         } else {
//             freq = 1;
//             ans = nums[i];
//         }

//         if(freq > n/2){
//             return ans;
//         }
//     }
   
//     return ans;


    int freq =0; int ans =0;
    for(int i=0; i<n; i++){
        if(freq =0){
            ans = nums[i];
        }
        if(ans == nums[i]){
            freq++;
        } else{
            freq--;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {1,1,1,2,2,2,5,5,5,5,5,5};
    int result = majorityElement(nums);
    cout << result << endl;

return 0;

}