#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char name[20][30];

void merge(int lb, int mid, int ub) {
    int i, j , k;
    char b[20][30];
    i = lb;
    j = mid + 1;
    k = lb;

    while (i <= mid && j <= ub) {
        if(strcmp(name[i], name[j]) <= 0) {
            strcpy(b[k++], name[i++]);
        } else {
            strcpy(b[k++], name[j++]);
        }
    }

    while(i <= mid) {
        strcpy(b[k++], name[i++]);
    }

    while(j <= ub) {
        strcpy(b[k++], name[j++]);
    }

    for(i=lb; i<=ub; i++) {
        strcpy(name[i], b[i]);
    }    
}

void merge_sort(int lb, int ub) {
    int mid;
    if(lb < ub) {
        mid = (lb + ub) / 2;
        merge_sort(lb, mid);
        merge_sort(mid+1, ub);
        merge(lb, mid, ub);
    }
}

int main() {
    FILE *fp;
    int i;
    fp = fopen("names.txt", "r");
    if(fp == NULL) {
        printf("Error opening file..");
        exit(0);
    }

    for(i=0; !feof(fp); i++) {
        fscanf(fp, "%s", name[i]);
    }
    fclose(fp);

    int n = i;
    merge_sort(0, n-1);

    fp = fopen("sortedemponname.txt", "w");
    if(fp == NULL) {
        printf("Error opening file..");
        exit(0);
    }

    for(i=0; i<n; i++) {
        fprintf(fp, "%s\n", name[i]);
    }
    fclose(fp);

    return 0;
}