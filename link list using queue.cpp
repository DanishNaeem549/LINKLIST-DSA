#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
class Queue{
private:
    Node* front; 
    Node* rear; 
public:
    Queue(){
        front=NULL;
        rear=NULL;
    }
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if(rear==NULL){ 
            front=rear=newNode;
            return;
        }
        rear->next=newNode; 
        rear=newNode;  
	}
    void dequeue(){
        if(front==NULL){ 
            cout<<"Queue is empty, nothing to dequeue!"<<endl;
            return;
        }
        Node* temp=front;  
        front=front->next;  
        if (front==NULL) {
            rear = NULL;
        }
        delete temp; 
    }
    int peek(){
        if(front==NULL){
            cout<<"Queue is empty!"<<endl;
            return -1; 
        }
        return front->data;
    }
    bool isEmpty(){
        return front==NULL;
}
    void display() {
        if (front==NULL){
            cout<<"Queue is empty!"<<endl;
            return;
        }
        Node* temp=front;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main(){
    Queue q;
    cout<<"Enqueue 10, 20, 30:"<<endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout<<"Peek: "<<q.peek()<<endl;
    cout<<"Dequeue an element:"<<endl;
    q.dequeue();
    q.display();
    cout<<"Peek: "<<q.peek()<<endl;
    cout<<"Dequeue all elements:"<<endl;
    q.dequeue();
    q.dequeue();
    q.dequeue(); 
    q.display();
    return 0;
      }

