#include<iostream>
using namespace std;


class Solution {
public:
    bool isPrime(int num){
        for(int i = 2; i*i <= num;++i){
            if(num%i == 0){
                return false;
            }
        }
        return true;
    }
    
    int countPrimes(int n) {
        
        int ret = 0;
        for(int i = 2 ;i < n;i++){
            ret += isPrime(i);
        }
        return ret;
    }

    int reverse(int x) {
        int num = 0;
        while(x){
            int pop = x%10;
            x/=10;
            if(num > INT_MAX/10 || (num == INT_MAX/10&& pop > 7))return 0;
            if(num < INT_MIN/10 || (num == INT_MIN/10&& pop < -8))return 0;
            num*=10;
            num+=pop;
            
        }
        return num;
    }
};

int main(){

    int prime = Solution().countPrimes(10);
    cout << prime << endl;
    int re1 = Solution().reverse(12345);
    int re2 = Solution().reverse(-3243);
    cout << re1<< endl;
    cout << re2 << endl;







    return 0;
}