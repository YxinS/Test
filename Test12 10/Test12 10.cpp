#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int s1=0,s2=0,s3=0;
        vector<int>::iterator it = bills.begin();
        while(it != bills.end()){
            if(*it == 5)++s1;
            else if(*it == 10){
                --s1;
                if(s1 <0 || s2<0)return false;
                ++s2;
            }
            else{
                if(s2 >= 1 && s1 >=1){
                    s1-=1;
                    s2-=1;
                    if(s1 <0 || s2<0)return false;
                    ++s3;
                }
                else if(s1 >= 3){
                    s1-=3;
                    if(s1 <0 || s2<0)return false;
                    ++s3;
                }
                else{
                    return false;
                }
            }
            
            ++it;
        }
        return true;
    }
};


int main(){
    vector<int> v{5,5,10,10,20};
    bool ret = Solution().lemonadeChange(v);
    cout << ret << endl;
    vector<int> v1{5,5,5,10,20};
    ret = Solution().lemonadeChange(v1);
    cout << ret << endl;


    return 0;
}