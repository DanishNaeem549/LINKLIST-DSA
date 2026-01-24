#include<iostream>
using namespace std;

class node{
	int data;
	node* next;
	public:
		node(int val){
			data=val;
			next=NULL;
		}  
		void insertatend(node* &head,int val){
			node* temp=head;     //create new pointer which is equal to the head
			node* n=new node(val);  //create new value which add at end of link list
			if(head==NULL){  //if head is already null so coming value is first val
				head=n;
			}else{
				while(temp->next!=NULL){
					temp=temp->next;  //move temp from head to end of list
				}
				temp->next=n;    //create a link between last node
				n->next=NULL;    
			}
		}
		
		void insertathead(node* &head,int val){
			node* temp=head;
			node* n=new node(val);
			n->next=head;
			head=n;
		}
		
		void display(node* &head){
			node* temp=head;
			while(temp!=NULL){
				cout<<temp->data<<" -> ";
				temp=temp->next;
			}
			cout<<"NULL"<<endl;
		}
};


int main(){
	
	node* obj;    //create a object
	node* head=NULL;  
	
	obj->insertatend(head,1);
	obj->insertatend(head,2);
	obj->insertatend(head,3);
	obj->insertatend(head,4);
	obj->insertatend(head,5);
	obj->insertathead(head,0);
	obj->display(head);
	
	return 0;
}
