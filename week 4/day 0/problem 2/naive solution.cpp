#include<iostream>

using namespace std;

void solve( int* a, int size, int val ){
	for( int i=0; i<size-2; i++){
		for( int j=i+1; j<size-1; j++){
			for( int k=j+1; k<size; k++){
				if( a[i]+a[j]+a[k] == val ){
					cout<<"Triplet found. "<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
					return;
				}
			}
		}
	}
	cout<<"Triplet not found. "<<endl;
	
	//niave solution. takes c(n+3,3) which is nearly n^3 time. very bad
}

int main(){
	int s;
	cout<<"Enter the size of the array: ";
	cin>>s;
	
	int a[s];
	cout<<"Enter the elements of the array: ";
	for( int i=0; i<s; i++){
		cin>>a[i];
	}
	
	int v;
	cout<<"Enter the value of the triplet sum to be searched: ";
	cin>>v;
	
	solve( a,s,v );
	
}
