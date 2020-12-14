#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)return 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vr(row,vector<int>(col,0));
        //vector<vector<int> > dp(rows, vector<int>(columns, 0));
        for(int i = 0; i< row;++i){
            for(int j= 0;j < col;++j){
                int left = 0,up = 0;
                if(i >0){up = vr[i-1][j];}
                if(j >0){left = vr[i][j-1];}
                vr[i][j] = max(left,up)+grid[i][j];
            }
        }
        return vr[row-1][col-1];
    }
};

int main(){

    vector<vector<int>> vr{{1,3,1},{1,5,1},{4,2,1}};
    int ret = Solution().maxValue(vr);
    cout << ret << endl;


    return 0;
}