#include<iostream> 

using namespace std;

int max_bitonic( int*a, int n){
	int inc[n], dec[n];
	inc[0]=1;dec[n-1]=1;
	for( int i=1; i<n; i++){
		if( a[i] >= a[i-1] ) inc[i]=inc[i-1]+1;
		else inc[i]=1;
	}
	for( int i=n-2; i>=0; i--){
		if( a[i] >= a[i+1] ) dec[i]=dec[i+1]+1;
		else dec[i]=1;
	}
	
	int res=0;
	for( int i=0; i<n; i++){
		if( inc[i]+dec[i] > res ) res=inc[i]+dec[i];
	}
	
	return res-1;
}

int main(){
	while(1){
		int n;
		cout<<"Enter the number of elements in the list: ";
		cin>>n;
		
		int a[n];
		cout<<"Enter the elements of the array: ";
		for ( int i=0; i<n; i++){cin>>a[i];}
		
		int res = max_bitonic( a,n );
		cout<<"The maximum length bitonic sub-array is: "<<res<<endl;
	}
}
