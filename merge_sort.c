#include<stdio.h>

void merge(int arr[], int mid, int lb, int ub) {
    int i, j, k, b[20];
    i = lb;
    j = mid + 1;
    k = lb;

    while(i <= mid && j <= ub) {
        if(arr[i] <= arr[j]) {
            b[k++] = arr[i++];
        } else {
            b[k++] = arr[j++];
        }
    }

    while(i <= mid) {
        b[k++] = arr[i++];
    }

    while(j <= ub) {
        b[k++] = arr[j++];
    }

    for(i=lb; i<=ub; i++) {
        arr[i] = b[i];
    }
}

void merge_sort(int arr[], int lb, int ub) {
    int mid;
    if(lb<ub) {
        mid = (lb+ub) / 2;
        merge_sort(arr, lb, mid);
        merge_sort(arr, mid+1, ub);
        merge(arr, mid, lb, ub);
    }
}

int main() {
    int arr[20], n;
    printf("How many vlaues : ");
    scanf("%d", &n);

    printf("Enter %d values :\n", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, n-1);

    printf("Sorted values are :\n");
    for(int i=0; i<n; i++) {
        printf("%4d", arr[i]);
    }

    return 0;
}