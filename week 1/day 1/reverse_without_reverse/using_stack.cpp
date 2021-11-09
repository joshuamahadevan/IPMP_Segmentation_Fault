#include "../../header/linkedList.h"
#include<stack>

int main(){
	Linked_list list;
	
	//getting input
	cout<<"Enter the elements one by one (enter -1 to end the list) ..."<<endl;
	while(1){
		int temp;
		cin>>temp;
		if(temp==-1) break;
		
		list.append(temp);
	}
	
	//code starts here
	struct node* temp=list.head();
	stack<int> s;
	
	cout<<"The elements of the list are: ";
	while( temp ){
		cout<<temp->data<<" ";
		s.push(temp->data);
		temp=temp->next;
	}
	cout<<endl<<"The elements of the list in reverse order are: ";
	while( !s.empty() ){
		cout<<s.top()<<" ";
		s.pop();
	}
	
}

//I just checked out gfg solution.. 
//this one is equivalent to the solution given in gfg as recursions are handled using stacks internally 
//this is what would happen internally if that recursive solution was called
//as stack operations can be done in o(1) time and there is no way to print all elements without going thru them atleast once, our solution which has o(n) is optimal
