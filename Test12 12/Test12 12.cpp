#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1)return nums.size();
        int sum = 1;
        int val = 2;
        for(int i = 1; i< nums.size();++i){
            if(nums[i] != nums[i-1]){
                sum+=nums[i] > nums[i-1] != val;
                val = nums[i] > nums[i-1];
            }
        } 
        return sum;
    }
};

int main(){
    vector<int> vr{1,17,5,10,13,15,10,5,16,8};
    int a = Solution().wiggleMaxLength(vr);
    cout << a << endl;


    return 0;
}