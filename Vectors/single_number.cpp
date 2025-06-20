#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int> &nums){
    int ans = 0;

    for(int n: nums){
        ans = ans ^ n;
    }
    return ans;


}

int main(){
    vector<int> nums = {3,1,4,4,1};
    int result = singleNumber(nums);

    cout<<"single number: "<< result << endl;

return 0;

}