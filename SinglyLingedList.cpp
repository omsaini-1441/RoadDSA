#include<bits/stdc++.h>
using namespace std;

class Node{
	
	public:
		int data;
		Node* next;
	//constructor
	Node(int data){
		this-> data = data;
		this-> next = NULL;
	}
	//destructor
	~Node(){
		int value = this->data;
		if(this->next != NULL){
			
			delete next;
			this->next= NULL;
		}
		cout<<"Memory is free with data "<< value << endl;
	}
	
};

void insertAtHead(Node* &Head, int d){                // insert at head
	Node* temp=new Node(d);
	temp->next=Head;
	Head = temp;
}

void print(Node* &Head){                             // traverse a linked list , print it
	Node* temp=Head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
	
}
void insertAtTail(Node* &tail, int d){              // insert at  tail 
	Node* temp=new  Node(d);
	tail->next=temp;
	tail=tail->next; 
}

void insertAtPosition(Node* &tail, Node* &Head, int position, int d){
	// for starting case  , inserting at first node
	if(position == 1){
		insertAtHead(Head,d);
		return;
	}
	Node* temp = Head;
	int cnt = 1;
	
	while(cnt<position-1){
		temp=temp->next;
		cnt++;
	}
	// inserting at last position
	if(temp->next== NULL){
		insertAtTail(tail,d);
		return;
	}
	// creating a node for d
	Node* nodeToInsert = new Node(d);
	
	nodeToInsert->next=temp->next;
	temp->next = nodeToInsert;
	
}

void deleteNode(int position,Node* &Head){          // delete a node
	//deleting first node
	if(position==1){
		Node* temp = Head;
		Head= Head->next;
		//memory free
		temp->next=NULL;
		delete temp;
	}
	// deleting in middle or any  other specific position
	else{
		Node* curr= Head;
		Node* prev= NULL;
		int cnt = 1;
		
		while(cnt<position){
			prev = curr;
			curr = curr->next;
			cnt++;
		}
		
		prev->next = curr->next;
		curr->next=NULL;
		delete curr;
		
	}
	
}


int main(){
	Node* node1 = new Node(10);
//	cout<< node1 -> data<<endl;
//	cout<<node1->next<<endl;
	
	//  head pointed to node1
	Node* Head= node1;
	Node* tail= node1;
	print(Head);
	insertAtTail(tail,12);
	insertAtTail(tail,15);      //  inserting at head and tail pos  in ll
	print(Head);
	insertAtPosition(tail,Head,4,22);
	print(Head);
	
	deleteNode(4,Head);
	print(Head);
	
	cout<<"tail is: "<<tail->data<<endl;
}




