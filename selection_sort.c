#include <stdio.h>

void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] > arr[j]) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}

int main() {
    int arr[20];
    int n;

    printf("How many values : ");
    scanf("%d", &n);

    printf("Enter %d values :\n", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);

    printf("Sorted values are :\n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}