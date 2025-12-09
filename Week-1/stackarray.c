#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;


void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = value;
    }
}


int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int main() {
    int arr[MAX], reversed[MAX];

    
    printf("Enter %d values:\n", MAX);
    for (int i = 0; i < MAX; i++) {
        scanf("%d", &arr[i]);
        push(arr[i]);  
    }

    
    for (int i = 0; i < MAX; i++) {
        reversed[i] = pop();
    }

    
    printf("Reversed values:\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", reversed[i]);
    }

    return 0;
}