#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        int i = 0;
        for(int j = 1;j< nums.size();++j){
            if(nums[i] != nums[j]){
                ++i;
                nums[i] = nums[j];
            }
        }
        return ++i;
    }
};

int main(){
    int arr[] = {0,0,1,1,1,2,2,3,3,4};
    vector<int> v1(arr,arr+sizeof(arr)/sizeof(int));
    vector<int> v{0,0,1,1,1,2,2,3,3,4};
    Solution().removeDuplicates(v1);
    vector<int>:: iterator it = v1.begin();
    while(it != v1.end()){
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    Solution().removeDuplicates(v);
    for(auto e : v){
        cout << e << " ";
    }
    cout << endl;

    return 0;
}