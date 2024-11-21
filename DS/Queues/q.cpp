#include<iostream>
using namespace std;
#define MAX 100
class Queue{
    int j;
    int front;
    int rear;
    int arr[MAX];
    public:
    Queue(){
        j=0;
        front = -1;
        rear = -1;
    }
    void enqueue(int n) {
        if(rear == MAX-1){        
            cout << "Queue is full!" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        arr[++rear] = n; 
    }

    int dequeue(){
        if(front == -1){
            return -1;
        }
        int value = arr[front];
        if(front == rear){
            front = rear = -1;
        }else{
            front++;
        }
        return value;
    }
};