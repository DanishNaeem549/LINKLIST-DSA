#include<iostream>
using namespace std;

class node{
	int data;
	node* next;
	node* pre;
	public:
		node(int val){
			data=val;
			next=NULL;
			pre=NULL;
		}
		void insertathead(node* &head,int val){
			node* n=new node(val);
			n->next=head;
			head->pre=n;
			head=n;
		}
		void insertatend(node* &head,int val){
			node* temp=head;
			node* n=new node(val);
			if(head==NULL){
			
			head =n;
			return;
			}
			while(temp->next!=NULL){
				temp=temp->next;
		    }
		    
		    temp->next=n;
		    n->pre=temp;
		    
		}
		void reverse(node* &head){
			node* temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			while(temp!=NULL){
				cout<<temp->data<<"->";
				temp=temp->pre;
			}
			cout<<"NULL"<<endl;
		}
		void reverse1(node* &head,int pos){
			node* temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			while(temp!=NULL){
				cout<<temp->data<<"->";
				temp=temp->pre;
	}
			cout<<"NULL"<<endl;
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
		void deletemid(node* &head){
			node* temp=head;
			int len;
			len=lenght(head);
			int mid=0;
			mid=len/2;
			for(int i=0;i<mid-1;i++){
				temp=temp->next;
			}
			node* todelete=temp->next;
			temp->next=temp->next->next;
			temp->next->pre=temp;
			
			delete todelete;
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
               temp->next->pre=n;
               temp->next=n;
                n->pre=temp;
			}
		}

          void deletehead(node* &head){
			node* todelete=head;
			head=head->next;
            head->pre=NULL;
			delete todelete;
		}
      void deleteattail(node* &head,int val){
			node* temp=head;
			if(head->next==NULL){
				deletehead(head);
			}else{
				
			while (temp->next->data!=val){
				temp=temp->next;
			}
			node* todelete=temp->next;
			temp->next=temp->next->next;
			todelete->next->pre=temp;
			   
			   delete todelete;
	}
}
		void display(node* &head){
			node* temp=head;
			while(temp!=NULL){
				cout<<temp->data<<"-> ";
				temp=temp->next;
			}
			cout<<"NULL"<<endl;
		}
};


int main(){
	
	node* obj;
	node* head=NULL;
	cout<<"insert at Tail:"<<endl;
	obj->insertatend(head,1);
	obj->insertatend(head,2);
	obj->insertatend(head,3);
	obj->insertatend(head,4);
	obj->display(head);
	cout<<"insert at head:"<<endl;
	obj->insertathead(head,0);
	obj->display(head);
	cout<<"delete at head:"<<endl;
	obj->deletehead(head);
	obj->display(head);
	cout<<"delete at Tail:"<<endl;
	obj->deleteattail(head,4);
	obj->display(head);
	cout<<"insert at position:"<<endl;
	obj->insertatpos(head,4,2);
	obj->display(head);

	return 0;
}
