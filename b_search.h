#include<stdio.h>
typedef struct emp
{
    int eno;
    char ename[20];
    int age;
}em[10],em1;

int main()
{
    FILE *fp;
    fp = fopen("emp.txt","w");
    fprintf(fp,"12 swapnil 67\n");
    fprintf(fp,"34 chetan 89\n");
    fprintf(fp,"dnyneswar 67\n");
    fclose(fp);
return 0; 
}