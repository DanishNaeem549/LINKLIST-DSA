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
		void insertathead(node* &head,int val){
			node* n=new node(val);
			n->next=head;
			head=n;
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
		void insertatend(node* &head,int val){
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
		void deletion(node* &head,int val){
			node* temp=head;
			if(head->next==NULL){
				deletehead(head);
			}else{
				
			while (temp->next->data!=val){
				temp=temp->next;
			}
			node* todelete=temp->next;
			temp->next=temp->next->next;
			   
			   delete todelete;
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
		
		 void insertatmid(node* &head,int val){
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
		 void findMinMax(node* &head) {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        int minVal = head->data;
        int maxVal = head->data;

        node* temp = head;
        while (temp != NULL) {
            if (temp->data < minVal) {
                minVal = temp->data;
            }
            if (temp->data > maxVal) {
                maxVal = temp->data;
            }
            temp = temp->next;
        }

        cout << "Minimum value: " << minVal << endl;
        cout << "Maximum value: " << maxVal << endl;
    }
    	void pairswap(node* &head){
    		node* temp=head;
    		while(temp && temp->next){
    			swap(temp->data,temp->next->data);
    			temp=temp->next->next;
			}
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
			
			delete todelete;
		}
		void duplicate(node* &head){
			node* temp=head;
			while(temp->next!=NULL){
				if(temp->next->data==temp->data){
					node* duplicate=temp->next;
					temp->next=temp->next->next;
					delete duplicate;
					temp=temp->next;
				}
				else{
					temp=temp->next;
				}
			}
		}
		node* getHead(node* head) {
        return head;
    }

		void append(node* &head){
			node* temp=head;
			node* temp1=head;
			while(temp->next!=next){
				temp=temp->next;
			}
			temp->next=getHead(head);
		}
		void sortalist(node* &head){
			bool swapped;
			do{
			node* temp=head;
			swapped=false;
			while(temp->next!=NULL){
				if(temp->data>temp->next->data){
					swap(temp->data,temp->next->data);
					swapped=true;
				}
				temp=temp->next;
			}
			}while(swapped);
		}
		void display(node* &head){
			node* temp=head;
			while(temp!=NULL){
				cout<<temp->data<<" -> ";
				temp=temp->next;
			}
			cout<<"NULL"<<endl;
		}
			void display1(node* &head ,int pos ){
			node* temp=head;
			while(--pos>=1){
				temp=temp->next;
			}
			cout<<temp->data<<endl;
		}
			void update(node* &head , int val ,int pos ){
			node* temp=head;
			while(--pos>=1){
				temp=temp->next;
			}
		    temp->data=val;
		}
};


int main(){
	
	node* obj;
	node* head=NULL;
	
    obj->insertatend(head,1);
	obj->insertatend(head,2);
	obj->insertatend(head,3);
	obj->insertatend(head,4);
	obj->insertatend(head,5);
	
	obj->display(head);
	obj->insertatpos(head,6,3);
	obj->display(head);
	obj->insertatmid(head,10);
	obj->insertatmid(head,11);
	obj->insertatmid(head,12);
	obj->display(head);
	cout<<"Number in list :"<<obj->lenght(head)<<endl;
	obj->display1(head,7);
	obj->deletemid(head);
	obj->display(head);
	cout<<"Number in list :"<<obj->lenght(head)<<endl;
	obj->insertatend(head,34);
	obj->display(head);
  //  obj->display(head);
	//obj->deletehead(head);
	obj->deletemid(head);
    obj->display(head);
    obj->findMinMax(head);
    obj->display1(head,5);
    obj->display(head);
    obj->pairswap(head);
    obj->display(head);
    obj->update(head,90,4);
    obj->display(head);
    obj->insertathead(head,2);
    obj->display(head);
    obj->duplicate(head);
    obj->display(head);
    obj->sortalist(head);
    obj->display(head);
	return 0;
}
