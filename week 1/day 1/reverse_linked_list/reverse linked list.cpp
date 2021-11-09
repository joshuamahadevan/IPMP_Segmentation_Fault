#include <iostream>
#include <cstdlib>

using namespace std;

struct node{
	int data; 
	struct node* next;
};

//I am not using the class defined earlier as i want to work closer to the linked list than the abstraction provided by the class.

//helper function to create nodes
struct node* new_node( int data ){
	struct node* temp= (struct node*) malloc( sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
}

//helper function to print linked list
void print( struct node* head){
	struct node* temp=head;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

//function to reverse the linked list
struct node* reverse(struct node* head){
	if(head==NULL || head->next==NULL ){
		return head;
	}
	
	struct node* current=head;
	struct node* prev=NULL;
	struct node* next=head->next;
	
	while( next!= NULL ){
		//moving one step forward in the ll keeping track of all 3 variables
		prev=current;
		current=next;
		next=current->next;
		
		//reversing the link
		current->next=prev;
	}
	head->next=NULL;
	
	return current;
}

int main(){
	struct node* list1=NULL;
	
	//getting input for the linked list
	cout<<"Enter the elements of the linked list one by one (Enter -1 to end the list): ";
	struct node* temp=NULL;
	while(1){
		int c;
		cin>>c;
		if(c==-1) break;
		if(list1==NULL) {
			//first node
			list1=new_node(c);
			temp=list1;
		}else{
			temp->next=new_node(c);
			temp=temp->next;
		}	
	}
	
	//printing the linked list and the reversed linked list
	cout<<"The elements of the linked list are: ";
	print(list1);
	cout<<endl
		<<"The reversed linked list is: ";
	print(reverse(list1));
	
}
