#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a,const void* b){
    return *(int*)a - *(int*)b;
}

int largestPerimeter(int* A, int ASize){
    qsort(A,ASize,sizeof(int),cmp);
    for(int i = ASize-1;i >1;i--){
        if((A[i-2]+A[i-1])>A[i]){
            return A[i-2]+A[i-1]+A[i];
        }
    }
    return 0;
}
int min(int a, int b){
    return a > b?b:a;
}
int nthUglyNumber(int n){
    int *arr = (int*)malloc(sizeof(int)*n);
    arr[0] = 1;
    int a2 = 0,a3 =0,a5 = 0;;
    for(int i  = 1;i<n;i++){
        arr[i] = min(min(arr[a2]*2,arr[a3]*3),arr[a5]*5);
        if(arr[i] == arr[a2]*2){
            a2++;
        }
        if(arr[i]== arr[a3]*3){
            a3++;
        }
        if(arr[i] == arr[a5]*5){
            a5++;
        }
    }
    return arr[n-1];
}
// int* singleNumbers(int* nums, int numsSize){
//     int* arr = (int*)calloc(numsSize,sizeof(int));
//     int* ret = (int*)malloc(sizeof(int)*2);
//     int tmp = 0;
//     for(int i = 0;i <numsSize;i++){
//         arr[nums[i]]++;
//     }
//     for(int i = 0;i<(numsSize/2+1);i++){
//         if(arr[i] == 1){
//             ret[tmp++] = i;
//         }
//     }
//     return ret;
// }

int main(){

    int arr[] ={3,6,2,3};
    int ret = largestPerimeter(arr,4);
    printf("%d\n",ret);
    int tmp = nthUglyNumber(10);
    printf("%d\n",tmp);







    return 0;
}