#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

// int cmp(const void* a,const void* b){
//     return *(char*)a - *(char*)b;
// }
// bool isAnagram(char * s, char * t){
//     int len_s = strlen(s);
//     int len_t = strlen(t);
//     if(len_s != len_t){
//         return false;
//     }
//     qsort(s,len_s,sizeof(char),cmp);
//     qsort(t,len_t,sizeof(char),cmp);
//     return strcmp(s,t) == 0;
// }
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};



int main(){
    Solution so;
    string s = "anagram";
    string t = "nagaram";
    bool a = so.isAnagram(s,t);
    cout << a << endl;
    return 0;
}