#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a,const void* b){
    return *(int*)a - *(int*)b;
}
int maximumGap(int* nums, int numsSize){
    qsort(nums,numsSize,sizeof(int),cmp);
    int max = 0;
    for(int i = 1;i < numsSize;i++){
        if((nums[i] - nums[i-1]) > max){
            max = nums[i] - nums[i-1];
        }
    }
    return max;
}

int main(){

    int a[] = {3,6,9,1};
    int max = maximumGap(a,4);
    printf("%d\n",max);


    return 0;
}