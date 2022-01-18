#include<iostream>
#include<algorithm>

using namespace std;

void solve( int* a, int size, int val ){
	sort(a,a+size);
	
	for( int i=0; i<size-2; i++){
		//performing 2 pointer search for sum of 2 eles from the remaining array on the right
		int v=val-a[i];
		
		int p1=i+1; 
		int p2=size-1;
		
		while( p1<size-1 && p2>i+1 && p1<p2 ){
			if( a[p1]+a[p2] == v){
				cout<<"Triplet found. "<<a[i]<<" "<<a[p1]<<" "<<a[p2];
			}else if( a[p1]+a[p2] < v ){
				p1++;
			}else{
				//a[p1]+a[p2] > v
				p2--;
			}
		}
	
	}
	
	//time complexity: sorting takes o(n logn) 
	//and searching with 2 ptrs o(n), performed on n eles is o(n^2)	
	//so o(n^2) complexity
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
