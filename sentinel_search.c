#include <stdio.h>

int sentinelSearch(int arr[], int n, int key) {
    int last = arr[n-1];
    arr[n-1] = key;
    int i = 0;

    while(arr[i] != key) {
        i++;
    }

    arr[n-1] = last;

    if(i < n-1 || arr[n-1] == key) {
        return i;
    }

    return -1;
} 

int main() {
    int arr[20], n;
    printf("How many values : ");
    scanf("%d", &n);

    printf("Enter %d values :\n", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter key to be searched : ");
    scanf("%d", &key);

    int i = sentinelSearch(arr, n, key);

    if(i == -1) {
        printf("Not found.");
    } else {
        printf("Found at %d index.", i);
    }

    return 0;
}