#include<stdio.h>
#include<stdlib.h>


int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(matrixSize == 0){
        *returnSize = 0;
        return NULL;
    }
    *returnSize = matrixSize*(*matrixColSize);
    int* ret = (int*)malloc(sizeof(int)*(*returnSize));
    int left = 0,up = 0;
    int right = *matrixColSize-1;
    int down = matrixSize-1;
    int rets = 0;
    while(rets < *returnSize){
        for(int i = left;i <= right; i++){
            ret[rets++] = matrix[up][i];
        }
        if(++up > down){
            break;
        }
        for(int i = up;i <= down; i++){
            ret[rets++] = matrix[i][right];
        }
        if(--right < left){
            break;
        }
        for(int i = right;i >= left;i--){
            ret[rets++] = matrix[down][i];
        }
        if(--down < up){
            break;
        }
        for(int i = down;i >= up;i--){
            ret[rets++] = matrix[i][left];
        }
        if(++left > right){
            break;
        }    
    }
    return ret;
}


int main(){
    return 0;
}