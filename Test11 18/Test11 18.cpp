#include<iostream>
using namespace std;
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int total = 0;
    int cur = 0;
    int ret = 0;
    for(int i = 0;i< gasSize;i++){
        total += gas[i] - cost[i];
        cur += gas[i] - cost[i];
        if(cur < 0){
            cur = 0;
            ret = i+1;
        }
    }
    return total >= 0 ? ret : -1;
}

int main(){

    int gas[] = {1,2,3,4,5};
    int cost[] = {3,4,5,1,2};
    int ret = canCompleteCircuit(gas,5,cost,5);
    if(ret == -1){
        cout << "不能行驶一周" << endl;
    } 
    else{
        cout << "可以行驶一周" << endl;
    }



    return 0;
}