#include<iostream>
#include<vector>

using namespace std;

void merge( int* a, int l, int mid, int r){
	vector<int> l1,l2;
	
	for( int i=l; i<=mid; i++){
		l1.push_back(a[i]);
	}
	for( int i=mid+1; i<=r; i++){
		l2.push_back(a[i]);
	}

	int i=0,j=0;
	int k=l;
	
	while( i<l1.size() && j<l2.size() ){
		if( l1[i] < l2[j] ) a[k++]=l1[i++];
		else a[k++]=l2[j++];
	}
	while( i<l1.size()){
		a[k++]=l1[i++];
	}
	while( j<l2.size()){
		a[k++]=l2[j++];
	}	
}

//int g=0;
void print( int*a, int s){
	for( int i=0; i<s; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void merge_sort( int* a, int l, int r){
	int mid=-1;
	if(l<r){
		mid=(l+r)/2;
		merge_sort( a, l, mid);
		merge_sort( a, mid+1, r);
		merge( a, l, mid, r );
	}
	//cout<<l<<" "<<mid<<" "<<r<<" - ";
	//print(a,g);
}


int main(){
	int s;
	cout<<"Enter the  number of elements in the list: ";
	cin>>s;
	//g=s;
	
	int a[s];
	cout<<"Enter the elements of the array: ";
	for( int i=0; i<s; i++){
		cin>>a[i];
	}
	cout<<"The array before sorting is: ";
	print(a,s);
	
	merge_sort(a,0,s-1);


	cout<<"The sorted array is: ";
	print(a,s);
}
