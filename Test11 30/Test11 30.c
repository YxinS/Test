#include<stdio.h>
#include<stdlib.h>
int* finalPrices(int* prices, int pricesSize/*, int* returnSize*/){
    //*returnSize = pricesSize;

    for(int i = 0;i<pricesSize;i++){
        for(int j = i+1;j<pricesSize;j++){
            if(prices[i] >= prices[j]){
                prices[i] = prices[i] - prices[j];
                break;
            }
        }
    }
    return prices;
}



int main(){

    int prices[] = {8,4,6,2,3};
    int* prices1 = finalPrices(prices,5);
    for(int i = 0;i<5;i++){
        printf("%d ",prices1[i]);
    }


    return 0;
}