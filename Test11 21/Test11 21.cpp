#include<iostream>
using namespace std;

int GetDay(int year,int month){
        static int arr[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(month == 2 && ((year%4==0&&year%100!=0)||year%400==0)){
            return 29;
        }
        return arr[month];
    }



int main(){
    int year,month,day;
    
    while(cin >> year >> month >> day){
        int dayy = 0;
        while(month){
            dayy+=GetDay(year,month-1);
            month--;
        }
        cout << dayy + day << endl;
    }
    
    
    
    return 0;
}