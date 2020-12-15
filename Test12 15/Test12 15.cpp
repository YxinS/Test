#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        int ret = str.size();
        int len = str.size();
        for(int i = len-1; i > 0;--i){
            if(str[i-1] > str[i]){
                --str[i-1];
                ret = i;
            }
        }
        for(int i = ret;i<len;++i){
            str[i] = '9';
        }
        return stoi(str);
    }
};

int main(){
    int a= 1234;
    int b = 332;
    int c = 5324;
    Solution s;
    cout << s.monotoneIncreasingDigits(a) << endl 
    << s.monotoneIncreasingDigits(b) << endl 
    << s.monotoneIncreasingDigits(c) << endl;

    return 0;
}