#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size()==0)return 0;
        for(int i = 1;i<array.size();++i){
            if(array[i] <= 0&& array[i-1] >= 0){
                array[i]+=array[i-1];
            }
            else{
                array[i] = max(array[i],array[i]+array[i-1]); 
            }
        }
        int Max = array[0];
        for(int i = 0;i < array.size();++i){
            if(array[i] > Max){
                Max = array[i];
            }
        }
        return Max;
    }
    
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==0)return false;
        sort(nums.begin(),nums.end());
        for(int i= 0;i < nums.size()-1;++i){
            if(nums[i] == nums[i+1]){
                return true;
            }
        }
        return false;

    }
};
int main(){

    vector<int> ar{1,1,1,3,3,4,3,2,4,2};
    int a = Solution().FindGreatestSumOfSubArray(ar);
    int b = Solution().containsDuplicate(ar);
    cout << a << "  " << b << endl;


    return 0;
}

