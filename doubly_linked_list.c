#include<stdio.h>
#include"doublylist.h" //user defined library's are called inside ""

int main() {
    int n, ch;
    NODEPTR dlist = NULL;

    do {
        printf("\n\n\n         MENU\n");
        printf("1. Create.\n2. Insert.\n3. Delete\n4. Display.\n5. Exit\n");
        printf("-----------------------------------------\n");

        printf("Enter your cloise : ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: dlist = create(dlist);
                break;
            case 2: printf("Enter new value : ");
                scanf("%d", &n);
                dlist = insert(dlist, n);
                break;
            case 3: dlist = del(dlist);
                break;
            case 4: display(dlist);
                break;
            default: printf("Envalid choise..\n");
        }
    } while(ch != 5);

    return 0;
}