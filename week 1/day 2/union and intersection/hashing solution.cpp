#include "../../header/linkedList.h"
#include<set>

Linked_list union_ll( Linked_list l1, Linked_list l2 ){
	node* res=NULL, *end=NULL;
	set<int> s;
	
	node* it=l1.head();
	while( it!=NULL ){
		if(s.find(it->data)==s.end()){
			s.insert(it->data);
			//adding node to ll	
			if(end==NULL){
				res=create_node(it->data);
				end=res;
			}
			end->next=create_node(it->data);
			end=end->next;
			//added node to ll
		}
		it=it->next;
	}
	it=l2.head();
	while(it!=NULL){
		if(s.find(it->data)==s.end()){
			//adding node to ll
			end->next=create_node(it->data);
			end=end->next;
			//added node to ll
		}
		it=it->next;
	}
	return Linked_list(res);
}

Linked_list intersection_ll( Linked_list l1, Linked_list l2 ){
	node* h1=l1.head();
	node* h2=l2.head();
	node* res=NULL, *end=NULL;
	set<int> s;
	
	node* it=l1.head();
	while( it!=NULL ){
		s.insert(it->data);
		it=it->next;
	}
	it=l2.head();
	while( it!=NULL ){
		if( s.find(it->data) != s.end() ){
			//adding node to ll	
			if(end==NULL){
				res=create_node(it->data);
				end=res;
			}
			end->next=create_node(it->data);
			end=end->next;
			//added node to ll
		}
		it=it->next;
	}
	
	return Linked_list(res);
}

int main(){
	Linked_list list1, list2, un, in;
	cout<<"Enter the elements of list 1 (-1 to end sequence) :"; list1.initialise();
	cout<<"Enter the elements of list 2 (-1 to end sequence) : "; list2.initialise();
	
	un=union_ll(list1,list2);
	in=intersection_ll(list1,list2);
	
	cout<<"The union of the 2 lists is: "; un.print();
	cout<<"The intersection of the 2 lists is: "; in.print();
}
