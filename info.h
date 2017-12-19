#ifndef _INFO_H_
#define _INFO_H_
#include<stdio.h>
#include<stdlib.h>
#define MAX_P 12

typedef struct information
{
    char name[20];
    char snum[10];
    int lit;
    int math;
    int eng;
    
}info;

info arr[12];
int stnum = 0;
#endif
