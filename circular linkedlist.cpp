#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		//constructor
		Node(int d){
			this->data=d;
			this->next=NULL;
			
		}
		
		//destructor
		~Node(){
			int value = this->data;
			if(this->data !=NULL){
				delete next;
				next=NULL;
			}
			cout<<"memory is free for the node with data "<< value<<endl;
		}
};

 void insertNode(Node* &tail, int element, int d){
	// assuming that ELEMENT is present in the list
	
	//empty list
	if(tail==NULL){
		Node* newNode = new Node(d);
		tail= newNode;
		newNode->next= newNode;
	}
	else{
		//non-empty list
		//assuming that ELEMENT is present in the list
		
		Node* curr = tail;
		
		while(curr->data != element){
			curr=curr->next;
		}
		
		// element found -> curr is representing element wala node
		
		Node* temp = new Node(d);
		temp->next= curr->next;
		curr->next = temp;
	}
}

void print(Node* tail){
	Node* temp = tail;
	if(tail==NULL){
		cout<<"List is empty"<<endl;
		return;
	}
	do
	{
		cout<< tail->data<<" ";
		tail=tail->next;
	}
	while(tail->next!= temp);
	cout<<endl;
}

void deleteNode(Node* &tail, int value){
	// if list is empty
	if(tail == NULL){
		cout<<" list is fookin empty";
		return;
	}
	else{
		// assuming the VALUE you given is present in the list
		Node* prev = tail;
		Node* curr = prev->next;
		
		while(curr->data != value){
			prev= curr;
			curr = curr->next;
		}
		
		prev->next = curr->next;
		
		//single node present in linked list
		if(curr==prev){
			tail= NULL;
		}
		// greater than single node present
		else if(tail== curr){
			tail = prev;
		}
		curr->next = NULL;
		delete curr;
		
	}
}

int main(){
	Node* tail = NULL;
	
	//empty list right now
	insertNode(tail,5,3);
	print(tail);
	insertNode(tail,3,5);
	print(tail);
	insertNode(tail,5,7);
	print(tail);
	insertNode(tail,7,9);
	print(tail);
	
	deleteNode(tail,3);
	print(tail);
	deleteNode(tail,9);
	print(tail);
}
