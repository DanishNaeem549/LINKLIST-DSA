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
		void ciclelinklist(node* &head){
			node* temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=head;
		}
      void insertathead(node* &head,int val){
      	node* n=new node(val);
      	node* temp=head;
      	while(temp->next!=head){
					temp=temp->next;
				}
				n->next=head;
				temp->next=n;
      	            head=n;
	  }
		void insertatend(node* &head,int val){
			node* n=new node(val);
			node* temp=head;
			if(head==NULL){
				n->next=n;
				head=n;
			}else{
				while(temp->next!=head){
					temp=temp->next;
				}
				temp->next=n;
				n->next=head;
			}
		}
		void deleteathead(node* &head){
		    node* temp=head;
		    while(temp->next!=head){
		    	temp=temp->next;
			}
			node* todelete=head;
			temp->next=head->next;
			head=head->next;
			delete todelete;
		}
		void deleteattail(node* &head){
			node* temp=head;
			while(temp->next->next!=head){
				temp=temp->next;
			}
			node* todelete=temp->next;
			temp->next=temp->next->next;
			delete todelete;
		}
		void deleteatspos(node* &head,int val){
			node* temp=head;
			while(temp->next->data!=val){
				temp=temp->next;
			}
			node* todelete=temp->next;
			temp->next=temp->next->next;
			delete todelete;
		}
		bool detected(node* &head){
			node* temp=head;
			node* temp1=head;
			while(temp1 && temp1->next){
				temp=temp->next;
				temp1=temp1->next->next;
				if(temp==temp1){
					return true;
			}
			}
			return false;
		}
		void display(node* &head){
			node* temp=head;
		do{
				cout<<temp->data<<"->";
				temp=temp->next;
			}	while(temp!=head);
			cout<<"head"<<endl;
		}
};

int main(){
	node* obj;
	node* head=NULL;
	cout<<"insert at tail"<<endl;
	obj->insertatend(head,1);
	obj->insertatend(head,2);
	obj->insertatend(head,3);
	obj->insertatend(head,4);
	obj->insertatend(head,5);
	obj->display(head);
	cout<<"insert at head"<<endl;
	obj->insertathead(head,2);
	obj->display(head);
	cout<<"Delete at sp position"<<endl;
	obj->deleteatspos(head,3);
	obj->display(head);
	cout<<"Delete at tail"<<endl;
	obj->deleteattail(head);
	obj->display(head);
	obj->detected(head);
	return 0;
}
