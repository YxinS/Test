#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        for(auto &e:words){
            m[e]++;
        }
        multimap<int,string,greater<>> mp;
        for(auto &e:m){
            mp.insert(make_pair(e.second,e.first));
        }
        vector<string> v;
        for(auto &e:mp){
            if(k==0){
                break;
            }
            v.push_back(e.second);
            --k;
        }
        // auto it = mp.begin();
        // while(it != mp.end()){
        //     if(k == 0){
        //         break;
        //     }
        //     v.push_back(it->second);
        //     --k;
        //     ++it;
        // }
        return v;
    }
};



int main(){
    vector<string> v{"i", "love", "leetcode", "i", "love", "coding"};
    vector<string> vs = Solution().topKFrequent(v,2);
    auto it = vs.begin();
    while(it != vs.end()){
        cout << *it <<" ";
        ++it;
    }
    cout << endl;





    return 0;
}