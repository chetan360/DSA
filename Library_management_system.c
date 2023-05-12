#include<stdio.h>
#include<windows.h>


typedef struct receive {
    int mno;
    int bno;
    char rdate[15];
}RSV;

typedef struct member {
    int mno;
    char mname[20];
    char address[30];
    char bdate[30];
}Mem;

typedef struct book {
    int bno;
    char title[20];
    char author[20];
    float price;
}Book;

typedef struct Issue {
    int mno;
    int bno;
    char idate[15];
}ISU;

void addIssue() {
    ISU i;
    FILE *fp;
    system("cls");
    fp = fopen("issue", "ab+");
    printf("Enter Issue information :\n");
    printf("Member no : ");
    scanf("%d", &i.mno);
    printf("Book no : ");
    scanf("%d", &i.bno);
    printf("Issue date : ");
    gets(i.idate);
    system("cls");
    fclose(fp);
}

void addBook() {
    Book bk;
    FILE *fp;
    system("cls");
    fp = fopen("book", "ab+");
    printf("Enter book information :\n");
    printf("Book no : ");
    scanf("%d", &bk.bno);
    fflush(stdin);
    printf("Book Title : ");
    gets(bk.title);
    printf("Book Author : ");
    gets(bk.author);
    printf("Book Price : ");
    scanf("%f", &bk.price);
    system("pause");
    fclose(fp);
}

void addMember() {
    Mem m;
    FILE *fp;
    system("cls");
    fp = fopen("member", "ab+");
    printf("Enter member informatoin\n");
    printf("Member no : ");
    scanf("%d", &m.mno);
    fflush(stdin);
    printf("Member name : ");
    gets(m.mname);
    printf("Member address : ");
    gets(m.address);
    printf("Member bdate : ");
    gets(m.bdate);
    fwrite((char *)&m, 1, sizeof(m), fp);
    printf("Member is added successfully..\n");
    system("pause");
    fclose(fp);
}

void getBook(int bno) {
    FILE *fp;
    Book b;
    fp = fopen("book", "rb+");
    while(!feof(fp)) {
        fread((char*)&b, 1, sizeof(b), fp);
        if(!feof(fp)) {
            if(b.bno = bno) {
                printf("Book no = %d\n", b.bno);
                printf("Title = %s\n", b.title);
                printf("Author = %s\n", b.author);
                printf("Price = %f\n", b.price);
                printf("--------------------------------\n");
            }
        }
    }
}

int getBno(int mno) {
    FILE *fp;
    ISU b;
    int bno;
    fp = fopen("issue", "rb+");
    while(!feof(fp)) {
        fread((char*)&b, 1, sizeof(b), fp);
        if(!feof(fp)) {
            if(b.mno == mno) {
                bno = b.bno;
            }
        }
    }
    fclose(fp);
    return bno;
}

void getName(int mno) {
    FILE *fp;
    Mem m;
    system("cls");
    fp = fopen("member", "rb+");
    while(!feof(fp)) {
        fread((char*)&m, 1, sizeof(m), fp);
        if(!feof(fp)) {
            if(m.mno = mno) {
                printf("Member no = %d\n", m.mno);
                printf("Name = %d\n", m.mname);
                printf("Address = %d\n", m.address);
                printf("Birth date = %d\n", m.bdate);
                printf("--------------------------------\n");
            }
        }
    }
    fclose(fp);
}

void addReceive() {
    RSV i;
    FILE *fp;
    fp = fopen("receive", "ab+");
    printf("Enter receive information :\n");
    printf("Member no : ");
    scanf("%d", &i.mno);
    printf("Book no : ");
    scanf("%d", &i.bno);
    fflush(stdin);
    printf("Book recieve date : ");
    gets(i.rdate);
    fwrite((char*)&i, 1, sizeof(i), fp);
    printf("Book Received successfully..\n");
    system("pause");
    system("cls");
    fclose(fp);
}

void displayBook() {
    FILE *fp;
    Book b;
    system("cls");
    fp = fopen("book", "rb+");
    while(!feof(fp)) {
        fread((char*)&b, 1, sizeof(b), fp);
        if(!feof(fp)) {
            printf("Book no = %d\n", b.bno);
            printf("Title = %s\n", b.title);
            printf("Author = %s\n", b.author);
            printf("Price = %f\n", b.price);
            printf("-------------------------------\n");
        }
    }
    fclose(fp);
    system("pause");
}

void displayMember() {
    FILE *fp;
    Mem m;
    system("cls");
    fp = fopen("member", "rb+");
    while(!feof(fp)) {
        fread((char*)&m, 1, sizeof(m), fp);
        if(!feof(fp)) {
            printf("Member no = %d\n", m.mno);
            printf("Name = %d\n", m.mname);
            printf("Address = %d\n", m.address);
            printf("Birth date = %d\n", m.bdate);
            printf("--------------------------------\n");
        }
    }
    fclose(fp);
}

void gotoxy(short x, short y) {
    printf("%c[%d;%df", 0x1b, y, x);
}

void menu() {
    system("cls");
    gotoxy(20, 5);
    printf("****** M E N U ******\n");
    gotoxy(20, 6);
    printf(" 1. Add new member\n");
    gotoxy(20, 7);
    printf(" 2. Add new book\n");
    gotoxy(20, 8);
    printf(" 3. Issue Book\n");
    gotoxy(20, 9);
    printf(" 4. Receive\n");
    gotoxy(20, 10);
    printf(" 5. Member report\n");
    gotoxy(20, 11);
    printf(" 6. Book Report\n");
    gotoxy(20, 12);
    printf(" 7. Exit\n");
    gotoxy(20, 13);
}

int main() {
    int choice;
    int mno;
    do {
        menu();
        printf(" Enter your choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addMember();
                break;
            case 2:
                addBook();
                break;
            case 3:
                addIssue();
                break;
            case 4:
                system("cls");
                printf("Enter member no : ");
                scanf("%d", &mno);
                getName(mno);
                getBook(mno);
                addReceive();
                system("cls");
                break;
            case 5:
                displayMember();
                break;
            case 6:
                displayBook();
                break;
        }
    } while(choice < 7);

    return 0;
}