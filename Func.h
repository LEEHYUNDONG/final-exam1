#ifndef _FUNC_H_
#define _FUNC_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*void Loadstnum(int *stnum)
{
    FILE *file = fopen("st.txt", "rb");
    if(file == NULL)
    {
        return;
    }
    
    fread(*stnum, sizeof(stnum), 1, file);

}*/
void Loaddata(info *arr)
{
    int i;
    FILE *file = fopen("info.txt", "rb");
    if(file == NULL)
    {
        return;
    }
    while(1)
    {
        fread(arr[*stnum].name, sizeof(arr[*stnum].name), 1, file);
        fread(arr[*stnum].snum, sizeof(arr[*stnum].snum), 1, file);
        fread(arr[*stnum].lit, sizeof(arr[*stnum].lit), 1, file);
        fread(arr[*stnum].math, sizeof(arr[*stnum].math), 1, file);
        fread(arr[*stnum].eng, sizeof(arr[*stnum].eng), 1, file);
        
        if(feof(file) != 0)
        {
            break;
        }
        (*stnum)++;
    }
}

/*void Savestnum(int *stnum)
{
    FILE *file = fopen("st.txt", "wb");
    if(file == NULL)
    {
        return;
    }
    
    fwrite(*stnum, sizeof(stnum), 1, file);

}*/
void Savedata(info *arr, int *stnum)
{
    int i;
    FILE *file = fopen("info.txt", "wb");
    if(file == NULL)
    {
        return;
    }

    for(i = 0;i < (*stnum);i++)
    {
        fwrite(arr[i].name, sizeof(arr[i].name), 1, file);
        fwrite(arr[i].snum, sizeof(arr[i].snum), 1, file);
        fwrite(arr[i].lit, sizeof(arr[i].lit), 1, file);
        fwrite(arr[i].math, sizeof(arr[i].math), 1, file);
        fwrite(arr[i].eng, sizeof(arr[i].eng), 1, file);
    }
}

void input_info(info *arr, int *stnum)
{
    int i, j;
    
    printf("------------------\n");
    printf("Name : ");
    fgets(arr[*stnum].name, sizeof(arr[*stnum].name), stdin);
    arr[*stnum].name[sizeof(arr[*stnum].name) - 1] = '\0';

    printf("Student number : ");
    fgets(arr[*stnum].snum, sizeof(arr[*stnum].snum), stdin);
    arr[*stnum].snum[sizeof(arr[*stnum].snum) - 1] = '\0';

    printf("Literature Score : ");
    scanf("%d", &arr[*stnum].lit);
    
    printf("Math : ");
    scanf("%d", &arr[*stnum].math);
    
    printf("English : ");
    scanf("%d", &arr[*stnum].eng);

    printf("------------------\n");
    (*stnum)++;

}
double total_average(info *arr, int *stnum)
{
    double avg;
    double total;
    int i;
    int t;

    for(i = 0;i < (*stnum);i++)
    {
        total += (arr[i].lit + arr[i].math + arr[i].eng);
        t++;
    }
    avg = total / t;

    return avg;

}
#endif
