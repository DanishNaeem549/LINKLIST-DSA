#include<iostream>
using namespace std;

class node{
	float data;
	node* next;
	public:
		node(float val){
			data=val;
			next=NULL;
		}
		void insertathead(node* &head,float val){
			node* n=new node(val);
			n->next=head;
			head=n;
		}
		void insertatpos(node* head,float val,int pos){
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
		void insertatend(node* &head,float val){
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
		
		void deletehead(node* &head){
			node* todelete=head;
			head=head->next;
			
			delete todelete;
		}
		void deletion(node* &head,float val){
			node* temp=head;
			if(head==NULL){
				cout<<"no list is present"<<endl;
				return;
			}
			if(head->next==NULL){
				deletehead(head);
			}
			while (temp->next->data!=val){
				temp=temp->next;
			}
			node* todelete=temp->next;
			temp->next=temp->next->next;
			   
			   delete todelete;
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
		
		 void insertatmid(node* &head,float val){
		 	node* n=new node(val);
		 	node* temp=head;
		 	int len=lenght(head);
			 int mid=len/2;
			 if(head==NULL){
			 	head=n;
			 }else{
			 	int i=0;
			 	while(i<mid-1){          //using while loop
			 //	for(int i=0;i<mid-1;i++){   using for loop
			 		temp=temp->next;
			 		i++;
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
			void display1(node* &head ,float pos ){
			node* temp=head;
			while(--pos>1){
				temp=temp->next;
			}
			cout<<temp->data<<endl;
		}
};


int main(){
	
	node* obj;
	node* head=NULL;
	
    obj->insertatend(head,1.1);
	obj->insertatend(head,2.2);
	obj->insertatend(head,3.3);
	obj->insertatend(head,4.4);
	obj->insertatend(head,5.5);
	
	obj->display(head);
	obj->insertatpos(head,4.0,3);
	obj->insertatpos(head,4.3,5);
	obj->insertatpos(head,4.5,6);
	obj->display(head);
	obj->insertatmid(head,5.5);
	obj->insertatmid(head,8.9);
	obj->insertatmid(head,9.5);
	obj->display(head);
	cout<<"Number in list :"<<obj->lenght(head)<<endl;
	obj->display1(head,7);
//	obj->deletion(head,1);
  //  obj->display(head);
	
//	obj->deletehead(head);
//	obj->display(head);


	return 0;
}
