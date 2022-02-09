#include<bits/stdc++.h>

using namespace std;

int* make_product_array( int* a, int n ){
	int* res=(int*)malloc( n * sizeof( int ));
	
	res[0]=1;
	for( int i=1; i<n; i++){
		res[i]=res[i-1]*a[i-1];
	}
	//now res has all prefix sums.
	
	// 1 2 3 4 5  6   7
	// 1 1 2 6 24 120 720
	
	int t=1;
	for( int i=n-2; i>=0; i-- ){
		t*=a[i+1];
		res[i]*=t;
	}
	return res;
}

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

		int* res = make_product_array( arr, n );
		
		cout<<"The product array is: ";
		for( int i=0; i<n; i++){
			cout<<res[i]<<" ";
		}
		cout<<endl;
 		free(res);	
	}
}
