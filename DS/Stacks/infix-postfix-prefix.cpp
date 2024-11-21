#include<iostream>
using namespace std;
#define MAX 100

class Stack{
    int top;
    char arr[MAX];  // Stack to hold characters
    
public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(char c) {  // Push character onto the stack
        if(top == MAX - 1) {
            cout << "Stack overflow";
            return;
        }
        arr[++top] = c;
    }

    char pop() {  // Pop character from the stack
        if(isEmpty()) {
            cout << "Stack underflow!";
            return -1;
        }
        return arr[top--];
    }

    char peek() {  // Peek at the top character of the stack
        if(isEmpty()) {
            cout << "Stack is empty!";
            return -1;
        }
        return arr[top];
    }
};

// Helper to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Helper to check if a character is an operand
bool isOperand(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}


int op_prec(char a) {
    if(a == '^') return 3;
    if(a == '*' || a == '/') return 2;
    if(a == '+' || a == '-') return 1;
    return 0;  
}

// Function to reverse a string
int reverse(const char* a, char* reverse) {
    Stack stack;
    int j = 0;
    for(int i = 0; a[i] != '\0'; ++i) {
        stack.push(a[i]);
    }
    while(!stack.isEmpty()) {
        reverse[j++] = stack.pop();
    }
    reverse[j] = '\0'; 
    return j;
}

// Infix to Postfix conversion
int infix_to_postfix(const char* a, char* postfix) {
    Stack stack;
    int j = 0;
    for(int i = 0; a[i] != '\0'; i++) {
        char c = a[i];
        if(isOperand(c)) {
            postfix[j++] = c;
        }
        else if(c == '(') {
            stack.push(c);
        }
        else if(c == ')') {
            while(!stack.isEmpty() && stack.peek() != '(') {
                postfix[j++] = stack.pop();
            }
            stack.pop(); 
        }
        else if(isOperator(c)) {
            while(!stack.isEmpty() && op_prec(stack.peek()) >= op_prec(c)) {
                postfix[j++] = stack.pop();
            }
            stack.push(c);
        }
    }
    while(!stack.isEmpty()) {
        postfix[j++] = stack.pop();
    }
    postfix[j] = '\0'; 
    return 0;
}


int infix_to_prefix(const char* a, char* prefix) {
    Stack stack;
    int j = 0;


    char reversedInfix[MAX];
    reverse(a, reversedInfix);


    char postfix[MAX];
    infix_to_postfix(reversedInfix, postfix);


    reverse(postfix, prefix);

    return j;  
}

int main() {
    const char* infix = "A+(B*C-(D/E^F)*G)*H";
    char prefix[MAX];

    infix_to_prefix(infix, prefix);

    // Print the result
    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}
