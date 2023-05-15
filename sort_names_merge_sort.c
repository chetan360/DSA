#include<stdio.h>
#include<string.h>

void merge(char name[][50], int lb, int mid, int ub) {
    int i, j, k ;
    char b[50][50];
    i = lb;
    j = mid + 1;
    k = lb;

    while((i <= mid) && (j <= ub)) {
        if(strcmp(name[i], name[j]) <= 0) {
            strcpy(b[k++], name[i++]);
        } else {
            strcpy(b[k++], name[j++]);
        }
    }

    while(i <= mid) {
        strcpy(b[k++], name[i++]);
    }

    while(j <= ub) {
        strcpy(b[k++], name[j++]);
    }

    for(i=lb; i<=ub; i++) {
        strcpy(name[i], b[i]);
    }
}

void merge_sort(char name[][50], int lb, int ub) {
    int mid;
    if(lb < ub) {
        mid = (lb + ub) / 2;
        merge_sort(name, lb, mid);
        merge_sort(name, mid+1, ub);
        merge(name, lb, mid, ub);
    }
}

int main() {
    char name[50][50];
    int n;
    printf("How many names : ");
    scanf("%d", &n);

    printf("Enter %d names :\n", n);
    for(int i=0; i<n; i++) {
        scanf("%s", name[i]);
    }

    merge_sort(name, 0, n-1);

    printf("Names in sorted order :\n");
    for(int i=0; i<n; i++) {
        printf(" %s\n", name[i]);
    }

    return 0;
}
