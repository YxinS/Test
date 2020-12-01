#include<stdio.h>
#include<stdlib.h>
int* searchRange(int* nums, int numsSize, int target/*, int* returnSize*/){
    int* arr = (int*)malloc(sizeof(int)*2);
    //*returnSize = 2;
    arr[0] = -1,arr[1] = -1;
    if(numsSize == 0){
        return arr;
    }
    int* ret = (int*)malloc(sizeof(int)*2);
    
    for(int i = 0;i< numsSize;i++){
        if(nums[i] == target){
            ret[0] = i;
            break;
        }
        else{
            ret[0] = -1;
        }

    }
    for(int i = numsSize-1;i>=0;i--){
        if(nums[i] ==target){
            ret[1] = i;
            break;
        }
        else{
            ret[1] = -1;
        }
    }
    
    return ret;
}



int main(){
    int nums[] = {5,7,7,8,8,10}; 
    int* ret = searchRange(nums,6,8);
    printf("%d %d",ret[0],ret[1]);

    return 0;
}