#include<iostream>

using namespace std;

int largest_sum_sub( int*a, int n){
	int res=0, max=0 ;
	
	for( int i=0; i<n; i++){
		if( a[i] > max+a[i] ) max=a[i];
		else max+=a[i];

		if( max > res ) res=max;
	}
	return res;
}

int main(){
	while( 1 ){
		int n;
		cout<<"Enter the size of the array: ";
		cin>>n;
		int a[n];
		cout<<"Enter the elements of the array: ";
		for( int i=0; i<n; i++){ cin>>a[i]; }
		
		int res=largest_sum_sub( a, n );
		cout<<"The maxiumum contiguous array sum is: "<<res<<"\n";
	}
}
