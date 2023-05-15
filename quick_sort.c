#include <stdio.h>

int partition(int arr[], int lb, int ub) {
    int dn = lb+1;
    int up = ub;
    int pivot = arr[lb];

    do {
        while(arr[dn] < pivot && dn <= ub) {
            dn++;
        }
        while(arr[up] > pivot && up > lb) {
            up--;
        }
        if(dn < up) {
            int t = arr[dn];
            arr[dn] = arr[up];
            arr[up] = t;
        }
    } while(dn < up);

    arr[lb] = arr[up];
    arr[up] = pivot;
    return up;
}

void quickSort(int arr[], int lb, int ub) {
    if(lb < ub) {
        int pi = partition(arr, lb, ub);
        quickSort(arr, lb, pi-1);
        quickSort(arr, pi+1, ub);
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

    quickSort(arr, 0, n-1);

    printf("Sorted values are :\n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}