#include<iostream>
using namespace std;
#include<string>
#include<algorithm>


class Solution{
    public:
    string addStrings(string num1,string num2){
        int len1 = num1.size()-1,len2 = num2.size()-1;
        int add = 0;
        string arr;
        while(len1 >= 0 || len2 >= 0 || add != 0){
            int x= len1 >= 0 ? num1[len1] - '0' : 0;
            int y = len2 >= 0 ? num2[len2] - '0' : 0;
            int result = x + y + add;
            arr += (result%10 + '0');
            add = result/10;
            --len1;
            --len2;
        }
        reverse(arr.begin(),arr.end());
        return arr;

    }
    string Multiply(string num1,string num2){
        if(num1 == "0" || num2 == "0")return "0";
        string arr("0");
        int len1 = num1.size()-1, len2 = num2.size()-1;
        for(int i = len1;i >= 0; i--){
            string cur;
            int add= 0;
            for(int j = len1; j > i; j--){
                cur.push_back(0);
            }
            int y = num2[i] - '0';
            for(int j = len1; j >= 0;j--){
                int x= num1[j] - '0';
                int product = x*y+add;
                cur.push_back(product%10);
                add = product/10;
            }
            while(add != 0){
                cur.push_back(add%10);
                add/=10;
            }
            for(auto& e : cur){
                e += '0';
            }
            reverse(cur.begin(),cur.end());
            arr = addStrings(arr,cur);
        }
        return arr;

    }
};




int main(){
    cout << Solution().addStrings("1234","4321") << endl;;
    cout << Solution().Multiply("123","321") << endl;




    return 0;
}