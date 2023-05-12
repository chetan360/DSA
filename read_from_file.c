#include<stdio.h>
#include<stdlib.h>
#include<string.h>
   
typedef struct friend {
    int fno;
    char fname[20];
    int age;
}fr;

fr rec[20];


int binary_search(int n, char key[20]) {
    int low, high, mid;
    low = 0;
    high = n-1;
    while(low<=high) {
        mid = (low+high)/2;
        if(strcmp(rec[mid].fname,key)==0) {
            return mid;
        } else if(strcmp(key, rec[mid].fname)>0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    FILE *fp;
    fp = fopen("friends.txt", "r");
    if(fp == NULL) {
        printf("Error opening file..\n");
        exit(0);
    }

    int i=0;
    while(!feof(fp)){
        fscanf(fp,"%d%s%d",&rec[i].fno, rec[i].fname, &rec[i].age);
        printf("%d %s %d\n",rec[i].fno, rec[i].fname, rec[i].age);
        i++;
    }
    fclose(fp);

    printf("Enter key to search : ");
    char key[20];
    scanf("%s", key);

    i = binary_search(i, key);

    if(i == -1) {
        printf("Not found..");
    } else {
        printf("Found at %d position.", i+1);
    }

    return 0;
}