#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber2(vector<int>& nums) {
        int ret = 0;
        for(auto e : nums){
            ret ^= e;
        }
        return ret;
    }
    int singleNumber(vector<int>& nums) {
        int arr[32] = {0};
        for(auto e : nums){
            for(size_t i = 0;i < 32;++i){
                if(e & (1 << i)){
                    arr[i]++;
                }
            }
        }
        int val = 0;
        for(size_t i = 0; i< 32;++i){
            if(arr[i]%3 == 1){
                val|=(1 << i);
            }
        }
        return val;
    }
    vector<int> singleNumber1(vector<int>& nums) {
        int val = 0;
        for(auto e : nums){
            val ^= e;
        }
        vector<int> ret;
        int num1 = 0,num2 = 0;
        size_t i = 0;
        for(; i < 32;++i){
            if(val & (1 << i))
                break;
        }
        for(auto e : nums){
            if(e & (1 << i)){
                num1^=e;
            }
            else
                num2^=e;
        
        }
        ret.push_back(num1);
        ret.push_back(num2);
        return ret;
    }
};

int main(){
    vector<int> v;
    vector<int> v1;
    vector<int> v3;
    v3.push_back(2);
    v3.push_back(2);
    v3.push_back(3);
    v3.push_back(4);
    v3.push_back(4);
    v3.push_back(1);
    v3.push_back(1);
    cout << Solution().singleNumber2(v3) << endl;
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    cout << Solution().singleNumber(v) << endl;;
    vector<int> v2 = Solution().singleNumber1(v1);
    for(auto e : v2){
        cout << e << " ";
    }
    cout << endl;

    return 0;
}