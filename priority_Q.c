#include<stdio.h>

#define MAX 20

int pdqueue[MAX], fr, rr;

void create() {
    fr = rr = -1;
}

void priority(int n) {
    int i, j;
    for(i=0; i<=rr; i++) {
        if(n >= pdqueue[i]) {
            for(j=rr+1; j>i; j--) {
                pdqueue[j] = pdqueue[j-1];
            }
            pdqueue[i] = n;
            return;
        }
    }
    pdqueue[i] = n;
}

void enqueue(int n) {
    if(rr >= MAX-1) {
        printf("Queue is full.\n");
        return;
    }
    if(fr==-1 && rr==-1) {
        fr++;
        pdqueue[++rr] = n;
        return;
    }
    priority(n);
    rr++;
}

void dqueue(int n) {
    int i;
    if(fr==-1 && rr==-1) {
        printf("Queue is empty.\n");
        return;
    }
    for(i=0; i<=rr; i++) {
        if(n==pdqueue[i]) {
            while(i<rr) {
                pdqueue[i] = pdqueue[i+1];
                i++;
            }
            pdqueue[i] = -99;
            rr--;
            if(rr==-1) {
                fr = -1;
            }
            return;
        }
    }
    printf("Number not found.\n");
}

void display() {
    if(fr==-1 && rr==-1) {
        printf("Queue is empty.\n");
        return;
    }
    while(fr<=rr) {
        printf(" %d ", pdqueue[fr]);
        fr++;
    }
    fr = 0;
}

int main() {
    create();
    int n, ch;
    do {
        printf("\n\n\n                 MENU\n");
        printf("1. Enqueue by priority\n");
        printf("2. Dqueue by priority\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choise : ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: printf("Enter a value : ");
                scanf("%d", &n);
                enqueue(n);
                break;
            case 2: printf("Enter a value : ");
                scanf("%d", &n);
                dqueue(n);
                break;
            case 3: display();
                break;
        }
    } while(ch != 4);
    return 0;
}