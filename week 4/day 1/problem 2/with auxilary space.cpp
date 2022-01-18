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

		int small[n], big[n];
		int t=INT_MAX;	
		int t_i;
		
		//small[] has indices of elements lesser than arr[i] and to it's left
		for( int i=0; i<n; i++){
			if( arr[i]<=t ){
				t=arr[i];
				t_i=i;
				small[i]=-1;
			} else{
				small[i]=t_i;
			}
		}
		
		t=INT_MIN;
		
		//big[] has indices of elements greater than arr[i] and to it's right		
		for( int i=n-1; i>=0; i--){
			if( arr[i]>=t ){
				t=arr[i];
				t_i=i;
				big[i]=-1;
			} else{
				big[i]=t_i;
			}
		}
		
		bool x=true;
		
		for( int i=0; i<n; i++ ){
			if( small[i]!=-1 && big[i]!=-1 ){
				cout<<"Sorted subsequence in arr: "<< arr[small[i]]<<" "<<arr[i]<<" "<<arr[big[i]]<<endl;
				x=false;
				break;
			} 
 		}
 		if(x) cout<<"No sorted subsequence exists in arr. "<<endl;
 		
	}
}
