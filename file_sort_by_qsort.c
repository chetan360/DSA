#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct employee {
    int eno;
    char ename[30];
    int age;
}emp;

emp rec[MAX];

int partition(int lb, int ub) {
    int dn = lb+1;
    int up = ub;
    emp pivot = rec[lb];
    do {
        while((rec[dn].age < pivot.age) && dn<=ub) {
            dn++;
        }
        while((rec[up].age > pivot.age) && up>lb) {
            up--;
        }
        if(dn<up) {
            emp temp = rec[dn];
            rec[dn] = rec[up];
            rec[up] = temp;
        }
    } while(dn<up);

    rec[lb] = rec[up];
    rec[up] = pivot;
    return up;
}

void quicksort(int lb, int ub) {
    if(lb<ub) {
        int pi = partition(lb, ub);
        quicksort(lb, pi-1);
        quicksort(pi+1, ub);
    }
}

int main() {
    FILE *fp1, *fp2;
    int i, n;

    fp1 = fopen("employee.txt", "w");
    if(fp1==NULL) {
        printf("Error opening file.");
        exit(0);
    }

    printf("How many rec of emps : ");
    scanf("%d", &n);

    printf("Enter %d emp rec as eno, name & age.\n", n);
    for(i=0; i<n; i++) {
        fscanf(stdin, "%d%s%d", &rec[i].eno, rec[i].ename, &rec[i].age);
        fprintf(fp1, "%d %s %d\n", rec[i].eno, rec[i].ename, rec[i].age);
    }
    fclose(fp1);

    fp1 = fopen("employee.txt", "r");
    if(fp1==NULL) {
        printf("Error opening file.");
        exit(0);
    }
    printf("\nData in employee.txt is :\n");
    for(i=0; i<n; i++) {
        fscanf(fp1, "%d%s%d", &rec[i].eno, rec[i].ename, &rec[i].age);
        printf("%d %s %d\n", rec[i].eno, rec[i].ename, rec[i].age);
    }
    fclose(fp1);

    quicksort(0, n-1);

    fp2 = fopen("sortedemponage.txt", "w+");
    if(fp2==NULL) {
        printf("Error opening file.");
        exit(0);
    }

    for(i=0; i<3; i++) {
        fprintf(fp2, "%d %s %d\n", rec[i].eno, rec[i].ename, rec[i].age);
    }
    fclose(fp2);

    return 0;
}