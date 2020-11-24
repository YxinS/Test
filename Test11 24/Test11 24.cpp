#include<iostream>
#include<string>
#include <algorithm>


class Solution {
public:
    std::string addStrings(std::string num1, std::string num2) {
        int i = num1.size()-1, j = num2.size()-1, add = 0;
        std::string ans = "";
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x + y + add;
            ans+=('0' + result % 10);
            add = result / 10;
            i -= 1;
            j -= 1;
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){

    std::string s1("1222222222");
    std::string s2("222222222233333333");
    Solution S;
    std::string s3 = S.addStrings(s1,s2);
    std::cout << s3 << std::endl;





    return 0;
}