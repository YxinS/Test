#include<iostream>
void swap(int* a,int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void moveZeroes(int* nums, int numsSize){
    int pos = 0;
    for(int i =0 ; i< numsSize;i++){
        if(nums[i] != 0){
            swap(&nums[pos],&nums[i]);
            pos++;
        }
    
    }

}
int main(){
    int nums[] = {0,1,0,3,12};
    moveZeroes(nums,5);
    for(int i = 0;i < 5;i++){
        std::cout << nums[i] <<" ";
    }

    return 0;
}