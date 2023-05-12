#include<stdio.h>
#include<string.h>

struct city {
    char cnames[50];
    int std;
};

int comp_count;

int linear_search(struct city rec[], int n, char key[]) {
    int i;
    comp_count = 0;
    for(int i=0; i<n; i++) {
        comp_count++;
        if(strcmp(rec[i].cnames, key) == 0) {
            return i;
        }
    }
    return -1;
}

int binary_search(struct city rec[], int lb, int ub,  char key[]) {
    int mid;
    comp_count = 0;
    while(lb <= ub) {
        comp_count++;
        mid = (lb+ub)/2;
        if(strcmp(rec[mid].cnames, key) == 0) {
            return mid;
        } else if(strcmp(key, rec[mid].cnames) > 0) {
            lb = mid + 1;
        } else {
            ub = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    struct city rec[50];
    printf("How many names : ");
    scanf("%d", &n);

    printf("Enter %d city names and their stds :\n", n);
    for(int i=0; i<n; i++) {
        scanf("%s%d", rec[i].cnames, &rec[i].std);
    }

    char key[50];
    printf("Enter key to search :\n");
    scanf("%s", key);

    int i = linear_search(rec, n, key);
    printf("Output of linear search :\n");
    if(i == -1) {
        printf("City not found.\n");
    } else {
        printf(" %s = %d\n", rec[i].cnames, rec[i].std);
        printf(" comparisons = %d\n", comp_count);
    }

    printf("Enter key to search :\n");
    scanf("%s", key);
    i = binary_search(rec, 0, n-1, key);

    printf("Output of binary search :\n");
    if(i == -1) {
        printf("City not found.\n");
    } else {
        printf(" %s = %d\n", rec[i].cnames, rec[i].std);
        printf(" comparisons = %d", comp_count);
    }

    return 0;
}