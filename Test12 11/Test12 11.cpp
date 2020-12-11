#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto &e : tokens){
            if(e == "+" || e == "-" || e == "*" || e == "/"){
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                switch(e[0]){
                    case '+':
                    st.push(right+left);
                    break;
                    case '-':
                    st.push(left-right);
                    break;
                    case '/':
                    st.push(left/right);
                    break;
                    case '*':
                    st.push(left*right);
                    break;
                    default:
                    exit(-1);
                    break;
                    
                } 
            }
            else{
                st.push(stoi(e));
            }
        }
        return st.top();

    }
};
int main(){

    vector<string> v{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    int ret = Solution().evalRPN(v);

    cout << ret <<endl;
    return 0;
}