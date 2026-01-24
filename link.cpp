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
		void insert(node* &head,int val){
	
	node* n=new node(val);
	node* temp=head;
	if(head==NULL){
		head=n;
		return;
	}
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n;
	n->next=NULL;
}
void insertatpos(node* head,int val,int pos){
			node* temp=head;
			node* n=new node(val);
			if(pos==1){
				n->next=head;
				head=n;
			}
			else{
				while(--pos>1){
					temp=temp->next;
				}
				n->next=temp->next;
				temp->next=n;
			}
		}
			int lenght(node* &head){
		    	int len=0;
		    	node* temp=head;
		 	while(temp){
		 		len++;
		 		temp=temp->next;
			 }
			 return len;
		}
		
		void display1(node* &head ,int pos ){
			node* temp=head;
			while(--pos>=1){
				temp=temp->next;
			}
			cout<<temp->data<<endl;
		}
void display(node* &head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
};


int main(){
	node* obj;
	node* head=NULL;
	obj->insert(head,1);
	obj->insert(head,2);
	obj->insert(head,3);
	obj->insert(head,4);
	obj->insert(head,5);
	obj->display(head);
	cout<<obj->lenght(head)<<endl;
	obj->insertatpos(head,6,4);
	obj->display(head);
	obj->display1(head,4);
	return 0;
}
