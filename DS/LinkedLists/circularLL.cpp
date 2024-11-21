#include<iostream>
using namespace std;

class CircularLL{
    private:
    struct Node{
        int val;
        Node* next;
    };
    Node* head;
    public:
    CircularLL(){
        head = nullptr;
    }
    Node* create(int data){
        Node* newNode = new Node;
        newNode->val = data;
        newNode->next = nullptr;
        return newNode;
    }
    void insertAtHead(int data){
        Node* newNode = create(data);
        if(head == nullptr){
            head = newNode;
            newNode->next = head;
        }else{
            Node* temp = head;
            while(temp->next!=head){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode = head->next;
            head = newNode;
        }
    }
    void insert(int data, int position){
        Node* newNode = new Node;
        newNode->val = data;
        newNode->next = nullptr;

        if(position == 1){
            newNode->next = head; //We do this to make sure that the now inserted element points to the previous element.
            head = newNode; //We set the new head as newNode
        }

        Node* temp = head;
        int count = 1;

        while(temp != nullptr && count<position-1){
            temp = temp->next;
            count++;
            if(temp==head){
                break;
            }
        }

        if(temp == nullptr){
            return;
        }

        newNode->next = head; //Makes sure that the newNode points to the node after insertion
        temp->next = newNode; //We need to make sure that the previous node points to the node being inserted.
    }

};