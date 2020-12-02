#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size()-1,len2 = num2.size()-1;
        int add = 0;
        string ret;
        while(len1 >= 0 || len2 >= 0 || add != 0){
            int x = len1 >= 0 ? num1[len1] - '0' : 0;
            int y = len2 >= 0 ? num2[len2] - '0' : 0;
            int result  = x + y +add;
            ret.insert(ret.begin(),result%10 + '0');
            add = result/10; 
            len1--;
            len2--;
        }
        return ret;
    }
};


int main(){
    string num1("12345");
    string num2("54321");
    string num = Solution().addStrings(num1,num2);
    cout << num << endl;
    
    return 0;
}