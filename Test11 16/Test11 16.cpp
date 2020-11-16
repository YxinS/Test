#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int minTimeToVisitAllPoints(int** points, int pointsSize/*, int* pointsColSize*/){
    //*pointsColSize = 2;
    int time = 0;
    int x = 0, y = 0;
    for(int i = 0;i < pointsSize-1;i++){
        x = abs(points[i][0] - points[i+1][0]);
        y = abs(points[i][1] - points[i+1][1]);
        if(x >= y){
            time += x;
        }
        else{
            time += y;
        }
    }
    return time;
}
