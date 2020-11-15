#include<stdio.h>
#include<stdlib.h>
int* decompressRLElist(int* nums, int numsSize/*,int* returnSize*/){
    int tmp = 0;
    for(int i = 0; i< numsSize; i++){
        if(i%2 == 0){
            tmp += nums[i];
        }
    }
    //*returnSize = tmp;
    int* arr = (int*)malloc(sizeof(int)*tmp);
    int left = 0,right = 1,len = 0;
    while(right <= numsSize){
        while(nums[left]--){
            arr[len++] = nums[right];
        }
        left+=2;
        right+=2;
    }
    return arr;
}
int main(){
    int ar[] = {1,2,3,4,5,6};//{2,4,4,4,6,6,6,6,6}
    int* a = decompressRLElist(ar,6);
    for(int i = 0;i < 9;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    
    
    return 0;
    system("pause");
}