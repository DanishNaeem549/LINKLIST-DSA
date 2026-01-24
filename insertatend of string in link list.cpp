#include<iostream>
using namespace std;

class node{
	string data;
	node* next;
	public:
		node(){}
		node(string val){
			data=val;
			next=NULL;
		}
		void insertathead(node* &head,string val){
			node* n=new node(val);
			n->next=head;
			head=n;
		}
		void insertatsp(node* &head,string val,int pos){
			node* n=new node(val);
			node* temp=head;
			if(pos==1){
				n->next=head;
				head=n;
			}else{
				while(--pos>1){
					temp=temp->next;
				}
				n->next=temp->next;
				temp->next=n;
			}
		}
		void insertatend(node* &head,string val){
			node* temp=head;
			node* n=new node(val);
			if(head==NULL){
				head=n;
			}else{
				while(temp->next!=NULL){
					temp=temp->next;
				}
				temp->next=n;
				n->next=NULL;
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
		
		 void insertatmid(node* &head,string val){
		 	node* n=new node(val);
		 	node* temp=head;
		 	int len=lenght(head);
			 int mid=len/2;
			 if(head==NULL){
			 	head=n;
			 }else{
			 	for(int i=0;i<mid-1;i++){
			 		temp=temp->next;
				 }
				 n->next=temp->next;
				 temp->next=n;
			 }
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
	
	node* obj;
	node* head=NULL;
	
	obj->insertatend(head,"Naeem");
	obj->insertatend(head,"Ali");
	obj->insertatend(head,"Danish");
	obj->insertatend(head,"Bilal");
	obj->insertatend(head,"Bilal");
	obj->insertathead(head,"Muhammad");
	obj->display(head);
	obj->insertatsp(head,"Ahmed",4);
	obj->insertatsp(head,"Ahmar",7);
	obj->insertatsp(head,"Arain",6);
	obj->display(head);
	obj->insertatmid(head,"allah");
	obj->display(head);
	return 0;
}
