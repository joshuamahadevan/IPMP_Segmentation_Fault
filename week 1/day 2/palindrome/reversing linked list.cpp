#include "../../header/linkedList.h"

struct node* find_middle( struct node* head ){
	//find middle of ll using 2 ptr
	struct node* slow=head;
	struct node* fast=head;
	
	while( fast->next!= NULL && fast->next->next!=NULL ){
		slow=slow->next;
		fast=fast->next->next;
	}
	
	return slow;
}

struct node* reverse_from( struct node* head ){
	//return a linked list with elements of head in reversed order
	node *prev, *curr, *next;
	prev=head;
	curr =head->next;
	prev->next=NULL; //to indicate end of our new list
	while( curr!=NULL ){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}

bool check_palindrome( struct node* head ){
	struct node* middle = find_middle ( head );
	node* rev_mid=reverse_from(middle->next);
	middle->next=NULL;	
	
	//now head ->middle and rev_mid->end are 2 linked lists. If corresponding elements are equal, the linked list is a palindrome
	
	struct node *it1=head,
				*it2=rev_mid;
	while( it1!=NULL && it2!=NULL ){
		if( it1->data != it2->data ) return false;
		it1=it1->next;
		it2=it2->next;
	}
	return true;
}

int main(){
	Linked_list list;
	cout<<"Enter the elements of the linked list seperated by spaces (Enter -1 after entering all elements to start the process)... ";
	while(1){
		int temp;
		cin>>temp;
		if(temp==-1) break;
		list.append(temp);
	}
		
	cout<< ((check_palindrome(list.head())) ? "The given linked list is a palindrome" : "The given linked list is not a palindrome" );
	cout<<endl<<endl<<"----------------------------------------------------------------"<<endl<<endl;
}
