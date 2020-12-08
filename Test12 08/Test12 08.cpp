#include<iostream>
using namespace std;
class Solution {
public:
    string breakPalindrome(string palindrome) {
        size_t len = palindrome.size(),half = len/2;
        if(palindrome.size() < 2)return "";
        for(size_t i = 0; i<half;++i){
            if(palindrome[i] > 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[len-1] = 'b';
        return palindrome;

    }
};


int main(){
    string str("abccba");
    string str1 = Solution().breakPalindrome(str);
    cout << str1 << endl;

    return 0;
}