#include<iostream>
using namespace std;
#define MAX 100
class Stack{
    int top;
    int arr[100];
    public:
    Stack(){
        top = -1;
    }
    bool isEmpty(){
        return top == -1;
    }
    void push(int n){
        if(top == MAX-1){
            cout << "Stack overflow";
            return;
        }
        arr[++top] = n; //Note that ++top HAS to be used in place of top++ as the increment needs to take place before the assignment takes place
    }
    int pop(){
        if(isEmpty()){
            cout << "Stack underflow!";
            return -1;
        }
        return arr[top--];
    }
    int peek(){
        if(isEmpty()){
            cout << "Stack is empty";
            return -1;
        }
        return arr[top];
    }
};
