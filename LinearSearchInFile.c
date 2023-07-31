#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct city {
    char cityName[30];
    char std[10];
}City[20];

int linearSearch(char key[]) {
    for(int i=0; i<5; i++) {
        if(strcmp(City[i].cityName, key) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    FILE *fp;

    fp = fopen("cities.txt", "r");
    if(fp == NULL) {
        printf("Error opening file");
        exit(0);
    }

    for(int i=0; i<5; i++) {
        fscanf(fp, "%s%s", City[i].cityName, City[i].std);
    }

    char key[30];
    printf("Enter city name : ");
    scanf("%s", key);

    int i = linearSearch(key);

    if(i == -1) {
        printf("City not in the list.");
    } else {
        printf("%s", City[i].std);
    }

    return 0;
}
