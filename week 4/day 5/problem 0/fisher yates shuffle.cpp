#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

void swap( int &a, int &b ){
	int c=a;
	a=b;
	b=c;
}

void randomise( int* a, int n ){
	srand(time(NULL)); //to generate new random sequences each time
	
	for( int i=n-1; i>0; i-- ){
		int j = rand() % (i+1);
		swap( a[j],a[i] );
	}
}

int main(){
	while(1){
		int n;
	    cout<<"Enter the size of the array: ";
	    cin>>n;
	    
		int arr[n];
		cout<<"Enter the elements of the array: ";
		for( int i=0; i<n; i++){
			cin>>arr[i];
		}
		
		randomise( arr, n );
		
		cout<<"Randomised array is: ";
		for( int i=0; i<n; i++){
			cout<<arr[i]<<" ";
		}
		
		cout<<"\n\n";

	}
	
}
