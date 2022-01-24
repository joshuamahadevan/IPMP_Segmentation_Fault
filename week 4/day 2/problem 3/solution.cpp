#include<bits/stdc++.h>

using namespace std;


int main(){
	while( 1 ){
		int n;
		cout<<"Enter the value of n (size of the array): ";
		cin>>n;	
		
		int a[n];
		cout<<"Enter the elements of the array ( elements should be in range 0 to n-1 ): ";
		for( int i=0; i<n; i++){
			cin>>a[i];
		}
 		
 		//we are going to use the approach where we add n to each element and check for a[i]>n later.
 		
 		for( int i=0; i<n; i++){
 			a[a[i]%n] += n;
		}
		
		cout<<"The repeating elements are: ";
		for( int i=0; i<n; i++){
			if( a[i] > 2*n ) cout<<i<<" ";
		} 
		cout<<endl<<endl;
 		
	}
}
