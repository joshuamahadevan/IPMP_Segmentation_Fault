#include "../../header/linkedList.h"

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
	cout<<"The elements of the list are: ";
	list.print();
	cout<<"The elements of the list in reverse order are: ";
	for( int i=list.size(); i>0; i--){
		cout<<list.get_val(i-1)<<" ";
	}
	
	
}
