#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a,const void* b){
    //return (((int*)*(int**)a)[1]) < (((int*)*(int**)b)[1])?-1:1;
    int* _a = *(int**)a;
    int* _b = *(int**)b;
    return _a[1] < _b[1]?-1:1;
}

int findMinArrowShots(int** points, int pointsSize, int pointsColSize){
    if(!pointsSize)return 0;
    qsort(points,pointsSize,sizeof(int*),cmp);
    int pos = points[0][1];
    int ret = 1;
    for(int i = 0;i< pointsSize;i++){
        if(points[i][0] > pos){
            pos = points[i][1];
            ret++;
        }
    }
    return ret;
}

int main(){
    int points[4][2] = {{2,8},{1,2},{10,16},{1,6}};
    int ret = findMinArrowShots((int**)points,4,2);
    printf("%d\n",ret);

    return 0;
}