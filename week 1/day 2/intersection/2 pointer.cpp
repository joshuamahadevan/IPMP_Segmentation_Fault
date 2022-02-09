#include "../../header/linkedList.h"

struct node* create_node( int data ){
	struct node* newnode= ( struct node* ) malloc ( sizeof( struct node ));
	newnode->data=data;
	newnode->next=NULL;		
	return newnode;
}

struct node* find_intersection( struct node* h1, struct node* h2 ){
	node *it1=h1, *it2=h2;
	
	bool c1=false,c2=false;
	
	while( !(c1&&c2) ){
		if( it1==NULL ){
			c1=true;
			it1=h2;
		}else{
			it1=it1->next;
		}
		
		if( it2==NULL ){
			c2=true;
			it2=h1;
		}else{
			it2=it2->next;
		}
	}
	
	//now it1 and it2 are equidistant from intersection point
	
	while( it1!=NULL && it2!=NULL ){
		if( it1==it2 ) return it1;
		it1=it1->next;
		it2=it2->next;
	}
	
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
