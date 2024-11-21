#include<iostream>
using namespace std;


class LinkedList{
    private:
    struct Node{
        int val;
        Node* next;
    };

    Node* head;
    public:
    LinkedList(){
        head = nullptr;
    }
    void insert_start(int data){
        Node* newNode = new Node;
        newNode-> val = data;
        newNode-> next = nullptr;
        head = newNode;
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
        }

        if(temp == nullptr){
            return;
        }

        newNode->next = temp->next; //Makes sure that the newNode points to the node after insertion
        temp->next = newNode; //We need to make sure that the previous node points to the node being inserted.
    }
    void insertRear(int data){
        Node* newNode = new Node;
        newNode->val = data;
        newNode->next = nullptr;

        Node* temp=head;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void del(int data){
        if(head->val == data){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        Node* temp = head;
        while(temp->next!=nullptr && temp->next->val!=data){
            temp=temp->next;
        }
        if(temp->next == nullptr){
            cout << "List is empty!"; 
        }

        Node* toDel = temp->next;
        temp->next = temp->next->next;
        delete toDel;
    }
    int count(){
        int i;
        Node* temp = head;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
    }
    ~LinkedList(){
        Node* temp = head;
        head = head->next;
        delete temp;
    }

};