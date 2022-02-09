#include<iostream> 

using namespace std;

void segregate_0s( int*a, int n){
	int *pos=a;
	
	for(int i=0; i<n; i++){
		if( a[i] == 0 ) continue;
		*pos=a[i];
		pos++;
	}
	
	while( pos < a+n ){
		*pos=0;
		pos++;
	}
}

int main(){
	while(1){
		int n;
		cout<<"Enter the number of elements in the list: ";
		cin>>n;
		
		int a[n];
		cout<<"Enter the elements of the array: ";
		for ( int i=0; i<n; i++){cin>>a[i];}
		
		segregate_0s(a,n);
		cout<<"The array after moving all 0's to the end: ";
		for( int i=0; i<n; i++){ cout<<a[i]<<" ";}
		cout<<endl;
	}
}
