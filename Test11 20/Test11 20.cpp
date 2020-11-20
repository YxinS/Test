#include<iostream>

bool isStraight(int* nums, int numsSize){
    int arr[14] = {0};
    int max = 0;
    for(int i = 0; i< numsSize;i++){
        if(nums[i] > max){
            max = nums[i];
        }
        arr[nums[i]]++;
    }
    for(int i = 0; i< numsSize;i++,max--){
        if(arr[max]!= 0){
            continue;
        }
        if(arr[0] > 0){
            arr[0]--;
        }
        else{
            return false;
        }
    }
    return true;
}


int main(){
    int nums[] = {1,2,3,4,5};
    int nums1[] = {0,0,1,2,5};
    std::cout << isStraight(nums,sizeof(nums)/sizeof(int)) << std::endl;
    std::cout << isStraight(nums1,sizeof(nums1)/sizeof(int)) << std::endl;



    return 0;
    system("pause");
}