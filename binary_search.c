#include<stdio.h>
#include<string.h>

int bsearch(int arr[], int n, int key) {
    int i, mid, low, up;

    low = 0;
    up = n-1;
    while(low <= up) {
        mid = (low+up)/2;
        if(arr[mid] == key) {
            return mid;
        }
        if(key < arr[mid]) {
            up = mid-1;
        } else {
            low = mid+1;
        }
    }
    return -1;
}

int main() {
    int arr[20], n;
    
    printf("How many values:\n");
    scanf("%d", &n);
    
    printf("Enter %d values:\n", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int key;
    printf("Enter value to searched : ");
    scanf("%d", &key);
    
    int i=bsearch(arr, n, key);
    if(i==-1) {
        printf("Not found..");
    } else {
        printf("Found at %d index..", i);
    }
    
    return 0;
}