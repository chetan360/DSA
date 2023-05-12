#include<stdio.h>

int arr[20], n, i, j;

void bsort() {
    for(i=1; i<n; i++) {
        for(j=0; j<n-i; j++) {
            if(arr[j+1]<arr[j]) {
                int t = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = t;
            }
        }
    }
}

int main() {
    printf("How many values : ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    bsort();

    printf("\n");

    for(i=0; i<n; i++) {
        printf("%4d", arr[i]);
    }
}