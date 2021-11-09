#include "../../header/linkedList.h"

using namespace std;

int solve( struct node* head ){
	struct node* slow=head;
	struct node* fast=head;
	
	while( slow!=NULL && fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	
	return slow->data;
}

int main(){
	Linked_list list;
	
	cout<<"Enter the elements one by one (enter -1 to end the list) ..."<<endl;
	while(1){
		int temp;
		cin>>temp;
		if(temp==-1) break;
		
		list.append(temp);
	}
	
	cout<<"The elements of the linked list are: ";
	list.print();
	
	cout<<"The middle element of the linked list is: "<<solve( list.head() );
}
