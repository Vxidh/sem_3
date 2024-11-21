#include<iostream>
using namespace std;
#define MAX 100
class Stack{
    int top;
    char arr[100];
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
bool parenthesis_checker(char arr[]){
    Stack s;
    for(int i = 0; arr[i]!='\0';++i){
        char curr = arr[i];
        if(curr == '('){
            s.push(curr);
        }
        else if(curr == ')'){
            if(s.isEmpty()){
                return false;
            }
            char top = s.pop();
            if(curr == ')' && top!='('){
                return false;
            }
        }
    }
}
int main(){
    char inp[100];
    cout << "Enter your expression: ";
    cin.getline(inp, 100);

}