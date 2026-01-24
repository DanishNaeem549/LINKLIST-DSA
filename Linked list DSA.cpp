#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node* next;
	node(int val){
		data=val;
		next=NULL;
	}
};
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
void insertathead(node* &head,int val){
	node* n=new node(val);
	n->next=head;
	head=n;
}
bool search(node* &head, int key){
	node* temp=head;
	while(temp!=NULL){
		if(temp->data==key){
			return true;
		}
		temp=temp->next;
	}
	return false;
}
void findMinMax() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        int minVal = head->data;
        int maxVal = head->data;

        Node* temp = head;
        while (temp != nullptr) {
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

void display(node* &head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<endl;
}
int main(){
	node* head=NULL;
	insert(head,1);
	insert(head,2);
	insert(head,3);
	insert(head,4);
	insertathead(head,5);
	display(head);
	
	return 0;
}
