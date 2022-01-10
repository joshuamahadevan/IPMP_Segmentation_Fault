#include "../../header/linkedList.h"
#include <stack>

bool check_palindrome( struct node* head ){
	struct node* temp=head;
	stack<int> s;
	
	while( temp ){
		s.push(temp->data);
		
		temp=temp->next;
	}//pusshing all elements onto stack
	
	temp=head;
	while( temp ){
		if( temp->data == s.top() ){
			s.pop();
			temp=temp->next;
		}else {
			return false;
		}
	}
	return true;
}

int main(){
	while( 1 ){
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
	
}
