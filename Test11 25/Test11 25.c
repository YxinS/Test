#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * sortString(char * s){
    //int* num = (int*)calloc(0,sizeof(int)*26);
    int num[26];
    memset(num, 0, sizeof(num));
    int len  = strlen(s);
    char* ret = (char*)malloc(sizeof(char)*(len+1));
    int max = 0;
    for(int i = 0;i< len;i++){
        num[s[i]-'a']++;
    }
    while(max < len){
        for(int i = 0;i<26;i++){
            if(num[i]){
                ret[max++] = i+'a';
                num[i]--;
            }
        }
        for(int i = 25;i >=0;i--){
            if(num[i]){
                ret[max++] = i +'a';
                num[i]--;
            }
        }
    }
    //ret[max] = '/0';
    return ret;

}
int main(){
    char*s = "aaaabbbbcccc";
    char*b = sortString(s);
    printf("%s\n",s);
    printf("%s\n",b);



    return 0;
}