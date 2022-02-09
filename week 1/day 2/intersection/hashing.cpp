#include "../../header/linkedList.h"
#include <set>

struct node* create_node( int data ){
	struct node* newnode= ( struct node* ) malloc ( sizeof( struct node ));
	newnode->data=data;
	newnode->next=NULL;
			
	return newnode;
}

struct node* find_intersection( struct node* h1, struct node* h2 ){
	//can use unordered_set but my compiler doesn't support it ;-;
	set<node*> s;
	node* it=h1;
	
	while(it!=NULL){
		s.insert(it);
		it=it->next;
	}
	
	it=h2;
	while( it!= NULL ){
		if( s.find(it) != s.end() ) return it;
		it=it->next;
	}
	//no intersection
	return 0;
}

int main(){
	struct node *n1,*n2,*n3,*n4,*n5,*n6,*n7;
	
	n1=create_node(1);
	n2=create_node(2);
	n3=create_node(3);
	n4=create_node(4);
	n5=create_node(5);
	n6=create_node(6);
	n7=create_node(7);
	
	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	
	n7->next=n6;
	n6->next=n4;
	
	/* n1 -> n2 -> n3 -> n4 -> n5
						^
				 n7 -> n6
					   
		Here, n4 is the point of intersection
	*/
	
	struct node* res=find_intersection( n1, n7 );

	cout<<"The 2 linked lists intersect at "<<res->data<<endl;
	
}
