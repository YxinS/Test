#include<stdio.h>
#include<iostream>
#include<stdlib.h>
int countGoodTriplets(int* arr, int arrSize, int a, int b, int c){
    int ret = 0;
    for(int i = 0;i<arrSize;++i){
        for(int j = i+1;j<arrSize;j++){
            for(int k = j+1;k<arrSize;k++){
                if(abs(arr[i]-arr[j]) <=a&&abs(arr[j]-arr[k]) <=b&&abs(arr[i]-arr[k])<=c){
                    ret++;
                }
            }
        }
    }
    return ret;
}


int main(){
    int arr[] = {3,0,1,1,9,7};
    int ret = countGoodTriplets(arr,6,7,2,3);
    std::cout << ret << std::endl;

    return 0;
}