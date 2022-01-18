#include<iostream>

using namespace std;

void repeating_elements(int* a, int n){
	//we have 1,2,3,...n, 1,2 (say 1,2 are repeated). now, if we add another 1,2,3,...n to the current array(say), then the problem becomes to find 2 numbers with odd occurances which we have done earlier
	
	int xr=0;
	
	for(int i=0; i<n; i++){
		xr=xr^(i+1);
	}
	for(int i=0; i<n+2; i++){
		xr=xr^a[i];
	}
	
	//finding right most set bit of xr
	
	int m = xr & ~(xr-1);
	
	int v1=0, v2=0;
	
	for( int i=0; i<n; i++){
		if(m&(i+1)) v1=v1^(i+1);
		else v2=v2^(i+1);
	}
	for( int i=0; i<n+2; i++){
		if(m&(a[i])) v1=v1^a[i];
		else v2=v2^a[i];		
	}
	
	cout<<"The repeated elements are: "<<v1<<" "<<v2;
	
}

int main(){
    int n;
    cout<<"Enter the value of n (array eles. go from 1 to n with 2 repeated values) :";
    cin>>n;

    int a[n+2];
    cout<<"Enter the "<<n+2<<" array elements: ";
    for( int i=0; i<n+2; i++){
        cin>>a[i];
    }

    repeating_elements(a,n);
}
