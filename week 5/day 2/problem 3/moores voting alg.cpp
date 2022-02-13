#include<iostream>
#include<map>

using namespace std;

int get_candidate(int*a, int n){
	int ind=0, c=0;
	for( int i=0; i<n; i++){
		if(a[ind]==a[i])c++;
		else c--;	
		if(c==0) { ind=i; c=1; }
	}
	return a[ind];
}

bool is_majority(int*a, int n, int v){
	int c=0;
	for( int i=0; i<n; i++){
		if(a[i]==v) c++;
		if( c>n/2 ) return true;
	}
	return false;
}

int majority( int *a, int n){
	int res=get_candidate(a,n);
	if(is_majority(a,n,res)) return res;
	else return INT_MIN;
}

int main(){
	while(1){
		int n;
		cout<<"Enter the number of elements of the array: ";
		cin>>n;

		int a[n];
		cout<<"Enter the elements of the array: ";
		for( int i=0; i<n; i++) cin>>a[i];

		int res=majority(a,n);
		if( res==INT_MIN ) cout<<"There is no majority element. \n";
		else cout<<"The majority element in the array is: "<<res<<endl;
	}
}
