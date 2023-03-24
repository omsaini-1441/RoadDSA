#include<iostream>
using namespace std;
 
 class Node{
 	public:
 	int data;
 	Node* prev;
 	Node* next;
 	
 	// constructor
 	Node(int d){
 		this->data = d;
 		this->prev = NULL;
 		this->next = NULL;
	 }
	 
	 //destructor
	 ~Node(){
	 	int val = this->data;
	 	if(next!= NULL){
	 		delete next;
	 		next = NULL;
		 }
	 	cout<<"Memory free for Node with data"<< val<< endl;
	 }
 	
 };
  void print(Node* &head){                        // print the linked list
  	Node* temp = head;
  	
  	while(temp!= NULL){
  		cout<<temp->data<<" ";
  		temp=temp->next;
	  }
	  cout<< endl;
	  
  }
   int getLength(Node* head){                     // length of linked list
   		Node* temp = head;
  		int len = 0;
  	while(temp!= NULL){
  		len++;
  		temp=temp->next;
	  }
	  return len;
   }
   
   void insertAtHead(Node* &head,Node* &tail, int d){         // insert element at head, start
   	// if list is empty
   	if(head==NULL){
   		Node* temp = new Node(d);
   		head=temp;
   		tail= temp;
	   }
	 else{
	   
	Node* temp = new Node(d);
   	temp->next = head;
   	head->prev = temp;
   	head = temp;
        }
   }
   
   void insertAtTail(Node* &tail,Node* &head, int d){		 //  insert at tail, end
   	// list empty
   	if(tail==NULL){
   		Node* temp= new Node(d);
   		tail=temp;
   		head = temp;
	   }
	   else{
	   
	Node* temp = new Node(d);
   	tail->next =temp;
   	temp->prev = tail;
   	tail= temp;
   		}	
   }
   
   void insertAtPosition(Node* &tail,Node* &head,int position, int d){       //  insert at certain position
   	// insert at head
   	 if(position==1){
   	 	insertAtHead(head,tail,d);
   	 	return; 
	   }
		
		Node* temp = head;
		int cnt =1;
		
		while(cnt<position-1){
			temp=temp->next;
			cnt++;
		}
   		
   		//inserting at last position
   		if(temp->next==NULL){
   			insertAtTail(tail,head,d);
   			return;
		   }
   		
   		//creating a node
   		Node* nodeToInsert = new Node(d);
   		
   		nodeToInsert->next = temp->next;
   		temp->next->prev = nodeToInsert;
   		temp->next= nodeToInsert;
   		nodeToInsert->prev=temp;
   }
 	
 	void deleteNode(int position, Node* &head){ 					// deleting a node
 		//deleting first postion or start node
 		if(position==1){
 			Node* temp= head;
 			temp->next->prev = NULL;
 			head = temp->next;
 			temp->next = NULL;
 			delete temp;
		 }
		 else{
		 	// deleting any middle node or last node
		 	
		 	Node* curr = head;
		 	Node* prev = NULL;
		 	
		 	int cnt =1;
		 	while(cnt< position){
		 		prev = curr;
		 		curr = curr->next;
		 		cnt++;
			 }
		 	
		 	curr->prev = NULL;
		 	prev->next = curr->next;
		 	curr->next =NULL;
		 	delete curr; 
		 }
	 }
 	
 int main(){
 	
 	Node* head= NULL;
 	Node* tail= NULL;
	 print(head);
 	
 	
 	insertAtHead(head,tail, 11);
 	print(head);
 	insertAtHead(head,tail, 13);
 	print(head);
 	insertAtHead(head,tail, 8);
 	print(head);
 	//cout<< getLength(head)<< endl;
 	insertAtTail(tail,head,25);
 	print(head);
 	insertAtPosition(tail,head,2,100);
 	print(head);
 	insertAtPosition(tail,head,3,7);
 	print(head);
 	insertAtPosition(tail,head,7,104);
 	print(head);
 	insertAtPosition(tail,head,1,101);
 	print(head);
 }
