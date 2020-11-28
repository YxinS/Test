#include<stdio.h>
#include<stdlib.h>

int* sumEvenAfterQueries(int* A, int ASize, int queries[4][2], int queriesSize/*,int* queriesColSize, int* returnSize*/){
    int* arr = (int*)malloc(sizeof(int)*ASize);
    int num = 0;

    for(int i = 0;i<ASize;i++){
        if(A[i]%2 == 0){
            num += A[i];
        }
    }
    for(int i = 0;i<queriesSize;i++){
        int tmp = A[queries[i][1]];
        A[queries[i][1]]+=queries[i][0];
        if(A[queries[i][1]]%2 == 0){
            if(tmp%2==0){
                num+=queries[i][0];
            }
            else
                num+=A[queries[i][1]];
        }
        else if(tmp%2==0){
            num-=tmp;
        }
        arr[i] = num;
    }
    //*returnSize = ASize;
    return arr;
}


int main(){

    int A[] = {1,2,3,4}; 
    int queries[4][2] = {{1,0},{-3,1},{-4,0},{2,3}};
    int *arr = sumEvenAfterQueries(A,4,queries,4);
    for(int i = 0;i<4;i++){
        printf("%d\n",arr[i]);
    }





    return 0;
}