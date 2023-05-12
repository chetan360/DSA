#include<stdio.h>
#include<string.h>
#include<math.h>

typedef struct stack {
    char data[30];
    int top;
}STACK;

STACK s;

void push(char ch) {
    s.data[++s.top] = ch;
}

char pop() {
    return s.data[s.top--];
}

int postfixEvalueation(char exp[20]) {
    for(int i=0; i<strlen(exp); i++) {
        if(exp[i]>='0' && exp[i]<='9') {
            push(exp[i]-'0');
        } else {
            int op2 = pop();
            int op1 = pop();

            switch(exp[i]) {
                case '+': push(op1+op2);
                    break;
                case '-': push(op1-op2);
                    break;
                case '*': push(op1*op2);
                    break;
                case '/': push(op1/op2);
                    break;
                case '^': push(pow(op1,op2));
                    break;
            }
        }
    }
    return pop();
}

int main() {
    s.top = -1;
    printf("Result is  = %d", postfixEvalueation("45*2/"));
}