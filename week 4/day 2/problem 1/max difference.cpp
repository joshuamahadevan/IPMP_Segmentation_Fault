#include<iostream>

using namespace std;

int main(){
	while(1){
		int n;
		cout<<"Enter the number of elements in the list: ";
		cin>>n;
		
		int a[n];
		
		cout<<"Enter the elements of the array: ";
		for( int i=0; i<n; i++){
			cin>>a[i];
		}	
		
		//keep track of min element in the array
		//if a new max element is found, subtract it from the current min
		//keep track of variations in this difference, return the largest value
		
		int min=INT_MAX, res=INT_MIN ;
		for( int i=0; i<n; i++){
			if( a[i]<min ) min=a[i];
			else{
				int temp=a[i]-min;
				
				if(temp>res) res=temp;
			}
		}
		
		cout<<res<<endl<<endl;
		
	}
}
