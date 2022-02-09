#include<iostream> 

using namespace std;

void rotate( int*a, int n, int d){
	int temp[d];
	for( int i=0; i<d; i++) temp[i]=a[i];
	for( int i=d; i<n; i++) a[i-d]=a[i];
	for( int i=n-d; i<n; i++) a[i]=temp[i-n+d];
}

int main(){
	while(1){
		int n;
		cout<<"Enter the number of elements in the list: ";
		cin>>n;
		
		int a[n];
		cout<<"Enter the elements of the array: ";
		for ( int i=0; i<n; i++){cin>>a[i];}
		
		int d;
		cout<<"Enter the number of rotations to perform: ";
		cin>>d;
		
		rotate(a,n,d);
		cout<<"The array after performing the reqd rotations is: ";
		for (int i=0; i<n; i++) cout<<a[i]<<" ";
		cout<<endl;
	}
}
