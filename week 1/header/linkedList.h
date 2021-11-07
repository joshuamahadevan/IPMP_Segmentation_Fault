#pragma once //guard to prevent including the same header more than once. we may get duplicate errors if header is included more than once

#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

struct node{
	int data;
	struct node* next;
}; //node of a linked list

class Linked_list{
	private: 
		struct node* root;
		struct node* create_node( int data ){
			struct node* newnode= ( struct node* ) malloc ( sizeof( struct node ));
			newnode->data=data;
			newnode->next=NULL;
			
			return newnode;
		}
		void error( string error){
			cout<<endl
				<<"------------------------------------------"<<endl
				<<"Exception: "<<error<<endl
				<<"------------------------------------------"<<endl
				<<endl;
			return;
		}
	public: 
		Linked_list(){
			root=NULL;
		}//constructor
		
		~Linked_list(){
			struct node* current=this->root;
			struct node* next;	
			
			while( current ){
				next=current->next;
				free(current);
				current=next;
			}
		}//destructor
		
		void append( int data ){
			if(root==NULL){
				struct node* newnode=create_node( data );
				this->root=newnode;
				return;
			}
			struct node* temp=this->root;
			while( temp->next ){
				temp=temp->next;
			}
			struct node* newnode=create_node(data);
			newnode->next=temp->next;
			temp->next=newnode;
			return;	
		}//adds the given value to the end of the linked list
		
		bool insert_at(int pos, int data){
			if( pos<0 ){
				error( "Position cannot be negative" );
				return false;//operation failed
			}
			if(pos==0){
				//insert element at begining of linked list
				struct node* newnode=create_node( data );
				newnode->next=root;
				root=newnode;
				return true;//operation successful
			}
			struct node* temp=this->root;
			while( --pos ){
				if( temp == NULL ){
					//linked list is shorter than the given index value
					error("Position does not exist ");
					return false;
				}
				temp=temp->next;
			}
			//now temp has address of node after which the new node should be inserted
			struct node* newnode=create_node(data);
			newnode->next=temp->next;
			temp->next=newnode;
			return true;
		}//inserts given value at a given position
		
		bool delete_val( int data ){
			if(this->root==NULL){
				error("Cannot delete element as linked list is empty");
				return false;
			}
			if(root->data==data){
				struct node* del= this->root;
				this->root=this->root->next;
				free(del);
				return true;
			}
			struct node* temp=this->root;
			struct node* del;
			while(temp->next){
				if(temp->next->data==data){
					//shoulld delete the node after temp
					struct node* del=temp->next;
					temp->next=temp->next->next;
					free(del);
					return true;
				}
				temp=temp->next;
			}
			//element not found
			error("Element to be deleted does not exist in the linked list");
			return false;
		}//deletes the given value from the linked list
		
		bool delete_at(int pos){
			//pos=0 stands for the begining of the sll
			//pos=n-1 stands for the end of the sll
			if(pos < 0){
				error("Cannot delete at -ve index ");
				return false;
			}
			if(this->root == NULL){
				error("Cannot delete element at linked list is empty");
				return false;
			}
			if(pos==0){
				struct node* del=this->root;
				this->root=this->root->next;
				free(del);
				return true;
			}
			struct node* temp=this->root;
			while(--pos){
				temp=temp->next;
				if(temp->next==NULL){
					//element to be deleted does not exist
					error("Element to be delted does not exist ");
					return false;
				}
			}//now temp will be having a pointer to the node right before the node to be deleted
			struct node* del=temp->next;
			temp->next=temp->next->next;
			free(del);
			return true;
		}//deletes the node at that particular index from the linked list
		
		void print(){
			struct node* temp=this->root;
			cout<<endl;
			while( temp ){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
			return;
		}//prints the content of the linked list 
		
		int size(){
			struct node* temp=this->root;
			int l=0;
			while( temp ){
				l++;
				temp=temp->next;
			}
			return l;
		}//returns size of the linked list
		
		bool search ( int data ){
			struct node* temp = this->root;
			while( temp ){
				if( temp->data == data ){
					return true;
				}
				temp=temp->next;
			}
			return false;
		} //searches for the given value in the linked list
		
		int find_index(int data){
			int ind=-1;
			struct node* temp = this->root;
			while( temp ){
				ind++;
				if( temp->data == data ){
					return ind;
				}
				temp=temp->next;
			}
			return ind;
		}
		
		struct node* head(){
			return this->root;
		}//returns root of the linked list
};

