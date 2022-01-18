#include<bits/stdc++.h>

using namespace std;

int main(){
	while( 1 ){
		int n;
		cout<<"\nEnter the size of the array: ";
		cin>>n;
		
		int arr[n];
		cout<<"Enter the elements of the array: ";
		for( int i=0; i<n; i++ ){
			cin>>arr[i];
		}

		int min=INT_MAX, a,b=INT_MAX; //a and b will be the first 2 terms of our sequence
		bool s=true;
		for( int i=0; i<n; i++ ){
			if( arr[i]<=min ) min=arr[i];
			else {
				if( arr[i]<=b ) {
					b=arr[i];
					a=min;
				}else{
					//bingo
					cout<< a <<" "<< b << " "<< arr[i] <<endl;
					s=false;
					break;
				}
			}
		}
		
		if(s) cout<<"No such triplet exists. \n";
 		
	}
}
