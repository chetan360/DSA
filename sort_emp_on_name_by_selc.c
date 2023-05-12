#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

char ename[30][10];

void selction_sort(int n) {
    int i, j;
    char t[20];
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(strcmp(ename[i],ename[j])>0) {
               strcpy( t, ename[i]);
               strcpy(ename[i], ename[j]);
               strcpy(ename[j], t); 
            }
        }
    }
}

int main() {
    FILE *fp;
    int n, i;
    
    fp = fopen("employee.txt","r");
    if(fp==NULL) {
        printf("Error opening file.\n");
        exit(0);
    }

    printf("\nData in employee.txt is :\n");
    i=0;
    while(!feof(fp)) {
        fscanf(fp, "%s", ename[i]);
        printf("%s\n", ename[i]);
        i++;
    }
    fclose(fp);

    n = i;
    selction_sort(n);

    printf("\nData after sorting.\n");
    for(i=0; i<n; i++) {
        printf(" %s\n", ename[i]);
    }

    return 0;
}