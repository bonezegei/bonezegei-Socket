/*
  Bonezegei Search
  Author: Bonezegei (Jofel Batutay)
*/
#include <stdio.h>
#include <string.h>

int src(char ar[],char *cmp,int n){
    int a;
    char tmp[32];
    for(a=0; a<32; a++){
        tmp[a]=0;}
    for(a=0; a<((int)strlen(cmp)); a++){
        tmp[a]=ar[a+n];}
    return strcmp(tmp,cmp);
}



int  src2cnt=0;
char src2data[64];
//search cya sa array until makita ang endpoint
void src2(char ar[],int n){
    src2cnt=0;
    int a=0;
    for(a=0; a<64; a++)src2data[a]=0;
    a=0;
    while( (ar[n+a]!=' ')&&( ar[n+a]!='?') ){
        src2data[a]=ar[n+a];
        a++;
        src2cnt++;
    }
}
