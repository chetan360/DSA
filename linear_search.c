#include<stdio.h>

int linearSearch(int arr[], int n, int key) {
    for(int i=0; i<n; i++) {
        if(arr[i] == key) {
            return i;
        }
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
    printf("Enter key to search : ");
    scanf("%d", &key);
    
    int i = linearSearch(arr, n, key);
    
    if(i == -1) {
        printf("Not found.");
    } else {
        printf("Found at %d index.", i);
    }
    
    return 0;
}