#include<iostream>

using namespace std;

void swap( int&a, int&b){
	int c=a;
	a=b; 
	b=c;
}

int partition( int *a, int l, int r ){
	int i=l;
	int j=r;
	int p=l;
	
	while(i<j){
		do{ j--; }while( a[j]> a[p] );
		do{ i++; }while( a[i]<= a[p] );
		
		if(i<j){ swap(a[i], a[j]); }		
	}
	
	swap( a[j], a[p]);
	return j;
}

void quickSort( int *a, int l, int r){
	if( l<r ){
		int j=partition(a,l,r);
		quickSort( a, l, j);
		quickSort( a, j+1, r);
	}
}

int main(){
	int s;
	cout<<"Enter the size of the list: ";
	cin>>s;
	
	int a[s+1];
	a[s]=INT_MAX;
	
	cout<<"Enter the elements of the list: ";
	
	for(int i=0; i<s; i++){
		int t;
		cin>>t;
		a[i]=t;
	}
	
	quickSort( a, 0, s);
	
	cout<<"The sorted list is: ";
	for(int i=0; i<s; i++){
		cout<<a[i]<<" ";
	}
	
	return 0;
}
