#include<iostream>

using namespace std;

void swap( int&a, int&b){
	int t=a;
	a=b;
	b=t;
}

void segregate_0s( int* arr, int n ){
		/*
		//methord 1
		int cnt_0=0; //stores the count of 0's in the array
		for( int i=0; i<n; i++ ){
			if( arr[i]==0 ) cnt_0++;
		}
		
		cout<<"The sorted array is: ";
		int i=0;
		for( i=0; i<cnt_0; i++){
			arr[i]=0;
		}
		for( ; i<n ; i++ ){
			arr[i]=1;
		} 
		*/
		/*
		//methord 2
		int ind_0=-1; //current index upto which array is sure to have all 0's
		
		int no_steps=0;
		for( int i=0; i<n; i++){
			no_steps++;
			if(i<=ind_0) continue;
			if(arr[i]==0) {
				swap( arr[i], arr[++ind_0] );
				i--;
			} 
		}
		cout<<"no_steps="<<no_steps<<"\n";
		*/
		
		//methord 3
		int l=0, r=n-1;

		while( l<r ){
			no_steps++;
			while(arr[l]==0){
				l++;
			}while(arr[r]==1){
				r--;
			}
			
			if( l<r ) swap( arr[l],arr[r] );
		}
	
}

int main(){
	while(1){
		int n;
		cout<<"Enter the number of elements in the array: ";
		cin>>n;
		
		int arr[n];
		cout<<"Enter the "<<n<<" values in the array: ";
		for( int i=0; i<n; i++ ){
			cin>>arr[i];
		}
		
		segregate_0s( arr, n );
	
		cout<<"The segregated array is: ";
		for( int i=0; i<n; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
}
