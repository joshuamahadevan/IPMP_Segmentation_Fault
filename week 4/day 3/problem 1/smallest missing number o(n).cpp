#include<iostream>
#include<cmath>

using namespace std;

void swap( int&a, int&b ){
	int t=a;
	a=b;
	b=t;
}

void print( int* a, int n){
	for( int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int smallest_missing( int* a, int n){
	int m=n-1;

	for( int i=0; i<n; i++ ){
		if(i>m) break;
		if( a[i]<=0 ){
			swap( a[i], a[m] );
			m--;
			i--;
		} 
	}
	m++;
	print(a,n);	
	print(a,m);
	//now all neg nos will be pushed to the right. so 0->m has all positive numbers now
	//there are m +ve nos in a which are from 0->m-1
	for( int i=0; i<m; i++){
		cout<<a[i]<<" ";
		if(abs(a[i]) <= m ){
			if( a[abs(a[i])-1] > 0 ) a[abs(a[i])-1] *=-1;
		}
		
	}
	cout<<endl;
	print(a,m);
	
	int res=1;
	for( int i=0; i<m ; i++ ){
		if( a[i]>0 )break;
		res++;
	}
	
	return res;
}

int main(){
	while(1){
		int n;
		cout<<"Enter the number of elements in the list: ";
		cin>>n;
		
		int a[n];
		
		cout<<"Enter the elements of the array: ";
		for( int i=0; i<n; i++){
			cin>>a[i];
		}	
		
		//keep track of min element in the array
		//if a new max element is found, subtract it from the current min
		//keep track of variations in this difference, return the largest value
		
		cout<<"The smallest positive number missing from the array is: "<<smallest_missing(a,n)<<endl<<endl;
	}
}
