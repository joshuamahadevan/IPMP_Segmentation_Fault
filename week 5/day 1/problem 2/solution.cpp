#include<iostream> 

using namespace std;

void merge( int *a, int l, int mid, int r, int& inv){
	int l_s[mid-l];
	int r_s[r-mid];
	for( int i=0; i<mid-l; i++){ l_s[i]=a[i+l]; }
	for( int i=0; i<r-mid; i++){ r_s[i]=a[i+mid]; }
	
	int l_i=0;
	int r_i=0;
	int a_i=l;
	
	while( l_i<mid-l && r_i<r-mid ){
		if( l_s[l_i] < r_s[r_i] ){
			a[a_i++]=l_s[l_i++];
		}else{
			a[a_i++]=r_s[r_i++];
			inv+=mid-l_i-l;
		}
	}
	while( l_i<mid-l ){ a[a_i++]=l_s[l_i++];}
	while( r_i<r-mid ){ a[a_i++]=r_s[r_i++];}
	
	
	for( int i=0; i<mid-l; i++) cout<<l_s[i]<<" ";
	cout<<" + ";
	for( int i=0; i<r-mid; i++) cout<<r_s[i]<<" ";
	cout<<" = ";
	for( int i=l; i<r; i++) cout<<a[i]<<" ";
	cout<<" : inv = "<<inv<<endl;
}

void merge_sort( int*a, int l, int r, int& inv){
	if( r-1==l ) return;
	int mid=(l+r)/2;
	merge_sort( a, l, mid, inv);
	merge_sort( a, mid, r, inv);
	merge( a, l, mid, r, inv);
}

int find_inversions( int*a, int l, int r){
	int c=0;
	merge_sort( a, l, r, c);

	return c;
}

int main(){
	while(1){
		int n;
		cout<<"Enter the number of elements in the list: ";
		cin>>n;
		
		int a[n];
		cout<<"Enter the elements of the array: ";
		for ( int i=0; i<n; i++){cin>>a[i];}
		
		int inv=find_inversions(a,0,n);
		
		cout<<"The number of inversions in the array is: "<<inv<<endl;
	}
}
