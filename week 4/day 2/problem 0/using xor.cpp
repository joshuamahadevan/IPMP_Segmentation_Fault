#include<iostream>

using namespace std;

int missing_element( int* a, int n ){
	int xr=0;
	for( int i=1; i<n; i++){
		xr=xr^i;
		xr=xr^a[i-1];
	}
	xr=xr^n;
	
	return xr;
}

int main(){
	while(1){
		int n;
	    cout<<"Enter the value of n (array eles. go from 1 to n with 1 missing value) :";
	    cin>>n;
	
	    int a[n-1];
	    cout<<"Enter the "<<n-1<<" array elements: ";
	    for( int i=0; i<n-1; i++){
	        cin>>a[i];
	    }
	
	    cout<<"The missing element in the array is: "<<missing_element( a,n )<<endl<<endl;
	}
	
}
