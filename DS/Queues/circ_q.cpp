#include<iostream>
using namespace std;
#define MAX 5

class CircQ{
    int arr[MAX];
    int front;
    int rear;
    int count;
    public:
    CircQ(){
        front = -1;
        rear = -1;
    }
    bool(isFull()){
        return count == MAX;
    }
    bool(isEmpty()){
        return count == 0;
    }
    void enqueue(int n){
        if(isFull()){
            return;
        }
        if(front == -1){
            front = 0;
        }
        rear = (rear+1)%MAX; //Need to increment rear before assigning an value
        arr[rear] = n; //Enqueueing
        count++;
    }
    int dequeue(){
        if(isEmpty()){
            return;
        }
        int value = arr[front];
        if(front == rear){
            front = rear = -1;
        }else{
            front = (front+1)*MAX;
        }
        count --;
        return value;
    }
};