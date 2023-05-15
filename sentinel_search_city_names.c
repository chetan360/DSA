#include <stdio.h>
#include <string.h>

int sentinelSearch(char arr[][20], int n, char key[]) {
    char last[20];
    strcpy(last, arr[n-1]);
    strcpy(arr[n-1], key);
    int i = 0;

    while(strcmp(arr[i], key) != 0) {
        i++;
    }

    strcpy(arr[n-1], last);

    if(i < n-1 || strcmp(arr[n-1], key) == 0) {
        return i;
    }

    return -1;
} 

int main() {
    char arr[20][20], n;
    printf("How many cities : ");
    scanf("%d", &n);

    printf("Enter %d city names :\n", n);
    for(int i=0; i<n; i++) {
        scanf("%s", arr[i]);
    }

    char key[20];
    printf("Enter city to be searched : ");
    scanf("%s", key);

    int i = sentinelSearch(arr, n, key);

    if(i == -1) {
        printf("Not found.");
    } else {
        printf("Found at %d index.", i);
    }

    return 0;
}