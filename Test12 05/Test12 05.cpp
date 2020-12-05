#include<iostream>
using namespace std;
#include<string>
class Solution {
public:
    char firstUniqChar(string s) {
        if(s.empty())return ' ';
        if(s.size() == 1)return s[0];
        int arr[26] = {0};
        for(int i = 0;i<s.size();i++){
            arr[s[i] - 'a']++; 
        }
        for( auto c : s)
        {
            if(arr[c-'a'] == 1)  
            return c;
        }
        // for(int i = 0; i< s.size();i++){
        //     if(arr[s[i] - '`'] == 1){
        //         return s[i];
        //     }
        // }
        return ' ';

    }
};


int main(){
    string arr("abaccdeff");
    char a = Solution().firstUniqChar(arr);
    cout << a << endl;

    return 0;
}