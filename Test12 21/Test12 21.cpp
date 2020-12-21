#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<unordered_map>
using namespace std;



class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> vs;
        unordered_map<string,int> um;
        istringstream wa(A);
        string w;
        while(wa >> w){
            ++um[w];
        }
        wa.clear();
        istringstream wb(B);
        while(wb >> w){
            ++um[w];
        }
        for(auto &e:um){
            if(e.second == 1){
                vs.push_back(e.first);
            }
        }
        return vs;
    }
};

int main(){

    string s{"this apple is sweet"}; 
    string ss{"this apple is sour"};
    vector<string> sss = Solution().uncommonFromSentences(s,ss);
    auto it = sss.begin();
    while(it != sss.end()){
        cout << *it<< endl;
        ++it;
    }
    cout << endl;

    return 0;
}