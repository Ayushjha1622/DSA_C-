#include<iostream>
#include<vector>
using namespace std;


void moveZeroes(vector<int> &nums){
    int n = nums.size();
    int j=0;

    for(int i=0; i<n; i++){
        if(nums[i] != 0){
            nums[j] = nums[i];
        }
    }


    for(int i=j; i<n; i++){
        nums[i] = 0;
    }
}

int main(){

    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);

    for(int num: nums){
        cout << num << " ";
    }

return 0;

}