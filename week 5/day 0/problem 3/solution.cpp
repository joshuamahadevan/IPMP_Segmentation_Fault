#include<iostream>

using namespace std;

int largest_sum_sub( int*a, int n){
	int min=INT_MAX;
	int res=INT_MIN;
	int sum=0;
	for( int i=0; i<n; i++){
		sum+=a[i];
		if( sum < min ) min = sum;
		else if ( sum-min > res ) res = sum-min;
	}
	if( res==INT_MIN ) return a[0];
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
