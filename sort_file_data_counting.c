#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char name[20][30];

void counting_sort(int n) {
    char b[20][30];
    int i;
    int c[26] = {0};

    for(i=0; i<n; i++) {
        c[name[i][0]-'a']++;
    }

    for(i=1; i<26; i++) {
        c[i] += c[i-1];
    }

    for(i=n-1; i>=0; i--) {
        strcpy(b[--c[name[i][0]-'a']],name[i]);
    }

    for(i=0; i<n; i++) {
        strcpy(name[i], b[i]);
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
    counting_sort(n);

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