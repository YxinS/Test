#include<iostream>

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x == 1)return 1;
        if(x == 0)return 0;
        double num = 1;
        long ret = n;
        if(ret < 0){
            x = 1/x;
            ret = -ret;
        }
        while(ret){
            if(ret & 1){
                num*=x;
            }
            x *= x;
            ret >>=1;
        }
        return num;
        // if(x == 0)return 0;
        // if(n == 0 || x == 1)return 1;
        // double num = 1;
        // if(n > 0){
        //     while(n){
        //         num *= x;
        //         --n;
        //     }
        // }
        // else{
        //     n = -n;
        //     while(n){
        //         num*=x;
        //         --n;
        //     }
        //     num = 1/num;
        // }
        // return num;
    }
};


int main(){
    double a = 2.10000;
    int b =  3;
    double c =  2.00000;
    int d =  -2;
    double e =  Solution().myPow(a,b);
    double f =  Solution().myPow(c,d);
    std::cout << e << "   " << f << std::endl;






    return 0;
}